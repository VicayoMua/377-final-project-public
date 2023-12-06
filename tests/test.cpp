#include <gtest/gtest.h>
#include <PageManager_ExtendedProj5>
#include "diskmallo"

DiskVirtualMemoryManager *dvmm = new DiskVirtualMemoryManager("./mem_files");

DiskMemory dm = dvmm->malloc(1024 * 1024 * 1024);

PageManager *pManager = new PageManager(dm.pointer(), dm.size());

#define HEAP_SIZE dm.size()

char data[10] = "Hello";

// Reallocates the heap.
void reset_heap() { return pManager->resetPage(); }

// Calculates the amount of free memory available in the heap.
size_t available_memory() { return pManager->availableSizeTotal(); }

// Returns the number of nodes on the free list.
int number_of_free_nodes() { return pManager->freeNodesNumber(); }

// Prints the free list. Useful for debugging purposes.
void print_free_list() { return pManager->printFreeNodes(); }

// Returns a pointer to a region of memory having at least the request `size` bytes.
void *my_malloc(size_t size) { return pManager->allocatePage(size, data); }

// Merges adjacent nodes on the free list to reduce external fragmentation.
#define h_physi_next_p ((char *) h + sizeof(node_t) + h->size)
#define h_next_p ((char *) (h->next))

// Frees a given region of memory back to the free list.
void my_free(void *allocated) { pManager->freePage(allocated); }

TEST(TestCase, InitAndCheckAvailableMemory) {
  reset_heap();
  size_t size = available_memory();
  ASSERT_EQ(size, HEAP_SIZE - sizeof(node_t));
}

TEST(TestCase, CheckNumberOfFreeNodes) {
  reset_heap();
  int count = number_of_free_nodes();
  ASSERT_EQ(count, 1);
}

TEST(TestCase, SimpleMallocCall) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
}

TEST(TestCase, SimpleMallocCallNumberOfFreeNodes) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
  int count = number_of_free_nodes();
  ASSERT_EQ(count, 1);
}

TEST(TestCase, MallocTooMuchMemory) {
  reset_heap();
  void *p = my_malloc(10000);
  ASSERT_TRUE(p == NULL);
}

TEST(TestCase, SimpleMallocCallCheckAvailableMemory) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_TRUE(p != NULL);
  size_t size = available_memory();
  ASSERT_EQ(size, HEAP_SIZE - sizeof(node_t) * 2 - 100);
}

TEST(TestCase, CheckYourHead) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_FALSE(p == NULL);

  header_t *head = (header_t *)((char *)p - sizeof(header_t));
  ASSERT_EQ(head->magic, MAGIC);
}

TEST(TestCase, SimpleFreeCheck) {
  reset_heap();
  void *p = my_malloc(100);
  ASSERT_FALSE(p == NULL);

  void *k = my_malloc(100);
  ASSERT_FALSE(k == NULL);

  my_free(p);
  ASSERT_EQ(number_of_free_nodes(), 2);
  k = NULL;  // to stop compiler warnings.
}

TEST(TestCase, SimpleFreeCheck2) {
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
    DiskVirtualMemoryManager *dvmm = new DiskVirtualMemoryManager("./mem_files");
    DiskMemory dm = dvmm->malloc(1024 * 1024 * 1024);
    PageManager *pManager = new PageManager(dm.pointer(), dm.size());   

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}