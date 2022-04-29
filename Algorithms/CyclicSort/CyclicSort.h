#ifndef __CYCLIC_SORT_H__
#define __CYCLIC_SORT_H__

#include <vector>
using Nums = std::vector<int>;

/**
 * Given a number in range 1 - N, sort these in O(n).
 */
static void cyclicSort(Nums& num) {
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != i + 1) {
            std::swap(num[i], num[num[i] - 1]);
        }
    }
}

/**
 * Find missing number
 */

static int findMissingNumber(Nums& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < nums.size() && nums[i] != i) {
            std::swap(nums[i], nums[nums[i]]);
        }
    }

    // find missing index
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i) return i;
    }
    return -1;
}

/**
 * Find All missing numbers in 1 - N
 */

static Nums findAllMissingNumbers(Nums& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    Nums res;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            res.emplace_back(i + 1);
        }
    }
    return res;
}
#endif
