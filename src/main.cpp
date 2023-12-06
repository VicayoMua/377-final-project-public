#include "diskmallo"
#include "PageManager_ExtendedProj5"
#include <fstream>

int main() {


    DiskVirtualMemoryManager *dvmm = new DiskVirtualMemoryManager("./mem_files");

    DiskMemory dm = dvmm->malloc(1024 * 1024 * 1024);

    PageManager *pm = new PageManager(dm.pointer(), dm.size());

    pm->allocatePage(64, (char *) "Hello World..! 2333");

    delete pm;

    dm.syncToDisk(true);

    dvmm->free(dm, false);

    delete dvmm;

    return 0;

}

