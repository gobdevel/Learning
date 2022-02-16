#include <vector>

#include "BinarySearchBasics.h"
#include "gtest/gtest.h"

using Container = std::vector<int>;

TEST(BinarySearch, Template1) {
    Container empty;
    Container nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(BinarySearchTemplate1(nums, 5), 2);
    EXPECT_EQ(BinarySearchTemplate1(nums, 4), -1);
    EXPECT_EQ(BinarySearchTemplate1(nums, 1), -1);
    EXPECT_EQ(BinarySearchTemplate1(nums, 45), -1);
    EXPECT_EQ(BinarySearchTemplate1(nums, 2), 0);
    EXPECT_EQ(BinarySearchTemplate1(nums, 34), 7);
    EXPECT_EQ(BinarySearchTemplate1(empty, 0), -1);
}

TEST(BinarySearch, Template2) {
    Container empty;
    Container nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(BinarySearchTemplate2(nums, 5), 2);
    EXPECT_EQ(BinarySearchTemplate2(nums, 4), -1);
    EXPECT_EQ(BinarySearchTemplate2(nums, 1), -1);
    EXPECT_EQ(BinarySearchTemplate2(nums, 45), -1);
    EXPECT_EQ(BinarySearchTemplate2(nums, 2), 0);
    EXPECT_EQ(BinarySearchTemplate2(nums, 34), 7);
    EXPECT_EQ(BinarySearchTemplate2(empty, 0), -1);
}

TEST(BinarySearch, Template3) {
    Container empty;
    Container nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(BinarySearchTemplate3(nums, 5), 2);
    EXPECT_EQ(BinarySearchTemplate3(nums, 4), -1);
    EXPECT_EQ(BinarySearchTemplate3(nums, 1), -1);
    EXPECT_EQ(BinarySearchTemplate3(nums, 45), -1);
    EXPECT_EQ(BinarySearchTemplate3(nums, 2), 0);
    EXPECT_EQ(BinarySearchTemplate3(nums, 34), 7);
    EXPECT_EQ(BinarySearchTemplate3(empty, 0), -1);
}
