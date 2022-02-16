#ifndef __TWO_POINTERS_H__
#define __TWO_POINTERS_H__

#include <iostream>

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/******************************************************************************
 *       TWO POINTER TECHNIQUES
 ******************************************************************************/

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return nullptr;

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
 * Intersection of Two Linked Lists
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *currA = headA, *currB = headB;

    while (currA != currB) {
        currA = currA ? currA->next : headB;
        currB = currB ? currB->next : headA;
    }
    return currA;
}

/**
 * Remove Nth Node From End of Lists
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0, head);

    ListNode *slow = &dummy, *fast = &dummy;
    while (n > 0) {
        fast = fast->next;
        --n;
    }

    while (fast && fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    auto toDel = slow->next;
    slow->next = slow->next->next;
    delete (toDel);
    return dummy.next;
}

ListNode *reverseList(ListNode *head) {
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
 * Remove Linked List Elements
 * Given the head of a linked list and an integer val, remove all the nodes of
 * the linked list that has Node.val == val, and return the new head.
 */
ListNode *removeElements(ListNode *head, int val) {
    ListNode  dummy(0, head);
    ListNode *prev = &dummy;

    while (head) {
        if (head->val == val) {
            prev->next = head->next;
            delete head;
            head = prev->next;
        } else {
            prev = head;
            head = head->next;
        }
    }
    return dummy.next;
}

/**
 * Odd Even Linked List
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list. The first node is considered odd, and the second node is even, and so
 * on.
 *
 */
ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *odd = head, *even = head->next, *evenStart = head->next;
    while (odd->next && even->next) {
        odd->next  = even->next;
        odd        = odd->next;
        even->next = odd->next;
        even       = even->next;
    }
    odd->next = evenStart;
    return head;
}

ListNode *reverse(ListNode *head) {
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
 * Palindrome Linked List
 * Given the head of a singly linked list, return true if it is a palindrome.
 */
bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);
    while (head && slow) {
        if (head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

// Swap Nodes in pairs
ListNode *swapPairs(ListNode *head) {
    if (head && head->next) {
        ListNode *res     = swapPairs(head->next->next);
        ListNode *newHead = head->next;
        newHead->next     = head;
        head->next        = res;
        return newHead;
    }
    return head;
}

#endif
