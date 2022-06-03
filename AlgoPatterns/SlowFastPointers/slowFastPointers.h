#ifndef __SLOW_FAST_POINTERS_H__
#define __SLOW_FAST_POINTERS_H__

#include "utils.h"
namespace SlowFastPointers {

struct ListNode {
    ListNode(int v) : val(v) {}
    int       val{0};
    ListNode* next{nullptr};
};

bool      hasCycle(ListNode* head);
ListNode* findCycleStart(ListNode* head);
ListNode* findMiddleOfLinkList(ListNode* head);
bool      isHappyNumber(int val);
bool      isPalindrome(ListNode* head);

class CircularArrayLoop {
public:
    static bool isLoopExists(const Nums& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            bool isForward = (nums[i] > 0);
            int  slow = i, fast = i;

            do {
                slow = findNextIndex(nums, isForward, slow);  // 1 move
                fast = findNextIndex(nums, isForward, fast);  // 1 move
                if (fast != -1) {
                    fast =
                        findNextIndex(nums, isForward, fast);  // another move
                }
            } while (slow != -1 && fast != -1 && slow != fast);

            if (slow != -1 && slow == fast) return true;
        }
        return false;
    }

private:
    static int findNextIndex(const Nums& nums, bool isForward, int currIndex) {
        bool direction = (nums[currIndex] > 0);
        // direction changed no loop;
        if (direction != isForward) return -1;
        auto nextIndex =
            (currIndex + nums[currIndex] + nums.size()) % nums.size();

        // Single element loop
        if (nextIndex == currIndex) {
            return -1;
        }
        return nextIndex;
    }
};
}  // namespace SlowFastPointers

#endif
