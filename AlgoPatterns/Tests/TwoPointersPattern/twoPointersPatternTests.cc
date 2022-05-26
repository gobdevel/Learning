#include "gtest/gtest.h"
#include "twoPointersPattern.h"

TEST(TwoPointersPattern, TargetSumInSortedArray) {
    Nums nums{1, 2, 3, 4, 6};
    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 6),
              std::make_pair(1, 3));

    nums = {2, 5, 9, 11};
    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 11),
              std::make_pair(0, 2));

    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 8),
              std::make_pair(-1, -1));

    nums = {1, 2};
    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 3),
              std::make_pair(0, 1));

    nums = {1};
    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 1),
              std::make_pair(-1, -1));

    nums = {};
    EXPECT_EQ(findPairWithTargetSumInSortedArray(nums, 1),
              std::make_pair(-1, -1));
}

TEST(TwoPointersPattern, RemoveDuplicateSortedArray) {
    Nums nums{2, 3, 3, 3, 6, 9, 9};
    EXPECT_EQ(removeDuplicateFromSortedArray(nums), 4);

    nums = {2, 2, 2, 11};
    EXPECT_EQ(removeDuplicateFromSortedArray(nums), 2);

    nums = {2};
    EXPECT_EQ(removeDuplicateFromSortedArray(nums), 1);

    nums = {};
    EXPECT_EQ(removeDuplicateFromSortedArray(nums), 0);
}

TEST(TwoPointersPattern, MakeSquares) {
    Nums nums{-2, -1, 0, 2, 3};
    Nums expected{0, 1, 4, 4, 9};

    EXPECT_EQ(makeSquares(nums), expected);

    nums     = {-3, -1, 0, 1, 2};
    expected = {0, 1, 1, 4, 9};
    EXPECT_EQ(makeSquares(nums), expected);

    nums     = {2};
    expected = {4};
    EXPECT_EQ(makeSquares(nums), expected);

    nums     = {-2};
    expected = {4};
    EXPECT_EQ(makeSquares(nums), expected);

    nums     = {};
    expected = {};
    EXPECT_EQ(makeSquares(nums), expected);

    nums     = {-1, -2, -3};
    expected = {1, 4, 9};
    EXPECT_EQ(makeSquares(nums), expected);
}

TEST(TwoPointersPattern, FindTripletSumToZero) {
    Nums     nums{-3, 0, 1, 2, -1, 1, -2};
    ListNums expected{
        {-3, 1, 2},
        {-2, 0, 2},
        {-2, 1, 1},
        {-1, 0, 1}
    };

    EXPECT_EQ(findTripletSumToZeroInUnsortedArray(nums), expected);

    nums     = {-5, 2, -1, -2, 3};
    expected = {
        {-5, 2,  3},
        {-2, -1, 3}
    };
    EXPECT_EQ(findTripletSumToZeroInUnsortedArray(nums), expected);

    nums     = {-5, 2};
    expected = {{}};
    EXPECT_EQ(findTripletSumToZeroInUnsortedArray(nums), expected);

    nums     = {-5};
    expected = {{}};
    EXPECT_EQ(findTripletSumToZeroInUnsortedArray(nums), expected);

    nums     = {};
    expected = {{}};
    EXPECT_EQ(findTripletSumToZeroInUnsortedArray(nums), expected);
}

TEST(TwoPointersPattern, TripletWithCloseSum) {
    Nums nums{-2, 0, 1, 2};
    EXPECT_EQ(findTripletSumCloseToTarget(nums, 2), 1);

    nums = {-3, -1, 1, 2};
    EXPECT_EQ(findTripletSumCloseToTarget(nums, 1), 0);

    nums = {1, 0, 1, 1};
    EXPECT_EQ(findTripletSumCloseToTarget(nums, 100), 3);
}

TEST(TwoPointersPattern, TripletWithSmallerSum) {
    Nums nums{-1, 0, 2, 3};
    EXPECT_EQ(findTripletWithSmallerSum(nums, 3), 2);

    nums = {-1, 4, 2, 1, 3};
    EXPECT_EQ(findTripletWithSmallerSum(nums, 5), 4);
}

TEST(TwoPointersPattern, SubarrayWithProduct) {
    Nums     nums{2, 5, 3, 10};
    ListNums expected{
        {2 },
        {5 },
        {2,  5},
        {3 },
        {5, 3},
        {10}
    };

    EXPECT_EQ(findSubarrayWithProductLessThanTarget(nums, 30), expected);

    nums     = {8, 2, 6, 5};
    expected = {
        {8 },
        {   2 },
        {   8,  2},
        {    6 },
        {  2,  6},
        {    5},
        { 6,   5}
    };
    EXPECT_EQ(findSubarrayWithProductLessThanTarget(nums, 50), expected);
}

TEST(TwoPointersPattern, DutchNationalFlag) {
    Nums nums{1, 0, 2, 1, 0};
    Nums expected{0, 0, 1, 1, 2};

    EXPECT_EQ(dutchNationalFlag(nums), expected);

    nums     = {2, 2, 0, 1, 2, 0};
    expected = {0, 0, 1, 2, 2, 2};
    EXPECT_EQ(dutchNationalFlag(nums), expected);
}

TEST(TwoPointersPattern, QuadrapleSum) {
    QuadrupleSum q;
    Nums         nums{4, 1, 2, -1, 1, -3};
    ListNums     expected{
        {-3, -1, 1, 4},
        {-3, 1,  1, 2}
    };

    EXPECT_EQ(q.find(nums, 1), expected);

    nums     = {2, 0, -1, 1, -2, 2};
    expected = {
        {-2, 0, 2, 2},
        {-1, 0, 1, 2}
    };
    EXPECT_EQ(q.find(nums, 2), expected);
}

TEST(TwoPointersPattern, StringCompareWithBackspaces) {
    StringWithBackspace s;
    EXPECT_TRUE(s.compare("xy#z", "xzz#"));
    EXPECT_FALSE(s.compare("xy#z", "xyz#"));
    EXPECT_TRUE(s.compare("xp#", "xyz##"));
    EXPECT_TRUE(s.compare("xywrrmp", "xywrrmu#p"));
}

TEST(TwoPointersPattern, MinimumWindowSort) {
    Nums nums{1, 2, 5, 3, 7, 10, 9, 12};
    EXPECT_EQ(shortestWindowSort(nums), 5);

    nums = {1, 3, 2, 0, -1, 7, 10};
    EXPECT_EQ(shortestWindowSort(nums), 5);

    nums = {1, 2, 3};
    EXPECT_EQ(shortestWindowSort(nums), 0);
}
