#ifndef __SLIDING_WINDOW_PATTERN_H__
#define __SLIDING_WINDOW_PATTERN_H__
#include "utils.h"

FloatNums findAverages(const Nums& nums, int k);
Num       maxSumSubarray(const Nums& nums, int k);
int       smallestSubarrayWithGivenSum(const Nums& nums, int sum);

int findLongestSubstringWithKDistinctCharacters(const std::string& str, int k);
int findLongestSubstringWithNoRepeatingCharacters(const std::string& str);
int findLongestSubstringWithSameLettersAfterReplacements(const std::string& str,
                                                         int                k);
int findLongestSubarrayWithOnesAfterReplacements(const Nums& nums, int k);

bool findGivenPatternPermutationInString(const std::string& str,
                                         const std::string& pattern);

Nums findStringAnagram(const std::string& str, const std::string& pattern);

std::string smallestWindowSubstring(const std::string& str,
                                    const std::string& pattern);
#endif
