#include "LinkListBasic.h"
#include "gtest/gtest.h"

TEST(LinkList, Basic_add) {
    LinkList<int> ll;
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1);
    EXPECT_EQ(ll.getSize(), 1);

    ll.emplace_front(2);
    EXPECT_EQ(ll.getSize(), 2);

    ll.emplace_front(2).emplace_front(3).emplace_back(4);
    EXPECT_EQ(ll.getSize(), 5);
}

TEST(LinkList, Basic_delete) {
    LinkList<int> ll;
    EXPECT_EQ(ll.getSize(), 0);

    ll.delete_back().delete_front();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1).delete_front();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1).delete_back();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_back(1).delete_back();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1).delete_front();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1).emplace_front(2).emplace_back(3).delete_front();
    EXPECT_EQ(ll.getSize(), 2);

    ll.delete_back().delete_back();
    EXPECT_EQ(ll.getSize(), 0);

    ll.emplace_front(1)
        .emplace_front(2)
        .emplace_back(3)
        .delete_front()
        .delete_front()
        .delete_back();
    EXPECT_EQ(ll.getSize(), 0);
}

TEST(LinkList, Add_Delete) {
    LinkList<int> ll;
    ll.emplace_back(1)
        .emplace_back(2)
        .emplace_back(3)
        .delete_back()
        .emplace_back(3);
    auto answer = LinkList<int>::VectorData{1, 2, 3};
    EXPECT_EQ(ll.getVectorData(), answer);

    ll.delete_front().emplace_front(1);
    EXPECT_EQ(ll.getVectorData(), answer);
}
