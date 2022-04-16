#ifndef __SUBSET_H__
#define __SUBSET_H__

#include <vector>

using Results = std::vector<std::vector<int>>;
using Input   = std::vector<int>;

static Results getAllSubset(const Input& nums) {
    // Begin with empty set
    Results subset(1, std::vector<int>{});
    for (const auto& num : nums) {
        auto existingSize = subset.size();
        // This loop should be old school loop
        for (int i = 0; i < existingSize; ++i) {
            // Copy existing
            std::vector<int> set(subset[i]);
            set.emplace_back(num);
            subset.emplace_back(std::move(set));
        }
    }
    return subset;
}

static Results getAllSubsetHandleDuplicate(Input& nums) {
    std::sort(nums.begin(), nums.end());
    // Begin with empty set
    Results subset(1, std::vector<int>{});
    int     startIndex = 0, endIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        startIndex = 0;
        if (i > 0 && nums[i] == nums[i - 1]) {
            startIndex = endIndex + 1;
        }

        endIndex = subset.size() - 1;
        // This loop should be old school loop
        for (int j = startIndex; j <= endIndex; ++j) {
            // Copy existing
            std::vector<int> set(subset[j]);
            set.emplace_back(nums[i]);
            subset.emplace_back(std::move(set));
        }
    }
    return subset;
}

#endif
