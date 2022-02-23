#include "BinaryTreeGeneric.h"
#include "gtest/gtest.h"

TEST(BinaryTree, Basic) {
    BinaryTree<int, int> bt;
    bt.emplace(23, 233).emplace(48, 488).emplace(19, 199).emplace(40, 400);

    EXPECT_EQ(*bt.find(40), 400);
    EXPECT_EQ(*bt.find(19), 199);
    EXPECT_EQ(bt.find(199), nullptr);
}
