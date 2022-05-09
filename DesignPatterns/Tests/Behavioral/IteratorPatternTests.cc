#include "IteratorPattern.h"
#include "gtest/gtest.h"

TEST(Iterator, Simple) {
    MyArray<10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto it = arr.begin();

    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);

    while (it != arr.end()) {
        std::cout << *it << ", ";
        ++it;
    }
}
