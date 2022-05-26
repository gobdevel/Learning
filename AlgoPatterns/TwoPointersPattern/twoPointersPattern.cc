#include "twoPointersPattern.h"

#include <algorithm>
#include <deque>
#include <iterator>
#include <limits>

#include "utils.h"

NumPair findPairWithTargetSumInSortedArray(const Nums& nums, int target) {
    if (nums.empty()) return {-1, -1};

    auto left = nums.begin(), right = std::prev(nums.end());
    while (left < right) {
        auto sum = *left + *right;
        if (sum == target) {
            return {std::distance(nums.begin(), left),
                    std::distance(nums.begin(), right)};
        }
        if (sum > target) {
            --right;
        } else {
            ++left;
        }
    }
    return {-1, -1};
}

int removeDuplicateFromSortedArray(Nums& nums) {
    if (nums.empty()) return 0;

    int  size = 1;
    auto curr = nums.begin();

    for (auto next = std::next(curr); next != nums.end(); ++next) {
        if (*curr != *next) {
            ++size;
            curr = next;
        }
    }
    return size;
}

Nums makeSquares(const Nums& nums) {
    if (nums.empty()) return nums;

    Nums result(nums.size(), 0);
    auto left = nums.begin(), right = std::prev(nums.end());
    auto res = result.rbegin();

    // This is important not all two pointer have same while loop
    while (left <= right) {
        auto leftSquare  = (*left) * (*left);
        auto rightSquare = (*right) * (*right);

        if (leftSquare > rightSquare) {
            *res = leftSquare;
            ++left;
        } else {
            *res = rightSquare;
            --right;
        }
        ++res;
    }
    return result;
}

template <typename BidirectionalIterator>
void findPairSum(BidirectionalIterator left, BidirectionalIterator right,
                 int targetSum, ListNums& result) {
    while (left < right) {
        auto sum = *left + *right;
        if (sum == targetSum) {
            result.emplace_back(Nums{-targetSum, *left, *right});
            ++left;
            --right;

            // Avoid duplicate
            while (left < right && *left == *std::prev(left)) {
                ++left;
            }

            // Avoid duplicate
            while (left < right && *right == *std::next(right)) {
                --right;
            }
        } else if (sum < targetSum) {
            ++left;
        } else {
            --right;
        }
    }
}

ListNums findTripletSumToZeroInUnsortedArray(Nums& nums) {
    auto size = nums.size();
    if (size < 3) return {{}};

    // sort the nums;
    std::sort(nums.begin(), nums.end());

    ListNums result;
    auto     curr = nums.begin();
    for (auto next = std::next(curr); next != nums.end(); ++next, ++curr) {
        if (*curr != *next) {  // removing duplicate
            findPairSum(next, std::prev(nums.end()), -(*curr), result);
        }
    }
    return result;
}

int findTripletSumCloseToTarget(Nums& nums, int target) {
    if (nums.size() < 3) return -1;

    std::sort(nums.begin(), nums.end());
    int smallestDifference = std::numeric_limits<int>::max();

    auto curr = nums.begin(), next = std::next(curr);

    for (; next != nums.end(); ++next, ++curr) {
        auto left = next, right = std::prev(nums.end());

        while (left < right) {
            // comparing the sum of three numbers to the targetSum can cause
            // overflow so, we will try to find target difference.
            auto diff = target - *curr - *left - *right;
            if (diff == 0) {  // we have found triplet with exact match
                return target - diff;
            }

            // Update smallest difference
            if (abs(diff) < abs(smallestDifference)) {
                smallestDifference = diff;
            }

            if (diff > 0) {  // we need bigger triplet
                ++left;
            } else {
                --right;  // We need smaller triplet
            }
        }
    }
    return (target - smallestDifference);
}

int findTripletWithSmallerSum(Nums& nums, int target) {
    if (nums.size() < 3) return 0;
    std::sort(nums.begin(), nums.end());
    int count = 0;

    auto curr = nums.begin(), next = std::next(curr);
    for (; next != nums.end(); ++next, ++curr) {
        auto left = next, right = std::prev(nums.end());

        while (left < right) {
            if (*left + *right < (target - *curr)) {  // B + C = Target - A
                // As array is sorted all numbers less than right will staisfy
                // above equation
                count += std::distance(left, right);
                ++left;
            } else {
                --right;
            }
        }
    }
    return count;
}

ListNums findSubarrayWithProductLessThanTarget(const Nums& nums, int target) {
    if (nums.empty()) return {{}};
    ListNums result;

    int  product     = 1;
    auto startWindow = nums.begin(), endWindow = startWindow;

    for (; endWindow != nums.end(); ++endWindow) {
        product *= *endWindow;
        while (product >= target && startWindow < nums.end()) {
            product /= *startWindow;
            ++startWindow;
        }

        // Now We have a subarray with product less than target.
        // Since the product of all numbers from startWindow to endWindow will
        // have a product less than the target therefor, all subarray from start
        // to end will have a product less than target as well. To avoid
        // duplicates, we will start with a subarray containing only *endWindow
        // and then extend it.
        std::deque<int> tempList;
        for (auto it = endWindow; it >= startWindow; --it) {
            tempList.emplace_front(*it);
            Nums resultVec;
            std::move(std::begin(tempList), std::end(tempList),
                      std::back_inserter(resultVec));
            result.push_back(resultVec);
        }
    }
    return result;
}

// Separate 0, 1, 2
Nums dutchNationalFlag(Nums& nums) {
    if (nums.size() < 2) return nums;

    auto left = nums.begin(), right = std::prev(nums.end());

    for (auto i = nums.begin(); i <= right;) {
        if (*i == 0) {
            std::iter_swap(left++, i++);
        } else if (*i == 1) {
            ++i;
        } else {
            std::iter_swap(right--, i);
        }
    }
    return nums;
}

ListNums QuadrupleSum::find(Nums& nums, int target) {
    if (nums.size() < 4) return {{}};

    ListNums results;

    std::sort(nums.begin(), nums.end());

    for (auto first = nums.begin(); first != nums.end(); ++first) {
        for (auto second = std::next(first); second != nums.end(); ++second) {
            auto lists = findPairSum(nums, first, second, target);
            std::move(lists.begin(), lists.end(), std::back_inserter(results));
        }
    }
    return results;
}

template <typename BidirectionalIterator>
ListNums QuadrupleSum::findPairSum(Nums& nums, BidirectionalIterator first,
                                   BidirectionalIterator second, int target) {
    ListNums results;
    auto     left = std::next(second), right = std::prev(nums.end());

    while (left <= right) {
        auto sum = *first + *second + *left + *right;
        if (sum == target) {
            results.emplace_back(Nums{*first, *second, *left, *right});
            ++left;
            --right;
            while (left < right && *left == *std::prev(left)) {
                ++left;
            }

            while (left < right && *right == *std::next(right)) {
                --right;
            }
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return results;
}

bool StringWithBackspace::compare(const std::string& lhs,
                                  const std::string& rhs) {
    auto rstartLeft  = lhs.rbegin();
    auto rstartRight = rhs.rbegin();

    while ((rstartLeft = getNextValidChar(rstartLeft, lhs.rend())) !=
               lhs.rend() &&
           (rstartRight = getNextValidChar(rstartRight, rhs.rend())) !=
               rhs.rend()) {
        if (*rstartLeft != *rstartRight) return false;

        ++rstartLeft;
        ++rstartRight;
    }

    return (rstartLeft == lhs.rend() && rstartRight == rhs.rend());
}

template <typename BidirectionalIterator>
BidirectionalIterator StringWithBackspace::getNextValidChar(
    BidirectionalIterator curr, BidirectionalIterator end) {
    int backspaces = 0;
    while (curr != end) {
        if (*curr == '#') {  // A space is represented by #
            ++backspaces;
        } else if (backspaces > 0) {
            --backspaces;
        } else {
            break;
        }
        ++curr;
    }
    return curr;
}

int shortestWindowSort(const Nums& nums) {
    auto left = nums.begin(), right = std::prev(nums.end());

    // find first out of sequence from left;
    for (auto next = std::next(left); next != nums.end() && *next >= *left;
         ++left, ++next) {
    }

    // Already sorted
    if (left == right) return 0;

    // find first out of sequence from right
    for (auto prev = std::prev(right); prev >= left && *prev <= *right;
         --prev, --right) {
    }

    std::cout << "Left : " << *left << ", Right : " << *right << "\n";
    // We have identified a window but that might not be entirely true
    // find the max and min from the sub array
    auto min = *std::min_element(left, right);
    auto max = *std::min_element(left, right);

    // extend the subarray to include any number bigger than min of sub array
    while (left != nums.begin() && *std::prev(left) > min) {
        --left;
    }

    // extend the subarray to include any number lesser than max of sub array
    while (right != nums.end() && *std::next(right) < max) {
        ++right;
    }
    return std::distance(left, right) + 1;
}
