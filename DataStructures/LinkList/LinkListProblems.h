#ifndef __LINKLIST_PROBLEM_H__
#define __LINKLIST_PROBLEM_H__
#include "LinkListBasic.h"

using ListNode = Node<int>;

template <typename T>
Node<T>* reverse(Node<T>* head) {
    Node<T>*prev = nullptr, *next = nullptr;
    while (head) {
        next       = head->next;
        head->next = prev;
        prev       = head;
        head       = next;
    }
    return prev;
}

/**
 * Given head which is a reference node to a singly-linked list. The value of
 * each node in the linked list is either 0 or 1. The linked list holds the
 * binary representation of a number.
 * Return the decimal value of the number in the linked list.
 * Ex : 1 0 1 1 = 11;

 Constraints:

    The Linked List is not empty.
    Number of nodes will not exceed 30.
    Each node's value is either 0 or 1.

*/

static int getDecimalValue(ListNode* head) {
    int num = head->val;
    while (head->next) {
        num  = num * 2 + head->next->val;
        head = head->next;
    }
    return num;
}

/**
 * Given the head of a singly linked list, return the middle node of the linked
list.
 * If there are two middle nodes, return the second middle node.
 * Ex :  [1,2,3,4,5] = node 3, [3, 4, 5]
Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
*/
static ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
Write a function to delete a node in a singly-linked list. You will not be given
access to the head of the list, instead you will be given access to the node to
be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.

Ex : [4, 5, 1, 9], 5 = [4, 1, 9]

Constraints:

    The number of the nodes in the given list is in the range [2, 1000].
    -1000 <= Node.val <= 1000
    The value of each node in the list is unique.
    The node to be deleted is in the list and is not a tail node
*/
static void deleteNode(ListNode* node) {
    while (node->next->next) {
        std::swap(node->val, node->next->val);
        node = node->next;
    }
    std::swap(node->val, node->next->val);
    delete (node->next);
    node->next = nullptr;
}

/**
Given the head of a singly linked list, reverse the list, and return the
reversed list. Ex : [1,2,3,4,5] = [5,4,3,2,1]
*/
static ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *next = nullptr;
    while (head) {
        next       = head->next;
        head->next = prev;
        prev       = head;
        head       = next;
    }
    return prev;
}

/**
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

Ex : list1 = [1,2,4], list2 = [1,3,4] = res = [1,1,2,3,4,4]
*/

static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode  dummy(0);
    ListNode* res = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            res->next = list1;
            list1     = list1->next;
        } else {
            res->next = list2;
            list2     = list2->next;
        }
        res = res->next;
    }

    res->next = list1 ? list1 : list2;
    return dummy.next;
}

/**
Given head, the head of a linked list, determine if the linked list has a cycle
in it.
*/
static bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

/**
Given the head of a linked list, return the node where the cycle begins. If
there is no cycle, return null.
*/
static ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

/**
Given the head of a linked list and an integer val, remove all the nodes of the
linked list that has Node.val == val, and return the new head. Ex : Input: head
= [1,2,6,3,4,5,6], val = 6 Output: [1,2,3,4,5] Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50
*/
static ListNode* removeElements(ListNode* head, int val) {
    ListNode  dummy(0, head);
    ListNode* curr = &dummy;

    while (curr->next) {
        if (curr->next->val == val) {
            auto toDel = curr->next;
            curr->next = curr->next->next;
            delete (toDel);
        } else {
            curr = curr->next;  // Note this
        }
    }
    return dummy.next;
}

/**
Merge Nodes in Between Zeros
You are given the head of a linked list, which contains a series of integers
separated by 0's. The beginning and end of the linked list will have Node.val ==
0.

For every two consecutive 0's, merge all the nodes lying in between them into a
single node whose value is the sum of all the merged nodes. The modified list
should not contain any 0's.

Return the head of the modified linked list.

Ex : Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Constraints:

    The number of nodes in the list is in the range [3, 2 * 105].
    0 <= Node.val <= 1000
    There are no two consecutive nodes with Node.val == 0.
    The beginning and end of the linked list have Node.val == 0.
*/

static ListNode* mergeNodes(ListNode* head) {
    ListNode *curr = head, *newHead = head;
    head = head->next;
    while (head) {
        if (head->val != 0) {
            curr->val += head->val;
        } else {
            curr->next = head->next ? head : nullptr;
            curr       = head;
        }

        head = head->next;
    }

    return newHead;
}

/**
Swapping Nodes in a Linked List
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node
from the beginning and the kth node from the end (the list is 1-indexed).

Ex : Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 105
    0 <= Node.val <= 100
*/

static ListNode* swapNodes(ListNode* head, int k) {
    int       count = 1;
    ListNode *first = head, *second = head, *curr = head;
    while (curr && curr->next && count < k) {
        curr = curr->next;
        ++count;
    }
    first = curr;

    while (curr && curr->next) {
        curr   = curr->next;
        second = second->next;
    }

    std::swap(first->val, second->val);
    return head;
}

/**
Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices
together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain
as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time
complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Constraints:

    n == number of nodes in the linked list
    0 <= n <= 104
    -106 <= Node.val <= 106
*/
static ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *odd = head, *even = head->next, *newHead = odd, *ev = even;
    int       count = 1;
    head            = head->next->next;
    while (head) {
        if (count % 2 == 0) {
            even->next = head;
            even       = even->next;
        } else {
            odd->next = head;
            odd       = odd->next;
        }
        head = head->next;
        ++count;
    }

    if (even) {
        even->next = nullptr;
    }
    odd->next = ev;
    return newHead;
}

/**
Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must
solve the problem without modifying the values in the list's nodes (i.e., only
nodes themselves may be changed.)

Input: head = [1,2,3,4]
Output: [2,1,4,3]

                                                                                                                                                Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
*/
static ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    auto res = swapPairs(head->next->next);

    auto newHead     = head->next;
    head->next->next = head;

    head->next = res;
    return newHead;
}

/**
Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the
head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start
using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal
to x.

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Constraints:

    The number of nodes in the list is in the range [1, 105].
    1 <= Node.val <= 105
*/
static ListNode* deleteMiddle(ListNode* head) {
    ListNode  dummy(0, head);
    ListNode *curr = &dummy, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        curr = curr->next;
    }

    auto toDel = curr->next;
    curr->next = curr->next->next;
    delete (toDel);

    return dummy.next;
}

/**
Partition List
Given the head of a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200
*/
static ListNode* partition(ListNode* head, int x) {
    ListNode  dummyLeft(0), dummyRight(0);
    ListNode *left = &dummyLeft, *right = &dummyRight;

    while (head) {
        if (head->val < x) {
            left->next = head;
            left       = left->next;
        } else {
            right->next = head;
            right       = right->next;
        }
        head = head->next;
    }

    if (right->next) {
        right->next = nullptr;
    }

    left->next = dummyRight.next;
    return dummyLeft.next;
}

/**
Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in
ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 10^4
*/
static ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
    ListNode  dummy(0);
    ListNode* prev = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1         = l1->next;
        } else {
            prev->next = l2;
            l2         = l2->next;
        }
        prev = prev->next;
    }

    prev->next = l1 ? l1 : l2;
    return dummy.next;
}

static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    int start = 0, end = lists.size() - 1;
    if (end < 0) return nullptr;

    while (end > 0) {
        lists[start] = mergeSortedList(lists[start], lists[end]);
        ++start;
        --end;
        if (start >= end) {
            start = 0;
        }
    }
    return lists[0];
}

#endif
