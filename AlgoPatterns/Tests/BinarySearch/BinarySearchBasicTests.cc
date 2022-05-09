#include "BinarySearch.h"
#include "gtest/gtest.h"
#include "utils.h"

TEST(BinarySearch, SimpleSearch) {
    Nums empty;
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(binarySearch(nums, 5), 2);
    EXPECT_EQ(binarySearch(nums, 4), -1);
    EXPECT_EQ(binarySearch(nums, 1), -1);
    EXPECT_EQ(binarySearch(nums, 45), -1);
    EXPECT_EQ(binarySearch(nums, 2), 0);
    EXPECT_EQ(binarySearch(nums, 34), 7);
    EXPECT_EQ(binarySearch(empty, 0), -1);
}

TEST(BinarySearch, OrderedAgnostic) {
    Nums empty;
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34};
    Nums nums2{34, 23, 11, 7, 6, 5, 3, 2};
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 5), 2);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 4), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 1), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 45), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 2), 0);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums, 34), 7);
    EXPECT_EQ(binarySearchOrderedAgnostic(empty, 0), -1);

    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 5), 5);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 4), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 1), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 45), -1);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 2), 7);
    EXPECT_EQ(binarySearchOrderedAgnostic(nums2, 34), 0);
    EXPECT_EQ(binarySearchOrderedAgnostic(empty, 0), -1);
}

TEST(BinarySearch, Ceiling) {
    Nums empty;
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(binarySearchFindCeiling(nums, 5), 2);
    EXPECT_EQ(binarySearchFindCeiling(nums, 4), 2);
    EXPECT_EQ(binarySearchFindCeiling(nums, 1), 0);
    EXPECT_EQ(binarySearchFindCeiling(nums, 45), -1);
    EXPECT_EQ(binarySearchFindCeiling(nums, 2), 0);
    EXPECT_EQ(binarySearchFindCeiling(nums, 34), 7);
    EXPECT_EQ(binarySearchFindCeiling(empty, 0), -1);
    EXPECT_EQ(binarySearchFindCeiling(nums, 6), 3);
    EXPECT_EQ(binarySearchFindCeiling(nums, 24), 7);
}

TEST(BinarySearch, NextLetter) {
    std::string str{"abcdef"};

    EXPECT_EQ(binarySearchNextLetter(str, 'c'), 'd');
    EXPECT_EQ(binarySearchNextLetter(str, 'f'), 'a');
    EXPECT_EQ(binarySearchNextLetter(str, 'i'), 'a');
    EXPECT_EQ(binarySearchNextLetter(str, 'a'), 'b');
}

TEST(BinarySearch, NumberRange) {
    Nums     nums{2, 3, 5, 6, 6, 6, 6, 34};
    NumRange range  = std::make_pair(3, 6);
    NumRange range2 = std::make_pair(-1, -1);
    NumRange range3 = std::make_pair(0, 0);

    EXPECT_EQ(binarySearchGetNumberRange(nums, 6), range);
    EXPECT_EQ(binarySearchGetNumberRange(nums, 9), range2);
    EXPECT_EQ(binarySearchGetNumberRange(nums, 2), range3);
}

TEST(BinarySearch, UnknownSize) {
    Nums nums{1,  3,  4,  6,  8,  11, 12, 13, 17, 19, 21, 22, 23,
              24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};

    EXPECT_EQ(binarySearchUnknownSize(nums, 13), 7);
    EXPECT_EQ(binarySearchUnknownSize(nums, 1), 0);
    EXPECT_EQ(binarySearchUnknownSize(nums, 22), 11);
    EXPECT_EQ(binarySearchUnknownSize(nums, 21), 10);
    EXPECT_EQ(binarySearchUnknownSize(nums, 0), -1);
    EXPECT_EQ(binarySearchUnknownSize(nums, 5), -1);
    EXPECT_EQ(binarySearchUnknownSize(nums, 16), -1);
}

TEST(BinarySearch, MinDistance) {
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(binarySearchMinDistance(nums, 5), 5);
    EXPECT_EQ(binarySearchMinDistance(nums, 8), 7);
    EXPECT_EQ(binarySearchMinDistance(nums, 1), 2);
    EXPECT_EQ(binarySearchMinDistance(nums, 45), 34);
    EXPECT_EQ(binarySearchMinDistance(nums, 2), 2);
    EXPECT_EQ(binarySearchMinDistance(nums, 34), 34);
}

TEST(BinarySearch, BitonicMax) {
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34, 23, 12, 9};
    EXPECT_EQ(binarySearchBitonicArrayMax(nums), 7);

    nums = {2, 3, 5, 6, 7, 11, 23, 34, 9};
    EXPECT_EQ(binarySearchBitonicArrayMax(nums), 7);

    nums = {2, 3, 1};
    EXPECT_EQ(binarySearchBitonicArrayMax(nums), 1);

    nums = {3, 1};
    EXPECT_EQ(binarySearchBitonicArrayMax(nums), 0);
}

TEST(BinarySearch, BitonicSearch) {
    Nums nums{2, 3, 5, 6, 7, 11, 23, 34, 26, 12, 9};
    EXPECT_EQ(binarySearchBitonicArray(nums, 34), 7);
    EXPECT_EQ(binarySearchBitonicArray(nums, 2), 0);
    EXPECT_EQ(binarySearchBitonicArray(nums, 9), 10);
    EXPECT_EQ(binarySearchBitonicArray(nums, 12), 9);
    EXPECT_EQ(binarySearchBitonicArray(nums, 1), -1);
    EXPECT_EQ(binarySearchBitonicArray(nums, 38), -1);
}

TEST(BinarySearch, SortedRotated) {
    Nums nums{36, 38, 42, 2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 34), 10);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 42), 2);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 2), 3);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 11), 8);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 36), 0);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 45), -1);
    EXPECT_EQ(binarySearchRotatedSortedArray(nums, 1), -1);
}

TEST(BinarySearch, SortedRotatedMin) {
    Nums nums{36, 38, 42, 2, 3, 5, 6, 7, 11, 23, 34};
    EXPECT_EQ(binarySearchRotationCount(nums), 3);

    nums = {4, 1, 2, 3};
    EXPECT_EQ(binarySearchRotationCount(nums), 1);

    nums = {1, 2, 3, 0};
    EXPECT_EQ(binarySearchRotationCount(nums), 3);
}

TEST(BinarySearch, SortedMatrix) {
    NumMatrix empty;
    NumMatrix nums = {
        {4,  5,  6,  7,  8,  9 },
        {10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21}
    };
    EXPECT_TRUE(binarySearchSortedMatrix(nums, 5));
    EXPECT_TRUE(binarySearchSortedMatrix(nums, 4));
    EXPECT_FALSE(binarySearchSortedMatrix(nums, 1));
    EXPECT_FALSE(binarySearchSortedMatrix(nums, 45));
    EXPECT_TRUE(binarySearchSortedMatrix(nums, 21));
    EXPECT_FALSE(binarySearchSortedMatrix(nums, 22));
    EXPECT_FALSE(binarySearchSortedMatrix(empty, 22));
}

TEST(BinarySearch, SortedRowSortedCol) {
    NumMatrix nums{
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    EXPECT_TRUE(binarySearchSortedRowSortedColMatrix(nums, 8));
    EXPECT_TRUE(binarySearchSortedRowSortedColMatrix(nums, 3));
    EXPECT_TRUE(binarySearchSortedRowSortedColMatrix(nums, 17));
    EXPECT_TRUE(binarySearchSortedRowSortedColMatrix(nums, 1));
    EXPECT_TRUE(binarySearchSortedRowSortedColMatrix(nums, 30));
    EXPECT_FALSE(binarySearchSortedRowSortedColMatrix(nums, 45));
    EXPECT_FALSE(binarySearchSortedRowSortedColMatrix(nums, 20));
}
