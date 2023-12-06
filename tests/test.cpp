#include <gtest/gtest.h>
#include <my_malloc.h>

PageManager* pManager = NULL;
char data[10] = "Hello";

node_t *heap() { return pManager->heap(NULL, HEAP_SIZE); }

// Reallocates the heap.
void reset_heap() { return pManager->reset_heap(); }

// Returns a pointer to the head of the free list.
node_t *free_list() { return pManager->free_list(); }

// Calculates the amount of free memory available in the heap.
size_t available_memory() { return pManager->available_memory(); }

// Returns the number of nodes on the free list.
int number_of_free_nodes() { return pManager->number_of_free_nodes(); }

// Prints the free list. Useful for debugging purposes.
void print_free_list() { return pManager->print_free_list(); }

// Finds a node on the free list that has enough available memory to allocate to a calling program.
void find_free(size_t size, node_t **found, node_t **previous) { return pManager->find_free(size, found, previous); }

// Splits a found free node to accommodate an allocation request.
void split(size_t size, node_t **previous, node_t **free_block, header_t **allocated) { return pManager->split(size, previous, free_block, allocated); }

// Returns a pointer to a region of memory having at least the request `size` bytes.
void *my_malloc(size_t size) { return pManager->my_malloc(size, data); }

// Merges adjacent nodes on the free list to reduce external fragmentation.
#define h_physi_next_p ((char *) h + sizeof(node_t) + h->size)
#define h_next_p ((char *) (h->next))

void coalesce(node_t *free_block) { return pManager->coalesce(free_block); }

// Frees a given region of memory back to the free list.
void my_free(void *allocated) { pManager->my_free(allocated); }

//////////////////////////////////////////////////////////////////////////////

TEST(MallocTest, InitAndCheckAvailableMemory) {
  std::cout << "test 1" << "\n";
  reset_heap();
  std::cout << "test 2" << "\n";
  size_t size = available_memory();
  std::cout << "test 3" << "\n";
  ASSERT_EQ(size, HEAP_SIZE - sizeof(node_t));
}

TEST(MallocTest, CheckNumberOfFreeNodes) {
  reset_heap();
  int count = number_of_free_nodes();
  ASSERT_EQ(count, 1);
}

TEST(MallocTest, SimpleMallocCall) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
}

TEST(MallocTest, SimpleMallocCallNumberOfFreeNodes) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
  int count = number_of_free_nodes();
  ASSERT_EQ(count, 1);
}

TEST(MallocTest, MallocTooMuchMemory) {
  reset_heap();
  void *p = my_malloc(10000);
  ASSERT_TRUE(p == NULL);
}

TEST(MallocTest, SimpleMallocCallCheckAvailableMemory) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
  size_t size = available_memory();
  ASSERT_EQ(size, HEAP_SIZE - sizeof(node_t) * 2 - 100);
}

TEST(MallocTest, CheckYourHead) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_FALSE(p == NULL);

  header_t *head = (header_t *)((char *)p - sizeof(header_t));
  ASSERT_EQ(head->magic, MAGIC);
}

TEST(MallocTest, SimpleFreeCheck) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_FALSE(p == NULL);

  void *k = my_malloc(100);
  ASSERT_FALSE(k == NULL);

  my_free(p);
  ASSERT_EQ(number_of_free_nodes(), 2);
  k = NULL;  // to stop compiler warnings.
}

TEST(MallocTest, SimpleFreeCheck2) {
  reset_heap();
  char* test[40];
  for (int i = 0; i < 35; i++) {
    test[i] = (char*)my_malloc(100);
    ASSERT_FALSE(test[i] == NULL);
  }

  for (int i = 34; i >= 0; i--) {
    my_free(test[i]);    
  }

  ASSERT_TRUE(available_memory() == 4096 - sizeof(header_t));
}

int main(int argc, char **argv) {
  pManager = new PageManager();

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}