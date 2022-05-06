#ifndef __K_WAY_MERGE_H__
#define __K_WAY_MERGE_H__
#include <limits>
#include <queue>

#include "LinkListBasic.h"
#include "utils.h"

using IntLinkList  = LinkList<int>;
using IntNode      = Node<int>;
using IntLinkLists = std::vector<IntNode*>;

struct NodeCompare {
    bool operator()(IntNode* a, IntNode* b) { return a->val > b->val; }
};

static IntNode* mergeKLinkList(const IntLinkLists& lists) {
    std::priority_queue<IntNode*, IntLinkLists, NodeCompare> minHeap;

    // Push top elements from all lists
    for (auto root : lists) {
        minHeap.push(root);
    }

    IntNode *head = nullptr, *tail = nullptr;
    while (!minHeap.empty()) {
        // Grab top (min) element from heap
        auto node = minHeap.top();
        minHeap.pop();

        // If first node, store head pointer to return.
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail       = tail->next;
        }

        // if current min node's list is not empty
        if (node->next != nullptr) {
            minHeap.push(node->next);
        }
    }
    return head;
}

// stores list id and index within this list
using ListIndex  = std::pair<int, int>;
using ValueIndex = std::pair<int, ListIndex>;

struct ComparePairNode {
    bool operator()(const ValueIndex& x, const ValueIndex& y) {
        return x.first > y.first;
    }
};

static int findKthSmallestFromListOfNumbers(const ListNums& lists, int k) {
    std::priority_queue<ValueIndex, std::vector<ValueIndex>, ComparePairNode>
        minHeap;

    // Add first element from each list with its index in the corresponding list
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            minHeap.emplace(std::make_pair(lists[i][0], std::make_pair(i, 0)));
        }
    }

    // Iterate through remaining elements in lists till K
    for (int i = 1; i < k; ++i) {
        auto node = std::move(minHeap.top());
        minHeap.pop();

        auto listIndex = node.second.first;
        auto index     = node.second.second;
        // Validate this list has reached its end
        if (index < lists[listIndex].size()) {
            ++index;
            minHeap.emplace(std::make_pair(lists[listIndex][index],
                                           std::make_pair(listIndex, index)));
        }
    }
    return minHeap.top().first;
}

static std::pair<int, int> findSmallestNumberRange(const ListNums& lists) {
    std::priority_queue<ValueIndex, std::vector<ValueIndex>, ComparePairNode>
        minHeap;

    int startRange = 0, endRange = std::numeric_limits<int>::max();
    int currentMaxNumber = std::numeric_limits<int>::min();

    // Add first element from each list with its index in the corresponding list
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            minHeap.emplace(std::make_pair(lists[i][0], std::make_pair(i, 0)));
            currentMaxNumber = std::max(currentMaxNumber, lists[i][0]);
        }
    }

    while (minHeap.size() == lists.size()) {
        auto node = std::move(minHeap.top());
        minHeap.pop();

        // adjust range
        if (endRange - startRange > currentMaxNumber - node.first) {
            startRange = node.first;
            endRange   = currentMaxNumber;
        }

        auto listIndex = node.second.first;
        auto index     = node.second.second;
        // Validate this list has reached its end
        if (index < lists[listIndex].size()) {
            ++index;
            minHeap.emplace(std::make_pair(lists[listIndex][index],
                                           std::make_pair(listIndex, index)));
            currentMaxNumber =
                std::max(currentMaxNumber, lists[listIndex][index]);
        }
    }
    return std::make_pair(startRange, endRange);
}
#endif
