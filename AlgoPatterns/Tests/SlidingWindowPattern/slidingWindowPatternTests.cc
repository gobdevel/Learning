#include "gtest/gtest.h"
#include "slidingWindowPattern.h"

TEST(SlidingWindowPattern, RunningAverage) {
    Nums nums{1, 3, 2, 6, -1, 4, 1, 8, 2};

    FloatNums expected{2.2, 2.8, 2.4, 3.6, 2.8};

    EXPECT_EQ(findAverages(nums, 5), expected);
}

TEST(SlidingWindowPattern, MaxSumSubarray) {
    Nums nums{2, 1, 5, 1, 3, 2};
    EXPECT_EQ(maxSumSubarray(nums, 3), 9);

    nums = {2, 3, 4, 1, 5};
    EXPECT_EQ(maxSumSubarray(nums, 2), 7);

    nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    EXPECT_EQ(maxSumSubarray(nums, 3), 13);
}

TEST(SlidingWindowPattern, SmallestSubarrayWithGivenSum) {
    Nums nums{2, 1, 5, 1, 3, 2};
    EXPECT_EQ(smallestSubarrayWithGivenSum(nums, 6), 2);

    nums = {2, 3, 4, 1, 5};
    EXPECT_EQ(smallestSubarrayWithGivenSum(nums, 5), 1);

    // nums = {1, 3, 2, 6, -1, 1, 1, 8, 2};
    // EXPECT_EQ(smallestSubarrayWithGivenSum(nums, 0), 2);
}

TEST(SlidingWindowPattern, LongestSubstringWithKDistinctChar) {
    std::string str{"araaci"};
    EXPECT_EQ(findLongestSubstringWithKDistinctCharacters(str, 2), 4);
    EXPECT_EQ(findLongestSubstringWithKDistinctCharacters(str, 1), 2);

    str = "cbbebi";
    EXPECT_EQ(findLongestSubstringWithKDistinctCharacters(str, 3), 5);
}

TEST(SlidingWindowPattern, LongestSubstringWithNoRepeatChars) {
    std::string str{"aabccbb"};
    EXPECT_EQ(findLongestSubstringWithNoRepeatingCharacters(str), 3);

    str = "abbbb";
    EXPECT_EQ(findLongestSubstringWithNoRepeatingCharacters(str), 2);

    str = "abccde";
    EXPECT_EQ(findLongestSubstringWithNoRepeatingCharacters(str), 3);
}

TEST(SlidingWindowPattern, LongestSubstringWithReplacement) {
    std::string str{"aabccbb"};
    EXPECT_EQ(findLongestSubstringWithSameLettersAfterReplacements(str, 2), 5);

    str = "abbcb";
    EXPECT_EQ(findLongestSubstringWithSameLettersAfterReplacements(str, 1), 4);

    str = "abccde";
    EXPECT_EQ(findLongestSubstringWithSameLettersAfterReplacements(str, 1), 3);
}

TEST(SlidingWindowPattern, LongestSubarrayWith1sReplacement) {
    Nums nums{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    EXPECT_EQ(findLongestSubarrayWithOnesAfterReplacements(nums, 2), 6);

    nums = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    EXPECT_EQ(findLongestSubarrayWithOnesAfterReplacements(nums, 3), 9);
}

TEST(SlidingWindowPattern, PermutationPatternInString) {
    std::string str{"oidbcaf"};
    EXPECT_TRUE(findGivenPatternPermutationInString(str, "abc"));

    str = "odicf";
    EXPECT_FALSE(findGivenPatternPermutationInString(str, "dc"));

    str = "bcdxabcdy";
    EXPECT_TRUE(findGivenPatternPermutationInString(str, "bcdyabcdx"));

    str = "aaacb";
    EXPECT_TRUE(findGivenPatternPermutationInString(str, "abc"));
}

TEST(SlidingWindowPattern, FindStringAnagram) {
    std::string str{"ppqp"};
    Nums        res{1, 2};
    EXPECT_EQ(findStringAnagram(str, "pq"), res);

    str = "abbcabc";
    Nums res1{2, 3, 4};
    EXPECT_EQ(findStringAnagram(str, "abc"), res1);
}

TEST(SlidingWindowPattern, SmallestWindowSubstring) {
    std::string str{"aabdec"};
    EXPECT_EQ(smallestWindowSubstring(str, "abc"), "abdec");

    str = "abdabca";
    EXPECT_EQ(smallestWindowSubstring(str, "abc"), "abc");

    str = "adcad";
    EXPECT_EQ(smallestWindowSubstring(str, "abc"), "");
}
