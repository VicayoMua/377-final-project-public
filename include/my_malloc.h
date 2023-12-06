#ifndef __MY_MALLOC_H
#define __MY_MALLOC_H

#include <stdlib.h>
#include <semaphore.h>

// Some important constants.
#define HEAP_SIZE 4096
#define MAGIC 0xDEADBEEF

// This struct is used as the header of an allocated block.
typedef struct __header_t {
  size_t size;  // the number of bytes of allocated memory
  unsigned int
      magic;  // the magic number used to identify a valid allocated block
} header_t;

// This struct is used for the free list.
typedef struct __node_t {
  size_t size;            // the number of bytes available in this free block
  struct __node_t *next;  // a pointer to the next free list node
} node_t;


class PageManager {
  private:
    // Semaphor to keep the class thread safe
    sem_t pg_sem;
    // A pointer to the head of the free list.
    node_t *head;

  public:
    // Constructor
    PageManager();

    // Deconstructor
    ~PageManager();

    // Returns head pointer to the free list or uses mmap to allocate a page of memory from the OS and initialize the first free node to parsed address.
    node_t *heap(char* address, int size);

    // Reallocates the heap.
    void reset_heap();

    // Returns a pointer to the head of the free list.
    node_t *free_list();

    // Calculates the amount of free memory available in the heap.
    size_t available_memory();

    // Returns the number of nodes on the free list.
    int number_of_free_nodes();

    // Prints the free list. Useful for debugging purposes.
    void print_free_list();

    // Finds a node on the free list that has enough available memory to allocate to a calling program.
    void find_free(size_t size, node_t **found, node_t **previous);

    // Splits a found free node to accommodate an allocation request.
    void split(size_t size, node_t **previous, node_t **free_block, header_t **allocated);

    // Returns a pointer to a region of memory having at least the request `size` bytes.
    void *my_malloc(size_t size, char* data);

    // Merges adjacent nodes on the free list to reduce external fragmentation.
    void coalesce(node_t *free_block);

    // Frees a given region of memory back to the free list.
    void my_free(void *allocated);
};

#endif