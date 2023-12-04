#include "diskmno.h"

DiskMemory::DiskMemory(void *pointer, size_t block_size) {
    this->_void_p = pointer;
    this->_size = block_size;
}

DiskMemory::DiskMemory() {
    this->_void_p = nullptr;
    this->_size = 0;
}

/*
 * getPointer() returns memory address of the beginning
 * */
void *DiskMemory::pointer() {
    return this->_void_p;
}

/*
 * getSize() returns the size of the memory from the beginning
 * */
size_t DiskMemory::size() {
    return this->_size;
}

bool DiskMemory::syncToDisk(bool if_wait_for_completion) {
    return (
            (if_wait_for_completion ?
             ::msync(this->_void_p, this->_size, MS_SYNC) :
             ::msync(this->_void_p, this->_size, MS_ASYNC)) != -1
    );
}