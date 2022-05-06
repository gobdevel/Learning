#include "KWayMerge.h"
#include "gtest/gtest.h"

TEST(KWayMerge, LinkList) {
    IntLinkList list1, list2, list3;
    list1.emplace_back(2).emplace_back(6).emplace_back(8);
    list2.emplace_back(3).emplace_back(6).emplace_back(7);
    list3.emplace_back(1).emplace_back(3).emplace_back(4);

    IntLinkLists lists{list1.getHead(), list2.getHead(), list3.getHead()};

    std::vector<int> expected{1, 2, 3, 3, 4, 6, 6, 7, 8};

    auto res = mergeKLinkList(lists);
    auto ret = convertLinkListToVector(res);
    EXPECT_EQ(ret, expected);
}

TEST(KWayMerge, KSmallestInVector) {
    Nums     list1{2, 6, 8}, list2{3, 6, 7}, list3{1, 3, 4};
    ListNums lists{list1, list2, list3};

    auto res = findKthSmallestFromListOfNumbers(lists, 5);
    EXPECT_EQ(res, 4);

    auto res1 = findKthSmallestFromListOfNumbers(lists, 1);
    EXPECT_EQ(res1, 1);

    auto res2 = findKthSmallestFromListOfNumbers(lists, 3);
    EXPECT_EQ(res2, 3);

    auto res3 = findKthSmallestFromListOfNumbers(lists, 4);
    EXPECT_EQ(res3, 3);
}

TEST(KWayMerge, SmallestNumberRange) {
    Nums     list1{1, 5, 8}, list2{4, 12}, list3{7, 8, 10};
    ListNums lists{list1, list2, list3};

    std::pair<int, int> expected{4, 7};

    auto res = findSmallestNumberRange(lists);

    EXPECT_EQ(res, expected);
}
