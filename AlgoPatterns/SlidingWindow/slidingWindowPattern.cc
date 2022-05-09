#include "slidingWindowPattern.h"

#include <limits>
#include <unordered_map>

FloatNums findAverages(const Nums& nums, int k) {
    int startWindow = 0, endWindow = 0;
    int sum = 0;

    FloatNums results;

    for (; endWindow < nums.size(); ++endWindow) {
        sum += nums[endWindow];
        if (endWindow - startWindow + 1 >= k) {
            results.emplace_back(static_cast<float>(sum) / k);
            sum -= nums[startWindow++];
        }
    }
    return results;
}

Num maxSumSubarray(const Nums& nums, int k) {
    int startWindow = 0, endWindow = 0, sum = 0;
    int maxSum = std::numeric_limits<int>::min();

    for (; endWindow < nums.size(); ++endWindow) {
        sum += nums[endWindow];
        if (endWindow - startWindow + 1 >= k) {
            maxSum = std::max(maxSum, sum);
            sum -= nums[startWindow++];
        }
    }
    return (maxSum == std::numeric_limits<int>::min() ? 0 : maxSum);
}

int smallestSubarrayWithGivenSum(const Nums& nums, int sum) {
    int startWindow = 0, endWindow = 0, currSum = 0;
    int smallestSubarraySize = std::numeric_limits<int>::max();

    for (; endWindow < nums.size(); ++endWindow) {
        currSum += nums[endWindow];
        while (currSum >= sum) {
            smallestSubarraySize =
                std::min(smallestSubarraySize, endWindow - startWindow + 1);
            currSum -= nums[startWindow++];
        }
    }
    return (smallestSubarraySize == std::numeric_limits<int>::max()
                ? -1
                : smallestSubarraySize);
}

int findLongestSubstringWithKDistinctCharacters(const std::string& str, int k) {
    int startWindow = 0, endWindow = 0, max = std::numeric_limits<int>::min();

    char map[26]   = {0};
    int  currChars = 0;

    for (; endWindow < str.length(); ++endWindow) {
        int pos = str[endWindow] - 'a';
        if (++map[pos] == 1) {
            currChars++;
        }
        while (currChars > k) {
            int startPos = str[startWindow] - 'a';
            if (--map[startPos] == 0) {
                currChars--;
            }
            ++startWindow;
        }
        if (currChars == k) {
            max = std::max(max, endWindow - startWindow + 1);
        }
    }
    return (max == std::numeric_limits<int>::min() ? 0 : max);
}

int findLongestSubstringWithNoRepeatingCharacters(const std::string& str) {
    int  startWindow = 0, endWindow = 0, max = std::numeric_limits<int>::min();
    char map[26] = {0};

    for (; endWindow < str.length(); ++endWindow) {
        int rightPos = str[endWindow] - 'a';
        map[rightPos]++;

        while (map[rightPos] > 1) {
            int leftPos = str[startWindow] - 'a';
            map[leftPos]--;
            startWindow++;
        }
        max = std::max(max, endWindow - startWindow + 1);
    }
    return max;
}

int findLongestSubstringWithSameLettersAfterReplacements(const std::string& str,
                                                         int                k) {
    int startWindow = 0, endWindow = 0,
        maxRepeatLetterCount = std::numeric_limits<int>::min();
    int max                  = std::numeric_limits<int>::min();
    int map[26]              = {0};

    for (; endWindow < str.length(); ++endWindow) {
        int endPos = str[endWindow] - 'a';
        map[endPos]++;
        maxRepeatLetterCount = std::max(maxRepeatLetterCount, map[endPos]);

        while (endWindow - startWindow + 1 - maxRepeatLetterCount > k) {
            int startPos = str[startWindow] - 'a';
            map[startPos]--;
            startWindow++;
        }
        max = std::max(max, endWindow - startWindow + 1);
    }
    return max;
}

int findLongestSubarrayWithOnesAfterReplacements(const Nums& nums, int k) {
    int startWindow = 0, endWindow = 0, max = std::numeric_limits<int>::min();

    // map to store frequency of 0's and 1's;
    int map[2] = {0};

    for (; endWindow < nums.size(); ++endWindow) {
        map[nums[endWindow]]++;

        if (nums[endWindow] == 1) {
            auto freq = map[nums[endWindow]];

            while (endWindow - startWindow + 1 - freq > k) {
                map[nums[startWindow]]--;
                ++startWindow;
            }
            max = std::max(max, endWindow - startWindow + 1);
        }
    }
    return (max == std::numeric_limits<int>::min() ? 0 : max);
}

bool findGivenPatternPermutationInString(const std::string& str,
                                         const std::string& pattern) {
    int startWindow = 0, endWindow = 0, matched = 0;

    std::unordered_map<char, int> freqMap;

    // Build frequency map
    for (char c : pattern) {
        freqMap[c]++;
    }

    for (; endWindow < str.length(); ++endWindow) {
        char endChar = str[endWindow];

        if (freqMap.find(endChar) !=
            freqMap.end()) {  // char matched with pattern
            if (--freqMap[endChar] == 0) matched++;
        }

        if (matched == freqMap.size()) return true;

        if (endWindow - startWindow + 1 >= pattern.size()) {
            char startChar = str[startWindow];
            if (freqMap.find(startChar) != freqMap.end()) {
                if (freqMap[startChar] == 0) {
                    matched--;
                }
                freqMap[startChar]++;
            }
            ++startWindow;
        }
    }
    return false;
}

// Similar to above only slightly change
Nums findStringAnagram(const std::string& str, const std::string& pattern) {
    int startWindow = 0, endWindow = 0, matched = 0;

    Nums results;  // <<<<<<<<

    std::unordered_map<char, int> freqMap;
    for (auto c : pattern) {
        freqMap[c]++;
    }

    for (; endWindow < str.length(); ++endWindow) {
        char endChar = str[endWindow];
        if (freqMap.find(endChar) != freqMap.end()) {
            if (--freqMap[endChar] == 0) matched++;
        }

        if (matched == freqMap.size()) {
            results.emplace_back(startWindow);  // <<<<<<
        }

        if (endWindow - startWindow + 1 >= pattern.size()) {
            int startChar = str[startWindow];
            if (freqMap.find(startChar) != freqMap.end()) {
                if (freqMap[startChar] == 0) {
                    matched--;
                }
                freqMap[startChar]++;
            }
            ++startWindow;
        }
    }
    return results;  // <<<<<<<<<
}

std::string smallestWindowSubstring(const std::string& str,
                                    const std::string& pattern) {
    int startWindow = 0, endWindow = 0, matched = 0, subStrStart = 0,
        minLength = str.length() + 1;

    std::unordered_map<char, int> freqMap;
    for (auto ch : pattern) {
        freqMap[ch]++;
    }

    for (; endWindow < str.length(); ++endWindow) {
        int endChar = str[endWindow];
        if (freqMap.find(endChar) != freqMap.end()) {
            if (--freqMap[endChar] >= 0) matched++;
        }

        while (matched == pattern.length()) {
            if (minLength > endWindow - startWindow + 1) {
                minLength   = endWindow - startWindow + 1;
                subStrStart = startWindow;
            }

            auto startChar = str[startWindow];
            if (freqMap.find(startChar) != freqMap.end()) {
                if (freqMap[startChar] == 0) matched--;

                freqMap[startChar]++;
            }
            ++startWindow;
        }
    }
    return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
}
