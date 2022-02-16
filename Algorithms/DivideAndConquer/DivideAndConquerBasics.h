#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

#include <algorithm>
#include <iostream>
#include <vector>
/**
 *     DIVIDE AND CONQUER WITH RECURSION
 *
 *  1. Divide. Divide the problem S into a set of subproblems:
 *     {S1,S2,...Sn} where n ≥ 2 i.e. there are usually more than one
 *     subproblem.
 *
 *  2. Conquer. Solve each subproblem recursively.
 *
 *  3. Combine. Combine the results of each subproblem.
 */

/**
 *    MERGE SORT USING DIVIDE & CONQUER WITH RECURSION
 *
 * 1. In the first step, we divide the list into two sublists.  (Divide)
 * 2. Then in the next step, we recursively sort the sublists in the previous
 *    step.  (Conquer)
 * 3. Finally we merge the sorted sublists in the above step repeatedly to
 *    obtain the final list of sorted elements.  (Combine)
 *
 */

template <typename RandomAccessIterator>
void MergeSort(RandomAccessIterator start, RandomAccessIterator end) {
    auto length = std::distance(start, end);
    if (length > 1) {
        auto mid = start + (length / 2);
        MergeSort(start, mid);
        MergeSort(mid, end);
        std::inplace_merge(start, mid, end);
    }
}

/**
 *  VALIDATE BINARY SEARCH TREE
 *
 * 1. In the first step, we divide the tree into two subtrees -- its left child
 *    and right child.  (Divide)
 *
 * 2. Then in the next step, we recursively validate each subtree is indeed a
 *    binary search tree.  (Conquer)
 *
 * 3. Upon the results of the subproblems from Step 2, we return true if and
 *    only if both subtrees are both valid BST.  (Combine)
 */

struct TreeNode {
    int       val   = {0};
    TreeNode *left  = {nullptr};
    TreeNode *right = {nullptr};
};

bool isValidBstHelper(TreeNode *node, long min, long max) {
    if (node) {
        return (node->val > min && node->val < max) &&
               isValidBstHelper(node->left, min, node->val) &&
               isValidBstHelper(node->right, node->val, max);
    }
    return true;
}

bool isValidBst(TreeNode *root) {
    return isValidBstHelper(root, LONG_MIN, LONG_MAX);
}

template <typename RandomAccessIterator>
void QuickSort(RandomAccessIterator start, RandomAccessIterator end) {
    if (start != end) {
        auto &pivot = *std::next(start, std::distance(start, end) / 2);
        auto  mid1  = std::partition(start, end, [&pivot](const auto &element) {
            return (element < pivot);
          });
        auto  mid2  = std::partition(start, end, [&pivot](const auto &element) {
            return !(pivot < element);
          });
        QuickSort(start, mid1);
        QuickSort(mid2, end);
    }
}

#endif

/**
 *  DRIVER CODE
 */
/**
int main(int argc, char *argv[]) {
    std::vector<int> nums{3, 2, 6, 1, 7, 4, 0, 12};
    QuickSort(std::begin(nums), std::end(nums));

    for (const auto &i : nums) {
        std::cout << i << ", ";
    }
    std::cout << "\n";
    return 0;
}
*/
