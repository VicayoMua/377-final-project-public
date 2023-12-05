#include "diskmallo"
#include <fstream>

int main() {


    DiskVirtualMemoryManager *dvmm = new DiskVirtualMemoryManager("./mem_files");

    DiskMemory dm = dvmm->calloc(1024, sizeof(char));

    if (dm.pointer() != NULL) {
        ::sprintf((char *) dm.pointer(), "Hello World. ");
    } else {
        ::printf("NULL pointer");
    }

    dm.syncToDisk(true);

    dvmm->free(dm, false);

    delete dvmm;


    std::fstream fs("./mem_files/mem_0");
    fs.seekg(std::ios::beg);
    char charr[100];
    fs.get(charr, 100);
    std::cout << charr << std::endl;
    return 0;



//    DiskVirtualMemoryManager *dvmm = new DiskVirtualMemoryManager("./mems");
//    ::printf("The disk folder can hold %lu new bytes. \n", dvmm->checkDiskFolderCapacity());
//
//    ::printf("Allocating 1 kilobyte as disk file ./mems/mem_0. \n");
//    DiskMemory dm0 = dvmm->malloc(1024);
//
//    printf("Printing hello to disk vm file ./mems/mem_0. \n");
//    void *page0 = dm0.pointer();
//    size_t page0_size = dm0.size();
//    snprintf((char *) page0, 7, "hello\n");
//
//    printf("Asking machine to write changes to disk immediately and wait for completion. \n");
//    dm0.syncToDisk(true);
//
//    printf("Freeing memory allocated for dm0. \n");
//    dvmm->free(dm0, false);
//
//    ::printf("Allocating 1 kilobyte as disk vm file ./mems/mem_0. \n");
//    DiskMemory dm1 = dvmm->calloc(1024, 1);
//    dvmm->free(dm1, false);
//
//    delete dvmm; // this operation will free all allocated space and delete memory files

    return 0;
}

