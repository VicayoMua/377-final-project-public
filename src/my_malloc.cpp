#include <assert.h>
#include <stdio.h>
#include <my_malloc.h>
#include <sys/mman.h>

// Definitions to simplify semaphore operations
#define ts_lock sem_wait(&this->pg_sem)
#define ts_unlock sem_post(&this->pg_sem)

// Constructor
PageManager::PageManager() {
  // Set head to NULL
  this->head = NULL;
  // Initialize Semaphore
  sem_init(&this->pg_sem, 0, 1);
}

// Deconstructor
PageManager::~PageManager() {
  // Lock
  ts_lock;

  // Unmapping the heap
  if (this->head != NULL) {
    munmap(this->head, HEAP_SIZE);
    this->head = NULL;
  }

  // Unlock
  ts_unlock;

  // Destroying the semaphore
  sem_destroy(&this->pg_sem);
}

// The heap function returns the head pointer to the free list. If the heap
node_t* PageManager::heap(char* address = NULL) { 
  ts_lock;
  if (head == NULL) {
    // This allocates the heap and initializes the head node.
    head = (node_t *) mmap(address, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    head->size = HEAP_SIZE - sizeof(node_t);
    head->next = NULL;
  }
  ts_unlock;
  return head;
 }

// Reallocates the heap.
void PageManager::reset_heap() {
  ts_lock;
  if (this->head != NULL) {
    ts_unlock;
    munmap(this->head, HEAP_SIZE);
    ts_lock;
    this->head = NULL;
    ts_unlock;
    this->heap();
  }
  ts_unlock;
}

// Returns a pointer to the head of the free list.
node_t* PageManager::free_list() { return this->head; }

// Calculates the amount of free memory available in the heap.
size_t PageManager::available_memory() {
  size_t n = 0;
  node_t *p = this->heap();
  ts_lock;
  while (p != NULL) {
    n += p->size;
    p = p->next;
  }
  ts_unlock;
  return n;
}

// Returns the number of nodes on the free list.
int PageManager::number_of_free_nodes() {
  int count = 0;
  node_t *p = this->heap();
  ts_lock;
  while (p != NULL) {
    count++;
    p = p->next;
  }
  ts_unlock;
  return count;
}

// Prints the free list. Useful for debugging purposes.
void PageManager::print_free_list() {
  node_t *p = this->heap();
  ts_lock;
  while (p != NULL) {
    printf("Free(%zd)", p->size);
    p = p->next;
    if (p != NULL) {
      printf("->");
    }
  }
  ts_unlock;
  printf("\n");
}

// Finds a node on the free list that has enough available memory to allocate to a calling program.
void PageManager::find_free(size_t size, node_t **found, node_t **previous) {
  ts_lock;
  if (!found || !previous) {ts_unlock; return; }
  *found = NULL;
  *previous = NULL;
  ts_unlock;
  node_t *prev = NULL, *now = this->heap();
  while (now) {
    if (now->size + sizeof(node_t) >= size + sizeof(header_t)) {
      ts_lock;
      *found = now;
      *previous = prev;
      ts_unlock;
      return;
    }
    prev = now;
    now = now->next;
  }
}

// Splits a found free node to accommodate an allocation request.
void PageManager::split(size_t size, node_t **previous, node_t **free_block, header_t **allocated) {
  ts_lock;
  if (!previous || !free_block || !allocated) { ts_unlock; return; }

  if ((*free_block)->size >= size + sizeof(header_t)) {
    node_t *nn = (node_t *) ((char *) (*free_block) + sizeof(header_t) + size);
    size_t oldsize = (*free_block)->size;
    node_t *oldnext = (*free_block)->next;
    nn->size = oldsize - sizeof(header_t) - size;
    nn->next = oldnext;
    if (*previous) {
      (*previous)->next = nn;
    } else { // *free_block == head
      this->head = nn;
    }
    *allocated = (header_t *) (*free_block);
    (*allocated)->size = size;
    (*allocated)->magic = MAGIC;

  } else {
    if (*previous) {
      (*previous)->next = (*free_block)->next;
    } else { // *free_block == head
      this->head = (*free_block)->next;
    }
    *allocated = (header_t *) (*free_block);
    (*allocated)->size = (*free_block)->size + sizeof(node_t) - sizeof(header_t);
    (*allocated)->magic = MAGIC;
  }
  ts_unlock;
}

// Returns a pointer to a region of memory having at least the request `size` bytes.
void* PageManager::my_malloc(size_t size) {
  ts_lock;
  node_t *prev = NULL, *found = NULL;
  ts_unlock;
  this->find_free(size, &found, &prev);
  ts_lock;
  if (!found) { ts_unlock; return NULL; }
  header_t *alloc = NULL;
  ts_unlock;
  this->split(size, &prev, &found, &alloc);
  return (char *) (alloc) + sizeof(header_t);
}

// Merges adjacent nodes on the free list to reduce external fragmentation.
#define h_physi_next_p ((char *) h + sizeof(node_t) + h->size)
#define h_next_p ((char *) (h->next))

void PageManager::coalesce(node_t *free_block) {
  ts_lock;
  if (!free_block) { ts_unlock; return; }
  for (node_t *h = free_block; h; h = h->next) {
    while (h->next && h_next_p == h_physi_next_p) {
      h->size += sizeof(node_t) + h->next->size;
      h->next = h->next->next;
    }
  }
  ts_unlock;
}

// Frees a given region of memory back to the free list.
void PageManager::my_free(void *allocated) {
  ts_lock;
  if (!allocated) { ts_unlock; return; }
  header_t *allochead = (header_t *) ((char *) allocated - sizeof(header_t));
  assert(allochead->magic == MAGIC);
  node_t *freehead = (node_t *) allochead;
  freehead->size = allochead->size + sizeof(header_t) - sizeof(node_t);
  freehead->next = this->head;
  this->head = freehead;
  ts_unlock;
  this->coalesce(this->head);
}