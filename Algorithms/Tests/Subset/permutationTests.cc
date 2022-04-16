#include "Permutation.h"
#include "gtest/gtest.h"

TEST(Permutation, Basic) {
    Input   nums{1, 3, 5};
    Results answer{
        {1, 3, 5},
        {1, 5, 3},
        {3, 1, 5},
        {3, 5, 1},
        {5, 1, 3},
        {5, 3, 1}
    };
    std::sort(answer.begin(), answer.end());

    auto ret = getAllPermutation(nums);
    std::sort(ret.begin(), ret.end());
    EXPECT_EQ(ret, answer);
}
