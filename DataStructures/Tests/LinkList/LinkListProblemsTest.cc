#include "LinkListProblems.h"
#include "gtest/gtest.h"

TEST(LinkList_Problems, Reverse) {
    LinkList<int> ll;
    ll.emplace_front(5)
        .emplace_front(4)
        .emplace_front(3)
        .emplace_front(2)
        .emplace_front(1);
    auto answer = LinkList<int>::VectorData{5, 4, 3, 2, 1};
    ll.setHead(reverse(ll.getHead()));
    EXPECT_EQ(ll.getVectorData(), answer);
}
