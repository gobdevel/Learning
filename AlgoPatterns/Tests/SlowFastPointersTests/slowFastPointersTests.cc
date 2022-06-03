#include "gtest/gtest.h"
#include "slowFastPointers.h"

using namespace SlowFastPointers;

TEST(SlowFastPointers, DetectCycle) {
    EXPECT_FALSE(hasCycle(nullptr));

    ListNode *head = new ListNode(1);
    EXPECT_FALSE(hasCycle(head));
    head->next = new ListNode(2);
    EXPECT_FALSE(hasCycle(head));
    head->next->next = new ListNode(3);
    EXPECT_FALSE(hasCycle(head));
    head->next->next->next             = new ListNode(4);
    head->next->next->next->next       = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    EXPECT_FALSE(hasCycle(head));
    head->next->next->next->next->next->next = head->next->next;
    EXPECT_TRUE(hasCycle(head));
}

TEST(SlowFastPointers, FindCycleStart) {
    ListNode *head                           = new ListNode(1);
    head->next                               = new ListNode(2);
    head->next->next                         = new ListNode(3);
    head->next->next->next                   = new ListNode(4);
    head->next->next->next->next             = new ListNode(5);
    head->next->next->next->next->next       = new ListNode(6);
    head->next->next->next->next->next->next = head->next->next;

    EXPECT_EQ(findCycleStart(head), head->next->next);
}

TEST(SlowFastPointers, HappyNumber) {
    EXPECT_TRUE(isHappyNumber(23));
    EXPECT_FALSE(isHappyNumber(12));
}

TEST(SlowFastPointers, MiddleOfLinkList) {
    EXPECT_FALSE(findMiddleOfLinkList(nullptr));
    ListNode *head = new ListNode(1);
    EXPECT_EQ(findMiddleOfLinkList(head), head);
    head->next = new ListNode(2);
    EXPECT_EQ(findMiddleOfLinkList(head), head->next);
    head->next->next = new ListNode(3);
    EXPECT_EQ(findMiddleOfLinkList(head), head->next);
    head->next->next->next = new ListNode(4);
    EXPECT_EQ(findMiddleOfLinkList(head), head->next->next);
    head->next->next->next->next = new ListNode(5);
    EXPECT_EQ(findMiddleOfLinkList(head), head->next->next);
    head->next->next->next->next->next = new ListNode(6);
    EXPECT_EQ(findMiddleOfLinkList(head), head->next->next->next);
}

TEST(SlowFastPointers, PalindromeLinkList) {
    ListNode *head               = new ListNode(2);
    head->next                   = new ListNode(4);
    head->next->next             = new ListNode(6);
    head->next->next->next       = new ListNode(4);
    head->next->next->next->next = new ListNode(2);

    EXPECT_TRUE(isPalindrome(head));
    head->next->next->next->next = new ListNode(1);
    EXPECT_FALSE(isPalindrome(head));
}

TEST(SlowFastPointers, CircularArrayLoop) {
    Nums nums{1, 2, -1, 2, 2};
    EXPECT_TRUE(CircularArrayLoop::isLoopExists(nums));

    nums = {2, 2, -1, 2};
    EXPECT_TRUE(CircularArrayLoop::isLoopExists(nums));

    nums = {2, 1, -1, 2};
    EXPECT_FALSE(CircularArrayLoop::isLoopExists(nums));
}
