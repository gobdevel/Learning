#ifndef __PERMUTATION_H__
#define __PERMUTATION_H__
#include <cctype>
#include <queue>
#include <string>
#include <vector>

using Results = std::vector<std::vector<int>>;
using Input   = std::vector<int>;

static Results getAllPermutation(Input& nums) {
    Results permutation;

    std::queue<std::vector<int>> queue;
    // start with empty
    queue.emplace(std::vector<int>{});

    for (auto& num : nums) {
        auto size = queue.size();
        for (int i = 0; i < size; ++i) {
            auto oldPermutation = std::move(queue.front());
            queue.pop();

            // Add new element at each position
            for (int j = 0; j <= oldPermutation.size(); ++j) {
                auto newPermutation = oldPermutation;
                newPermutation.insert(newPermutation.begin() + j, num);
                if (newPermutation.size() == nums.size()) {
                    permutation.push_back(newPermutation);
                } else {
                    queue.emplace(newPermutation);
                }
            }
        }
    }
    return permutation;
}

using StringResult = std::vector<std::string>;

static StringResult getStringCasePermutation(const std::string& str) {
    StringResult permutations;
    if (str.empty()) return permutations;

    permutations.emplace_back(str);
    for (int i = 0; i < str.length(); ++i) {
        if (std::isalpha(str[i])) {
            int size = permutations.size();
            for (int j = 0; j < size; ++j) {
                auto strCopy = permutations[j];
                if (std::isupper(strCopy[i])) {
                    strCopy[i] = std::tolower(strCopy[i]);
                } else {
                    strCopy[i] = std::toupper(strCopy[i]);
                }
                permutations.emplace_back(std::move(strCopy));
            }
        }
    }
    return permutations;
}
#endif
