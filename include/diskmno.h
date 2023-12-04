//
// Created by Vicayo Chang on 11/15/2023.
//
#include "diskmallo.h"
#ifndef VIRTUALMEMORYMANAGER_DISKMNO_H
#define VIRTUALMEMORYMANAGER_DISKMNO_H

/*
 * DiskMemory is thread dangerous without any protections of mutual exclusion.
 * Plus, most implementations are not atomic, so mutex is needed where this class is used!
 * DiskMemory represents the information returned possibly by DiskVirtualMemoryManager.
 * This implementation uses nullptr rather than NULL.
 * */
class DiskMemory {
private:
    void *_void_p;
    size_t _size;
public:
    /*
     * constructor
     * */
    DiskMemory();

    DiskMemory(void *pointer, size_t block_size);

    /*
     * getPointer() returns memory address of the beginning
     * */
    void *pointer();

    /*
     * getSize() returns the size of the memory from the beginning
     * */
    size_t size();

    /*
     * syncToDisk() returns a bool whether the content is successfully immediately synced to disk.
     * */
    bool syncToDisk(bool if_wait_for_completion);
};

#endif //VIRTUALMEMORYMANAGER_DISKMNO_H
