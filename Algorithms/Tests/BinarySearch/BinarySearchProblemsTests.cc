#include <vector>

#include "BinarySearchProblems.h"
#include "gtest/gtest.h"

using Container = std::vector<int>;

TEST(BinarySearchProblem, LeftElement) {
    Container empty;
    Container nums{2, 2, 2, 3,  5,  5,  5,  5,  5, 5,
                   5, 6, 7, 11, 23, 34, 34, 34, 34};

    EXPECT_EQ(BinarySearchLeftElement(nums, 2), 0);
    EXPECT_EQ(BinarySearchLeftElement(nums, 3), 3);
    EXPECT_EQ(BinarySearchLeftElement(nums, 5), 4);
    EXPECT_EQ(BinarySearchLeftElement(nums, 34), 15);
    EXPECT_EQ(BinarySearchLeftElement(nums, 4), -1);
    EXPECT_EQ(BinarySearchLeftElement(nums, 1), -1);
    EXPECT_EQ(BinarySearchLeftElement(nums, 40), -1);
    EXPECT_EQ(BinarySearchLeftElement(empty, 40), -1);
}

TEST(BinarySearchProblem, SingleLeftElement) {
    Container nums{1};
    EXPECT_EQ(BinarySearchLeftElement(nums, 1), 0);
    EXPECT_EQ(BinarySearchLeftElement(nums, 0), -1);
}

TEST(BinarySearchProblem, RightElement) {
    Container empty;
    Container nums{2, 2, 2, 3,  5,  5,  5,  5,  5, 5,
                   5, 6, 7, 11, 23, 34, 34, 34, 34};

    EXPECT_EQ(BinarySearchRightElement(nums, 2), 2);
    EXPECT_EQ(BinarySearchRightElement(nums, 3), 3);
    EXPECT_EQ(BinarySearchRightElement(nums, 5), 10);
    EXPECT_EQ(BinarySearchRightElement(nums, 34), 18);
    EXPECT_EQ(BinarySearchRightElement(nums, 4), -1);
    EXPECT_EQ(BinarySearchRightElement(nums, 1), -1);
    EXPECT_EQ(BinarySearchRightElement(nums, 40), -1);
    EXPECT_EQ(BinarySearchRightElement(empty, 40), -1);
}

TEST(BinarySearchProblem, LeftRightElement) {
    Container empty;
    Container nums{2, 2, 2, 3,  5,  5,  5,  5,  5, 5,
                   5, 6, 7, 11, 23, 34, 34, 34, 34};

    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 2, true), 0);
    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 3, true), 3);
    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 5, false), 10);
    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 34, false), 18);
    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 4, false), -1);
    EXPECT_EQ(BinarySearchRightOrLeftElement(nums, 4, true), -1);
}

TEST(BinarySearchProblem, SingleRightElement) {
    Container nums{1};
    EXPECT_EQ(BinarySearchRightElement(nums, 1), 0);
    EXPECT_EQ(BinarySearchRightElement(nums, 0), -1);
}

TEST(BinarySearchProblem, SortedMatrix) {
    Matrix empty;
    Matrix nums = {
        {4,  5,  6,  7,  8,  9 },
        {10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21}
    };
    EXPECT_TRUE(searchInSortedMatrix(nums, 5));
    EXPECT_TRUE(searchInSortedMatrix(nums, 4));
    EXPECT_FALSE(searchInSortedMatrix(nums, 1));
    EXPECT_FALSE(searchInSortedMatrix(nums, 45));
    EXPECT_TRUE(searchInSortedMatrix(nums, 21));
    EXPECT_FALSE(searchInSortedMatrix(nums, 22));
    EXPECT_FALSE(searchInSortedMatrix(empty, 22));
}
