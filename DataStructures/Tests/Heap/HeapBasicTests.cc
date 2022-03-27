#include <algorithm>

#include "HeapBasic.h"
#include "gtest/gtest.h"

TEST(Heap, Build) {
    std::vector<int> data{2, 3, 1, 6, 7, 8, 4};
    buildHeap(data);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));
}

TEST(Heap, insert) {
    std::vector<int> data{2, 3, 1, 6, 7, 8, 4};
    buildHeap(data);

    insert(data, 9);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));

    insert(data, 14);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));

    insert(data, 0);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));
}

TEST(Heap, remove) {
    std::vector<int> data{2, 3, 1, 6, 7, 8, 4};
    buildHeap(data);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));

    remove(data);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));

    remove(data);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));

    remove(data);
    EXPECT_TRUE(std::is_heap(data.begin(), data.end(), std::greater{}));
}
