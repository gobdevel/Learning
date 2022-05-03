#include "CyclicSort.h"
#include "gtest/gtest.h"

TEST(CyclicSort, simple) {
    Nums nums{1, 4, 2, 5, 3};
    Nums expected{1, 2, 3, 4, 5};

    cyclicSort(nums);
    EXPECT_EQ(nums, expected);
}

TEST(CyclicSort, Error) {
    Nums nums{1, 4, 2, 5, 3};
    Nums expected{1, 4, 4, 5};

    cyclicSort(nums);
    EXPECT_NE(nums, expected);
}

TEST(CyclicSort, MissingNumber) {
    Nums nums{1, 4, 2, 5, 3};
    EXPECT_EQ(findMissingNumber(nums), 0);

    Nums nums1{1, 4, 2, 0, 3};
    EXPECT_EQ(findMissingNumber(nums1), -1);
}

TEST(CyclicSort, AllMissingNumber) {
    Nums nums{2, 3, 1, 8, 2, 3, 5, 1};
    Nums expected{4, 6, 7};
    auto ret = findAllMissingNumbers(nums);
    EXPECT_EQ(ret, expected);

    Nums nums1{1, 2, 3, 4, 5};
    Nums expected1{};
    auto ret1 = findAllMissingNumbers(nums1);
    EXPECT_EQ(ret1, expected1);
}
