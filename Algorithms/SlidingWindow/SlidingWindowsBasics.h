#ifndef __SLIDING_WINDOW_BASIC_H__
#define __SLIDING_WINDOW_BASIC_H__

#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using Array = std::vector<int>;

/**
 * Type 1  : Fixed Window Size
 * Problem : Given an array consisting of n integers, find the contiguous
 *           subarray of given length k that has the maximum sum value. And
 *           you need to output the maximum sum value.
 */
int findMaxSumOfSubArrayOfSize(Array& nums, int k) {
    int maxSum  = INT_MIN;
    int currMax = 0;
    for (int i = 0; i < nums.size(); ++i) {
        currMax += nums[i];
        if (i >= k - 1) {
            if (maxSum < currMax) {
                maxSum = currMax;
            }
            currMax -= nums[i - (k - 1)];
        }
    }
    return (maxSum == INT_MIN ? 0 : maxSum);
}

/*
 * Type 2  : Dynamic Window Size
 * Problem : Given an array of n positive integers and a positive integer s,
 *           find the minimal length of a contiguous subarray of which the
 *           sum >= s. If there isn't one, return 0 instead.
 */
int sizeOfSmallestSubArrayOfSumGreaterThan(Array& nums, int targetSum) {
    int minSubArraySize = INT_MAX;
    int currSum         = 0;
    int windowStart     = 0;

    for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
        currSum += nums[windowEnd];
        while (currSum >= targetSum) {  // move window from left
            minSubArraySize = (windowEnd - windowStart + 1);
            currSum -= nums[windowStart++];
        }
    }
    return (minSubArraySize == INT_MAX ? 0 : minSubArraySize);
}

/**
 * Type 3  : Dynamic Window Size with Auxilary Data Structure
 * Problem : Given a string, find the length of the longest substring T that
 *           contains at most k distinct characters.
 */
int longestSubstringWithDistinctCharacter(std::string& str, int k) {
    int maxSubString = INT_MIN;
    int windowStart  = 0;

    std::unordered_map<char, int> map;
    for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
        map[str[windowEnd]]++;
        if (map.size() > k) {
            while (windowStart < windowEnd) {
                map[str[windowStart]]--;
                if (map[str[windowStart]] == 0) {
                    map.erase(str[windowStart]);
                }
                ++windowStart;
            }
        }
        maxSubString = std::max(maxSubString, windowEnd - windowStart + 1);
    }
    return (maxSubString == INT_MIN ? 0 : maxSubString);
}

#endif

/**
int main(int argc, char* argv[]) {
    Array nums = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    std::cout << findMaxSumOfSubArrayOfSize(nums, 3) << "\n";
    std::cout << sizeOfSmallestSubArrayOfSumGreaterThan(nums, 10) << "\n";

    std::string str = {"AAAHHIBC"};
    std::cout << longestSubstringWithDistinctCharacter(str, 3) << "\n";
    return 0;
}

*/
