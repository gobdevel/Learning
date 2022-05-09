#ifndef __BINARY_SEARCH_H__
#define __BINARY_SEARCH_H__
#include "utils.h"

int  binarySearch(const Nums& nums, Num key);
int  binarySearchOrderedAgnostic(const Nums& nums, Num key);
int  binarySearchFindCeiling(const Nums& nums, Num key);
char binarySearchNextLetter(std::string& str, char key);
int  binarySearchUnknownSize(const Nums& nums, Num key);
Num  binarySearchMinDistance(const Nums& nums, Num key);
Num  binarySearchBitonicArrayMax(const Nums& nums);
int  binarySearchBitonicArray(const Nums& nums, Num key);
int  binarySearchRotatedSortedArray(const Nums& nums, Num key);
int  binarySearchRotationCount(const Nums& nums);

NumRange binarySearchGetNumberRange(const Nums& nums, Num key);

bool binarySearchSortedRowSortedColMatrix(NumMatrix& matrix, int target);
bool binarySearchSortedMatrix(NumMatrix& matrix, int target);

#endif
