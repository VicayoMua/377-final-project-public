#include "diskmallo.h"

DiskVirtualMemoryManager::DiskVirtualMemoryManager(const char *folder_path) {
    if (folder_path == NULL || folder_path == nullptr) // some architectures consider NULL to be different from nullptr
        throw std::runtime_error("DiskVirtualMemoryManager.constructor: folder_path is NULL!");
    DIR *folder = ::opendir(folder_path);
    if (!folder && (::mkdir(folder_path, 0600) != 0 || !(folder = ::opendir(folder_path)))) {
        throw std::runtime_error(
                "DiskVirtualMemoryManager.constructor: folder_path is totally invalid (does not exist and cannot even be created)!"
        );
    }
    if (closedir(folder) == -1 || !(folder = ::opendir(folder_path))) {
        throw std::runtime_error(
                "DiskVirtualMemoryManager.constructor: folder_path is created but cannot be reopened!"
        );
    }
    this->folder_path_global_length = ::strlen(folder_path);
    this->folder_path_global = ::strdup(folder_path);
    this->folder_global = folder;
    this->free_mem_file_id_stack = new SimpleStack<unsigned long>;
    ::sem_init(&this->free_mem_file_id_stack_sem, 0, 1);
    this->free_mem_file_id_max_counter = 0;
    ::sem_init(&this->free_mem_file_id_max_counter_sem, 0, 1);
    this->ptr_to_fd_id_size_map = new std::map<unsigned long, struct map_info_fd_id_size_fpath>;
    ::sem_init(&this->ptr_to_fd_id_size_map_sem, 0, 1);
}

void *DiskVirtualMemoryManager::deconstructor_helper(void *_param) {
    auto *param = (struct deconstructor_helper_stru *) _param;
    ::msync(param->ptr, param->size, MS_SYNC);
    ::munmap(param->ptr, param->size);
    ::close(param->fd);
    ::remove(param->fpath);
    ::free(param->fpath);
    ::free(param);
    pthread_exit(NULL);
}

DiskVirtualMemoryManager::~DiskVirtualMemoryManager() {
    ::free(this->folder_path_global);
    ::sem_wait(&this->free_mem_file_id_stack_sem);
    delete this->free_mem_file_id_stack;
    ::sem_post(&this->free_mem_file_id_stack_sem);
    ::sem_destroy(&this->free_mem_file_id_stack_sem);
    ::sem_destroy(&this->free_mem_file_id_max_counter_sem);
    ::sem_wait(&this->ptr_to_fd_id_size_map_sem);
    size_t size = this->ptr_to_fd_id_size_map->size();
    if (size > 0) {
        auto *tids = (pthread_t *) ::calloc(size, sizeof(pthread_t));
        int index = 0;
        for (auto t = this->ptr_to_fd_id_size_map->begin(); t != this->ptr_to_fd_id_size_map->end(); t++) {
            // this struct is deconstructed at the end of each thread!!!
            auto *stru = (struct deconstructor_helper_stru *) ::calloc(1, sizeof(struct deconstructor_helper_stru));
            stru->ptr = (void *) t->first;
            stru->fd = t->second.fd;
            stru->size = t->second.size;
            stru->fpath = t->second.fpath;
            ::pthread_create(tids + index, NULL, this->deconstructor_helper, (void *) stru);
            index++;
        }
        for (index = 0; index < size; index++) {
            ::pthread_join(tids[index], NULL);
        }
        ::free(tids);
    }
    delete this->ptr_to_fd_id_size_map;
    ::sem_post(&this->ptr_to_fd_id_size_map_sem);
    ::sem_destroy(&this->ptr_to_fd_id_size_map_sem);
    ::closedir(this->folder_global);
}

size_t DiskVirtualMemoryManager::checkDiskFolderCapacity() {
    struct statvfs stat{};
    if (::statvfs(this->folder_path_global, &stat) == 0) {
        return stat.f_frsize * stat.f_bavail; // Calculate available space in bytes
    } else {
        throw std::runtime_error(
                "DiskVirtualMemoryManager.checkDiskFolderCapacity: Cannot determine the total available folder space!");
    }
}

DiskMemory DiskVirtualMemoryManager::malloc(size_t size) {
    if (size <= 0 || this->checkDiskFolderCapacity() < size)
        return {nullptr, 0};
    // get mem_file_id
    unsigned long mem_file_id;
    ::sem_wait(&this->free_mem_file_id_stack_sem);
    if (!this->free_mem_file_id_stack->isEmpty()) {
        mem_file_id = this->free_mem_file_id_stack->pop();
        ::sem_post(&this->free_mem_file_id_stack_sem);
    } else {
        ::sem_post(&this->free_mem_file_id_stack_sem);
        ::sem_wait(&this->free_mem_file_id_max_counter_sem);
        mem_file_id = free_mem_file_id_max_counter++;
        ::sem_post(&this->free_mem_file_id_max_counter_sem);
    }
    // make mem_file_path: folder_path + "/" + "mem_" + mem_file_id
    size_t mem_file_path_length = folder_path_global_length + 5 + (size_t) log10((double) (mem_file_id + 1)) + 3;
    char *mem_file_path = (char *) ::calloc(mem_file_path_length, sizeof(char));
    ::snprintf(mem_file_path, mem_file_path_length,
               "%s/mem_%llu", this->folder_path_global, (unsigned long long) mem_file_id);
    // create the file
//    int fd = ::open(mem_file_path, O_RDWR | O_CREAT | O_TRUNC, 0600);
    int fd = ::open(mem_file_path, O_RDWR | O_CREAT | O_TRUNC);
    if (fd == -1) {
        ::free(mem_file_path);
        return {nullptr, 0};
    }
//    ::free(mem_file_path); this line can be deleted: this free is moved to freer.
    // test whether the created file can take enough space
    if (::lseek(fd, (off_t) size - 1, SEEK_SET) == -1 || ::write(fd, "", 1) != 1) {
        ::close(fd);
        return {nullptr, 0};
    }
    // create the mapping
    void *ptr = ::mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        ::close(fd);
        return {nullptr, 0};
    }
    if (::msync(ptr, size, MS_SYNC) == -1) {
        ::munmap(ptr, size); // no matter this succeeds or fails for reason...
        ::close(fd);
        return {nullptr, 0};
    }
    ::sem_wait(&this->ptr_to_fd_id_size_map_sem);
    this->ptr_to_fd_id_size_map->operator[]((unsigned long) ptr) = {fd, mem_file_id, size, mem_file_path};
    ::sem_post(&this->ptr_to_fd_id_size_map_sem);
    return {ptr, size};
}

DiskMemory DiskVirtualMemoryManager::calloc(size_t count, size_t size_of_each) {
//    We don't check if count and size_of_each is valid here
//    Because calloc() calls malloc() and data is of size_t, an unsigned type!
//    if (count <= 0 || size_of_each <= 0) return {nullptr, 0};
    DiskMemory dm = this->malloc(count * size_of_each);
    if (dm.size() != 0)
        ::memset(dm.pointer(), 0, dm.size());
    return dm;
}

unsigned char DiskVirtualMemoryManager::free(DiskMemory &&dmem, bool if_delete_memory_file) {
    void *ptr = dmem.pointer();
    // find info & delete it
    ::sem_wait(&this->ptr_to_fd_id_size_map_sem);
    auto t = this->ptr_to_fd_id_size_map->find((unsigned long) ptr);
    if (t == this->ptr_to_fd_id_size_map->end()) {
        ::sem_post(&this->ptr_to_fd_id_size_map_sem);
        return 0;
    }
    struct map_info_fd_id_size_fpath info = t->second;
    this->ptr_to_fd_id_size_map->erase(t);
    ::sem_post(&this->ptr_to_fd_id_size_map_sem);
    // close mmap
    if (::msync(ptr, info.size, MS_SYNC) == -1 || ::munmap(ptr, info.size) == -1) {
        return 2;
    }
    // close file descriptor
    ::close(info.fd);
    if (if_delete_memory_file) {
        ::remove(info.fpath); // ignore if remove() succeeded or not
    }
    ::free(info.fpath);
    // record free id
    ::sem_wait(&this->free_mem_file_id_stack_sem);
    this->free_mem_file_id_stack->push(info.id);
    ::sem_post(&this->free_mem_file_id_stack_sem);
    return 1;
}

unsigned char DiskVirtualMemoryManager::free(DiskMemory &dmem, bool if_delete_memory_file) {
    void *ptr = dmem.pointer();
    // find info & delete it
    ::sem_wait(&this->ptr_to_fd_id_size_map_sem);
    auto t = this->ptr_to_fd_id_size_map->find((unsigned long) ptr);
    if (t == this->ptr_to_fd_id_size_map->end()) {
        ::sem_post(&this->ptr_to_fd_id_size_map_sem);
        return 0;
    }
    struct map_info_fd_id_size_fpath info = t->second;
    this->ptr_to_fd_id_size_map->erase(t);
    ::sem_post(&this->ptr_to_fd_id_size_map_sem);
    // close mmap
    if (::msync(ptr, info.size, MS_SYNC) == -1 || ::munmap(ptr, info.size) == -1) {
        return 2;
    }
    // close file descriptor
    ::close(info.fd);
    if (if_delete_memory_file) {
        ::remove(info.fpath); // ignore if remove() succeeded or not
    }
    ::free(info.fpath);
    // record free id
    ::sem_wait(&this->free_mem_file_id_stack_sem);
    this->free_mem_file_id_stack->push(info.id);
    ::sem_post(&this->free_mem_file_id_stack_sem);
    return 1;
}