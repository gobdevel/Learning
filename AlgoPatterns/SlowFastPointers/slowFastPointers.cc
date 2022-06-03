#include "slowFastPointers.h"

namespace SlowFastPointers {

bool hasCycle(ListNode *head) {
    if (!head) return false;

    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode *findCycleStart(ListNode *head) {
    if (!head) return head;

    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
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

bool isHappyNumber(int val) {
    auto getSquareSum = [](int data) {
        int sum = 0;
        while (data > 0) {
            auto digit = data % 10;
            sum += (digit * digit);
            data = data / 10;
        }
        return sum;
    };

    int slow = val, fast = val;
    do {
        slow = getSquareSum(slow);                // One hop
        fast = getSquareSum(getSquareSum(fast));  // two hop
    } while (slow != fast);
    return (slow == 1);
}

ListNode *findMiddleOfLinkList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr, *next = nullptr;
    while (head) {
        next       = head->next;
        head->next = prev;
        prev       = head;
        head       = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *mid   = findMiddleOfLinkList(head);
    ListNode *right = reverse(mid);
    ListNode *temp  = right;

    while (head && right) {
        if (head->val != right->val) break;
        head  = head->next;
        right = right->next;
    }
    reverse(temp);
    return (!head || !right);
}

}  // namespace SlowFastPointers
