#include "BinarySearch.h"

int binarySearch(const Nums& nums, Num key) {
    if (nums.empty()) return -1;

    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int binarySearchOrderedAgnostic(const Nums& nums, Num key) {
    if (nums.empty()) return -1;

    int  start = 0, end = nums.size() - 1;
    bool isAcending = nums[end] > nums[start];

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] == key)
            return mid;
        else {
            if (isAcending) {  // Ascending ordered
                if (nums[mid] > key) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {  // Descending ordered
                if (nums[mid] > key) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    }
    return -1;
}

int binarySearchFindCeiling(const Nums& nums, Num key) {
    if (nums.empty()) return -1;

    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return (start < nums.size() ? start : -1);
}

char binarySearchNextLetter(std::string& str, char key) {
    if (str.empty()) return 0;

    int start = 0, end = str.length() - 1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (str[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return (str[start % str.length()]);
}

int search(const Nums& nums, Num key, bool ceil) {
    int start = 0, end = nums.size() - 1, keyIndex = -1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] > key) {
            end = mid - 1;
        } else if (nums[mid] < key) {
            start = mid + 1;
        } else {
            keyIndex = mid;
            if (ceil) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return keyIndex;
}

NumRange binarySearchGetNumberRange(const Nums& nums, Num key) {
    auto left  = search(nums, key, false);
    int  right = -1;
    if (left != -1) {
        right = search(nums, key, true);
    }
    return std::make_pair(left, right);
}

int binarySearchUnknownSize(const Nums& nums, Num key) {
    int start = 0, end = 1;

    while (start <= end) {
        if (key > nums[end]) {
            int newStart = end + 1;
            end += (end - start + 1) * 2;
            start = newStart;
        } else {
            auto mid = start + (end - start) / 2;
            if (nums[mid] == key)
                return mid;
            else if (nums[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}

Num binarySearchMinDistance(const Nums& nums, Num key) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;

        if (nums[mid] == key)
            return key;
        else if (nums[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (start < nums.size() && end >= 0) {
        return std::min(nums[start], nums[end]);
    } else {
        return (end < 0 ? nums[start] : nums[end]);
    }
}

Num binarySearchBitonicArrayMax(const Nums& nums) {
    int start = 0, end = nums.size() - 1;

    while (start < end) {  // important for mid+1 validity
        auto mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid + 1]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int binarySearchBitonicArray(const Nums& nums, Num key) {
    auto orderedAgnosticBs = [&](int start, int end, Num key) {
        bool isAcending = nums[start] < nums[end];

        while (start <= end) {
            auto mid = start + (end - start) / 2;

            if (nums[mid] == key) return mid;

            if (isAcending) {
                if (nums[mid] > key) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] > key) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    };
    int  maxIndex = binarySearchBitonicArrayMax(nums);
    auto res      = orderedAgnosticBs(0, maxIndex, key);
    if (res != -1) return res;
    return orderedAgnosticBs(maxIndex + 1, nums.size() - 1, key);
}

int binarySearchRotatedSortedArray(const Nums& nums, Num key) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] == key) {
            return mid;
        }

        if (nums[start] <= nums[mid]) {  // left is sorted
            if (key >= nums[start] && key < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {  // right is sorted
            if (key > nums[mid] && key <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int binarySearchRotationCount(const Nums& nums) {
    int start = 0, end = nums.size() - 1;
    while (start < end) {
        auto mid = start + (end - start) / 2;

        if (mid < end && nums[mid] > nums[mid + 1]) return mid + 1;
        if (mid > start && nums[mid - 1] > nums[mid]) return mid;

        if (nums[start] < nums[mid]) {  // left is sorted
            start = mid + 1;
        } else {  // right is sorted
            end = mid - 1;
        }
    }
    return -1;
}

bool binarySearchSortedMatrix(NumMatrix& matrix, int target) {
    if (matrix.size() == 0) return false;

    int start = 0, col = matrix[0].size(), end = (matrix.size() * col) - 1;
    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (matrix[mid / col][mid % col] == target) {
            return true;
        } else if (matrix[mid / col][mid % col] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}

bool binarySearchSortedRowSortedColMatrix(NumMatrix& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            --col;
        } else {
            ++row;
        }
    }
    return false;
}
