#ifndef __BINARY_SEARCH_BASICS_H__
#define __BINARY_SEARCH_BASICS_H__

#include <iostream>
#include <vector>

/*
 * Type :  Basic Binary Search Template - 1
 * Desc :  Template #1 is used to search for an element or condition which can
 *         be determined by accessing a single index in the array.
 * Note :  At the end of loop, 'start' will have last index of success condition
 *         and 'end' at invalidate index
 *
 *
 * Template #1 (left <= right):
 *
 *  1. Most basic and elementary form of Binary Search
 *  2. Search Condition can be determined without comparing to the element's
 *     neighbors.(or use specific elements around it)
 *  3. No post-processing required because at each step, you are checking to see
 *     if the element has been found. If you reach the end, then you know the
 *     element is not found
 */

inline int BinarySearchTemplate1(std::vector<int>& nums, int target) {
    int size = nums.size(), start = 0, end = size - 1;

    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            // Element found return
            return mid;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    // std::cout << "Not Found : " << target << ", ( start : " << start
    //           << ", end : " << end << ") \n";
    return -1;
}

/*
 * Type :  Basic Binary Search Template - 2
 * Desc :  Template #2 is an advanced form of Binary Search. It is used to
 *         search for an element or condition which requires accessing the
 *         current index and its immediate right neighbor's index in the array.
 *
 *        Template #2 (left < right): right = size
 *  1. An advanced way to implement Binary Search.
 *  2. Search Condition needs to access the element's immediate right neighbor
 *  3. Use the element's right neighbor to determine if the condition is met and
 *     decide whether to go left or right
 *  4. Guarantees Search Space is at least 2 in size at each step
 *  5. Post-processing required. Loop/Recursion ends when you have 1 element
 *     left. Need to assess if the remaining element meets the condition.
 */

inline int BinarySearchTemplate2(std::vector<int>& nums, int target) {
    int size = nums.size(), start = 0, end = size;  // Note end == size

    while (start < end) {  // Note this changed here
        auto mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            // Element found return
            return mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    //  At the end, start && end will be at either 0 or end of array
    // std::cout << "Not Found : " << target << ", ( start : " << start
    //          << ", end : " << end << ") \n";

    // Post-processing:
    // End Condition: start == right
    if (start != size && nums[start] == target) return start;
    return -1;
}

/*
 * Type :  Basic Binary Search Template - 3
 * Desc :  It is used to search for an element or condition which requires
 *         accessing the current index and its immediate left and right
 *         neighbor's index in the array.
 *
 *     Template #3 (left + 1 < right): end = size - 1
 *
 *    1. An alternative way to implement Binary Search
 *    2. Search Condition needs to access element's immediate left and right
 *       neighbors.
 *    3. Use element's neighbors to determine if the condition is met and
 *       decide whether to go left or right.
 *    4. Guarantees Search Space is at least 3 in size at each step
 *    5. Post-processing required. Loop/Recursion ends when you have 2 elements
 *       left. Need to assess if the remaining elements meet the condition.
 *
 */

inline int BinarySearchTemplate3(std::vector<int>& nums, int target) {
    int size = nums.size(), start = 0, end = size - 1;  // Note end == size
    if (size == 0) return -1;

    while (start + 1 < end) {  // Note this changed here
        auto mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            // Element found return
            return mid;
        } else if (nums[mid] > target) {  // search space selection
            end = mid;
        } else {
            start = mid;
        }
    }
    //  At the end, start && end will be at either 0 & 1 or end-1 & end of array
    // std::cout << "Not Found : " << target << ", ( start : " << start
    //          << ", end : " << end << ") \n";

    // Post-processing:
    // End Condition: start + 1 == end
    if (nums[start] == target) return start;
    if (nums[end] == target) return end;
    return -1;
}
#endif
