#include <vector>

#include "LinkListTemplate.h"
#include "gtest/gtest.h"

TEST(ForwardList, Add) {
    std::vector<int> data{1, 2, 3, 4, 5}, answer;

    ForwardList<int> list;
    for (auto& i : data) {
        list.emplace_back(i);
    }
    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);
}

TEST(ForwardList, Add_Corner) {
    std::vector<int> data, answer;

    ForwardList<int> list;
    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);

    data.emplace_back(1);
    for (auto& i : data) {
        list.emplace_back(i);
    }

    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);
    answer.clear();

    data.emplace_back(2);
    list.emplace_back(2);

    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);
    answer.clear();
}

TEST(ForwardList, Delete) {
    std::vector<int> data, answer;

    ForwardList<int> list;
    list.remove_first();
    list.remove_last();

    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);

    list.emplace_back(1);
    list.remove_last();
    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);

    list.emplace_back(1);
    list.emplace_front(0);
    list.remove_first();
    data.emplace_back(1);
    list.for_each([&answer](const auto& entry) { answer.emplace_back(entry); });
    EXPECT_EQ(data, answer);
}

TEST(ForwardList, Iterator) {
    std::vector<int> data{1, 2, 3, 4, 5}, answer;

    ForwardList<int> list;
    for (auto& i : data) {
        list.emplace_back(i);
    }

    for (auto i = list.begin(); i != list.end(); ++i) {
        answer.emplace_back(i->val);
    }
    EXPECT_EQ(data, answer);

    answer.clear();
    data.pop_back();
    list.remove_last();
    for (auto i = list.begin(); i != list.end(); ++i) {
        answer.emplace_back(i->val);
    }
    EXPECT_EQ(data, answer);
}

TEST(ForwardList, Find) {
    std::vector<int> data{1, 2, 3, 4, 5}, answer;

    ForwardList<int> list;
    for (auto& i : data) {
        list.emplace_back(i);
    }
    auto it = list.find(2);
    EXPECT_NE(it, list.end());
    EXPECT_EQ(it->val, 2);

    it = list.find(4);
    EXPECT_NE(it, list.end());
    EXPECT_EQ(it->val, 4);
}
