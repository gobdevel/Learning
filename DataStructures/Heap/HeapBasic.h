#ifndef __HEAP_BASIC_H__
#define __HEAP_BASIC_H__
#include <vector>

using Container = std::vector<int>;

static int getRoot(int index) { return index / 2; }
static int getLeft(int index) { return (2 * index) + 1; }
static int getRight(int index) { return (2 * index) + 2; }

// Min Heap
void HeapiFy(Container& nums, int index);

void buildHeap(Container& nums);
void BottomUpFix(Container& nums, int index);

void insert(Container& nums, int value);

void remove(Container& nums);
#endif
