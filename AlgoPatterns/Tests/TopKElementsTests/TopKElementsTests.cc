#include "TopKElements.h"
#include "gtest/gtest.h"

TEST(TopKElements, Basic) {
    Nums nums{3, 1, 5, 12, 2, 11};
    Nums expected{5, 12, 11};

    auto ret = findKLargetsNumbers(nums, 3);
    EXPECT_EQ(ret, expected);
}

TEST(KthSmallestElements, Basic) {
    Nums nums{13, 1, 5, 12, 2, 11};

    auto ret = findKthSmallestNumbers(nums, 3);
    EXPECT_EQ(ret, 5);
}

TEST(ClosetPoint, Basic) {
    Points points{
        {1, 3 },
        {3, 4 },
        {2, -1}
    };
    Points expected{
        {1, 3 },
        {2, -1}
    };

    auto ret = findKClosetPointToOrigin(points, 2);
    EXPECT_EQ(ret, expected);
}
