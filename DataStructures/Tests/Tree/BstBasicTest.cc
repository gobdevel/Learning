#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(TREE, Basic) {
    BTree<int, int> bt;
    bt.insert(10, 100);
    bt.insert(8, 88);
    bt.insert(7, 140);
    bt.insert(9, 140);
    bt.insert(12, 100);
    bt.insert(14, 88);
    bt.insert(16, 140);
    EXPECT_EQ(bt.getHeight(), 4);
}
