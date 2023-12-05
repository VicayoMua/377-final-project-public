#include <assert.h>
#include <stdio.h>
#include <my_malloc.h>
#include <sys/mman.h>

// A pointer to the head of the free list.
node_t *head = NULL;

// The heap function returns the head pointer to the free list. If the heap
// has not been allocated yet (head is NULL) it will use mmap to allocate
// a page of memory from the OS and initialize the first free node.
node_t *heap() {
    if (head == NULL) {
        // This allocates the heap and initializes the head node.
        head = (node_t *) mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE,
                               MAP_ANON | MAP_PRIVATE, -1, 0);
        head->size = HEAP_SIZE - sizeof(node_t);
        head->next = NULL;
    }

    return head;
}

// Reallocates the heap.
void reset_heap() {
    if (head != NULL) {
        munmap(head, HEAP_SIZE);
        head = NULL;
        heap();
    }
}

// Returns a pointer to the head of the free list.
node_t *free_list() {
    return head;
}

// Calculates the amount of free memory available in the heap.
size_t available_memory() {
    size_t n = 0;
    node_t *p = heap();
    while (p != NULL) {
        n += p->size;
        p = p->next;
    }
    return n;
}

// Returns the number of nodes on the free list.
int number_of_free_nodes() {
    int count = 0;
    node_t *p = heap();
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// Prints the free list. Useful for debugging purposes.
void print_free_list() {
    node_t *p = heap();
    while (p != NULL) {
        printf("Free(%zd)", p->size);
        p = p->next;
        if (p != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

// Finds a node on the free list that has enough available memory to
// allocate to a calling program. This function uses the "first-fit"
// algorithm to locate a free node.
//
// PARAMETERS:
// size - the number of bytes requested to allocate
//
// RETURNS:
// found - the node found on the free list with enough memory to allocate
// previous - the previous node to the found node
//

void find_free(size_t size, node_t **found, node_t **previous) {
    // TODO
    if (!found || !previous) return;
    *found = NULL;
    *previous = NULL;
    node_t *prev = NULL, *now = heap();
    while (now) {
        if (now->size + sizeof(node_t) >= size + sizeof(header_t)) {
            *found = now;
            *previous = prev;
            return;
        }
        prev = now;
        now = now->next;
    }
}

// Splits a found free node to accommodate an allocation request.
//
// The job of this function is to take a given free_node found from
// `find_free` and split it according to the number of bytes to allocate.
// In doing so, it will adjust the size and next pointer of the `free_block`
// as well as the `previous` node to properly adjust the free list.
//
// PARAMETERS:
// size - the number of bytes requested to allocate
// previous - the previous node to the free block
// free_block - the node on the free list to allocate from
//
// RETURNS:
// allocated - an allocated block to be returned to the calling program
//
void split(size_t size, node_t **previous, node_t **free_block, header_t **allocated) {
    // TODO
    if (!previous || !free_block || !allocated)
        return;
   if ((*free_block)->size >= size + sizeof(header_t)) {
       node_t *nn = (node_t *) ((char *) (*free_block) + sizeof(header_t) + size);
       size_t oldsize = (*free_block)->size;
       node_t *oldnext = (*free_block)->next;
       nn->size = oldsize - sizeof(header_t) - size;
       nn->next = oldnext;
       if (*previous) {
           (*previous)->next = nn;
       } else { // *free_block == head
           head = nn;
       }
       *allocated = (header_t *) (*free_block);
       (*allocated)->size = size;
       (*allocated)->magic = MAGIC;
   } else {
       if (*previous) {
           (*previous)->next = (*free_block)->next;
       } else { // *free_block == head
           head = (*free_block)->next;
       }
       *allocated = (header_t *) (*free_block);
       (*allocated)->size = (*free_block)->size + sizeof(node_t) - sizeof(header_t);
       (*allocated)->magic = MAGIC;
   }
}

// Returns a pointer to a region of memory having at least the request `size`
// bytes.
//
// PARAMETERS:
// size - the number of bytes requested to allocate
//
// RETURNS:
// A void pointer to the region of allocated memory
//
void *my_malloc(size_t size) {
    // TODO
//    if (size <= 0) return NULL;
    node_t *prev = NULL, *found = NULL;
    find_free(size, &found, &prev);
    if (!found) return NULL;
    header_t *alloc = NULL;
    split(size, &prev, &found, &alloc);
    return (char *) (alloc) + sizeof(header_t);
}

// Merges adjacent nodes on the free list to reduce external fragmentation.
//
// This function will only coalesce nodes starting with `free_block`. It will
// not handle coalescing of previous nodes (we don't have previous pointers!).
//
// PARAMETERS:
// free_block - the starting node on the free list to coalesce
//
#define h_physi_next_p ((char *) h + sizeof(node_t) + h->size)
#define h_next_p ((char *) (h->next))

void coalesce(node_t *free_block) {
    // TODO
    if (!free_block) return;
    for (node_t *h = free_block; h; h = h->next) {
        while (h->next && h_next_p == h_physi_next_p) {
            h->size += sizeof(node_t) + h->next->size;
            h->next = h->next->next;
        }
    }
}

// Frees a given region of memory back to the free list.
//
// PARAMETERS:
// allocated - a pointer to a region of memory previously allocated by my_malloc
//
void my_free(void *allocated) {
    // TODO
    if (!allocated) return;
    header_t *allochead = (header_t *) ((char *) allocated - sizeof(header_t));
    assert(allochead->magic == MAGIC);
    node_t *freehead = (node_t *) allochead;
    freehead->size = allochead->size + sizeof(header_t) - sizeof(node_t);
    freehead->next = head;
    head = freehead;
    coalesce(head);
}
