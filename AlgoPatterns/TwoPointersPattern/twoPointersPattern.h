#ifndef __TWO_POINTERS_PATTERN_H__
#define __TWO_POINTERS_PATTERN_H__
#include "utils.h"

NumPair findPairWithTargetSumInSortedArray(const Nums& nums, int target);
int     removeDuplicateFromSortedArray(Nums& nums);

Nums     makeSquares(const Nums& nums);
ListNums findTripletSumToZeroInUnsortedArray(Nums& nums);
int      findTripletSumCloseToTarget(Nums& nums, int target);
int      findTripletWithSmallerSum(Nums& nums, int target);

// Two Pointer & sliding Window
ListNums findSubarrayWithProductLessThanTarget(const Nums& nums, int target);
Nums     dutchNationalFlag(Nums& nums);

class QuadrupleSum {
public:
    ListNums find(Nums& nums, int target);

private:
    template <typename BidirectionalIterator>
    ListNums findPairSum(Nums& nums, BidirectionalIterator first,
                         BidirectionalIterator second, int target);
};

class StringWithBackspace {
public:
    bool compare(const std::string& lhs, const std::string& rhs);

private:
    template <typename BidirectionalIterator>
    BidirectionalIterator getNextValidChar(BidirectionalIterator curr,
                                           BidirectionalIterator end);
};

int shortestWindowSort(const Nums& nums);
#endif
