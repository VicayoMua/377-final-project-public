//
// Created by vicay on 11/14/2023.
//

#ifndef VIRTUALMEMORYMANAGER_DVMEM_H
#define VIRTUALMEMORYMANAGER_DVMEM_H

// Unix C Headers
#include "cstring"
#include "cmath"
#include <fcntl.h>
#include "unistd.h"
#include "dirent.h"
#include "pthread.h"
#include "semaphore.h"
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/mman.h>

// CPP Headers
#include "string"
#include "map"
#include "stdexcept"
#include "iostream"

// My CPP Headers
#include "simplestack"
#include "diskmno.h"

/*
 * DiskVirtualMemoryManager is thread safe with sufficient mutual exclusion protections.
 * Thus, every method can be considered done atomically! NICE CODE!!!
 * */
class DiskVirtualMemoryManager {
private:
    /*
     * folder_path_global is thread safe because of being constant.
     * maintained by:
     *      constructor, deconstructor
     * */
    char *folder_path_global;
    size_t folder_path_global_length;

    /*
     * folder_global is thread safe because of being constant.
     * maintained by:
     *      constructor, deconstructor
     * */
    DIR *folder_global;

    /*
     * free_mem_file_id_stack is thread dangerous and should be protected by a binary semaphore.
     * maintained by:
     *      constructor, deconstructor,
     *      malloc, calloc,
     *      free
     * */
    SimpleStack<unsigned long> *free_mem_file_id_stack;
    sem_t free_mem_file_id_stack_sem;

    /*
     * free_mem_file_id_max_counter is thread dangerous and should be protected by a binary semaphore.
     * maintained by:
     *      constructor, deconstructor,
     *      malloc, calloc,
     *      free
     * */
    unsigned long free_mem_file_id_max_counter;
    sem_t free_mem_file_id_max_counter_sem;

    /*
     * struct map_info_fd_id_size_fpath is used for performance, used in prt_to_fd_id_size_map below.
     * It's absolutely more efficient if we combine those info as a struct when doing the mapping!
     * */
    struct map_info_fd_id_size_fpath {
        int fd;
        unsigned long id;
        size_t size;
        char *fpath;
    };

    /*
     * ptr_to_fd_id_size_map is thread dangerous and should be protected by a binary semaphore.
     * maintained by:
     *      constructor, deconstructor,
     *      malloc, calloc,
     *      free
     * */
    std::map<unsigned long, struct map_info_fd_id_size_fpath> *ptr_to_fd_id_size_map;
    sem_t ptr_to_fd_id_size_map_sem;
public:
    /*
     * constructor
     * */
    explicit DiskVirtualMemoryManager(const char *folder_path);

    /*
     * deconstructor
     * */
    ~DiskVirtualMemoryManager();

private:
    struct deconstructor_helper_stru {
        void *ptr;
        int fd;
        size_t size;
        char *fpath;
    };

    static void *deconstructor_helper(void *param);

public:
    /*
     * checkDiskFolderCapacity() returns the total available folder space
     * */
    size_t checkDiskFolderCapacity();

    /*
     * malloc(size) returns the size of allocated virtual memory on success.
     *              returns {nullptr, 0} on failure.
     * Please be careful that only unix-like path is supported!
     *      On Windows environment, the path separator is '\\' instead of '/'
     * */
    DiskMemory malloc(size_t size);

    /*
     * calloc(count, size_of_each) not only calls malloc(count*size_of_each) but also set all binaries to 0.
     * */
    DiskMemory calloc(size_t count, size_t size_of_each);

    /*
     * free(dmem) returns:
     *      0 -> fail, invalid ptr
     *      1-> success
     *      2-> fail, can't stop mapping
     * */
    unsigned char free(DiskMemory &&dmem, bool if_delete_memory_file);

    unsigned char free(DiskMemory &dmem, bool if_delete_memory_file);
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   /////////////////////////////////////////////                                   //
//     DiskVirtualMemoryManager      /////////////////////////////////////////////     DiskVirtualMemoryManager      //
//         Below are some            /////////////////////////////////////////////         Below are some            //
//         implementations           /////////////////////////////////////////////         implementations           //
//                                   //////////////                 //////////////                                   //
/////////////////////////////////////////////////////    NOSE     /////////////////////////////////////////////////////
///////////////////////////////////////////////////////         ///////////////////////////////////////////////////////
////////////////////////////////               //////////     //////////               ////////////////////////////////
////////////////////////////////  POKER  FACE  //////////// ////////////  POKER  FACE  ////////////////////////////////
////////////////////////////////  POKER  FACE  /////////////////////////  POKER  FACE  ////////////////////////////////
////////////////////////////////               /////////////////////////               ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif //VIRTUALMEMORYMANAGER_DVMEM_H
