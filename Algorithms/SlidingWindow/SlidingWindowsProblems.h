#ifndef __SLIDING_WINDOW_PROBLEMS_H__
#define __SLIDING_WINDOW_PROBLEMS_H__
#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * Problem : Longest Substring Without Repeating Characters
 *           Given a string s, find the length of the longest substring without
 *           repeating characters.
 *
 * Ex      : Input: s = "abcabcbb"
 *           Output: 3
 *           Explanation: The answer is "abc", with the length of 3.
 *
 * Solution : Using Template - 3
 */
int lengthOfLongestSubstring(std::string s) {
    int maxSubstring = INT_MIN;
    int startWindow = 0, currSubstring = 0;

    std::unordered_map<char, int> map;

    for (int endWindow = 0; endWindow < s.size(); ++endWindow) {
        currSubstring++;
        map[s[endWindow]]++;

        while (map[s[endWindow]] > 1) {
            --currSubstring;
            map[s[startWindow]]--;
            ++startWindow;
        }
        maxSubstring = std::max(maxSubstring, endWindow - startWindow + 1);
    }
    return (maxSubstring == INT_MIN ? 0 : maxSubstring);
}

/**
 * Problem : Minimum Window Substring
 *           Given two strings s and t of lengths m and n respectively, return
 *           the minimum window substring of s such that every character in t
 *           (including duplicates) is included in the window. If there is no
 *           such substring, return the empty string "".
 *
 * Ex      : Input: s = "ADOBECODEBANC", t = "ABC"
 *           Output: "BANC"
 *           Explanation: The minimum window substring "BANC" includes 'A', 'B',
 *           and 'C' from string t.
 *
 * Soln    : Using Template - 3
 */
std::string minWindow(std::string s, std::string t) {
    std::string result{""};
    int         windowStart = 0, currMatch = 0, minLength = INT_MAX;
    std::unordered_map<char, int> mapMatch, map1;

    for (auto& c : t) {
        mapMatch[c]++;
    }

    for (int windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
        char c = s[windowEnd];
        if (mapMatch.find(c) != mapMatch.end()) {
            if (++map1[c] == mapMatch[c]) {
                currMatch++;
            }
        }
        while (currMatch == mapMatch.size()) {  // right condition meet
            // Calculate min length
            if (minLength > windowEnd - windowStart + 1) {
                minLength = windowEnd - windowStart + 1;
                result    = s.substr(windowStart, minLength);
            }
            // Shrink from start
            char c1 = s[windowStart++];
            if (map1.find(c1) != map1.end()) {
                if (--map1[c1] < mapMatch[c1]) {
                    currMatch--;
                }
            }
        }
    }
    return result;
}
#endif

/**
int main() {
    std::cout << minWindow("bba", "ab") << "\n";
    std::cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
    std::cout << minWindow("A", "AA") << "\n";
}

*/
