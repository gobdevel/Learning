#ifndef __BINARY_SEARCH_PROBLEMS_H__
#define __BINARY_SEARCH_PROBLEMS_H__

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

/**
 Problem : Find first position of an element in a sorted array ?
 *         Using Template - 1
 */
inline int BinarySearchLeftElement(std::vector<int>& nums, int target) {
    int size = nums.size(), start = 0, end = size - 1;
    if (size == 0) return -1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] >= target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return (nums[start] == target ? start : -1);
}

/**
 Problem : Find last position of an element in a sorted array ?
 *         Using Template - 1
 */
inline int BinarySearchRightElement(std::vector<int>& nums, int target) {
    int size = nums.size(), start = 0, end = size - 1;
    if (size == 0) return -1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] <= target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return (nums[end] == target ? end : -1);
}

/*
Problem : Write an efficient algorithm that searches for a value target in an
          m x n integer matrix matrix. This matrix has the following properties:

          > Integers in each row are sorted from left to right.
          > The first integer of each row is greater than the last integer of

            {4,  5,  6,  7,  8,  9 },
            {10, 11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20, 21}
*/
inline bool searchInSortedMatrix(Matrix& matrix, int target) {
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

/*
Problem : Write an efficient algorithm that searches for a value target in an
          m x n integer matrix matrix. This matrix has the following properties:

          > Integers in each row are sorted in ascending from left to right.
          > Integers in each column are sorted in ascending from top to bottom.

              {1,  4,  7,  11, 15},
              {2,  5,  8,  12, 19},
              {3,  6,  9,  16, 22},
              {10, 13, 14, 17, 24},
              {18, 21, 23, 26, 30}
*/
inline bool searchInSortedRowSortedColMatrix(Matrix& matrix, int target) {
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

#endif

/**
int main() {
    std::vector<int> nums{1, 1, 2, 6, 6, 6, 7, 9, 12, 24, 25, 25};

    Matrix matrix = {
        {4, 5, 6, 7, 8, 9}, {10, 11, 12, 13, 14, 15}, {16, 17, 18, 19, 20, 21}};

    Matrix matrix2 = {{1, 4, 7, 11, 15},
                      {2, 5, 8, 12, 19},
                      {3, 6, 9, 16, 22},
                      {10, 13, 14, 17, 24},
                      {18, 21, 23, 26, 30}};

    std::cout << "Matrix Search 5 : " << searchInSortedMatrix(matrix, 5)
              << "\n";
    std::cout << "Matrix Search 2 : " << searchInSortedMatrix(matrix, 2)
              << "\n";

    std::cout << "Matrix Search 5 : "
              << searchInSortedRowSortedColMatrix(matrix2, 5) << "\n";
    std::cout << "Matrix Search 26 : "
              << searchInSortedRowSortedColMatrix(matrix2, 26) << "\n";
    return 0;
}
*/
