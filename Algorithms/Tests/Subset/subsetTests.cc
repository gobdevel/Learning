#include "Subset.h"
#include "gtest/gtest.h"

TEST(Subset, Basic) {
    Input nums{1, 3, 5};
    auto  ret = getAllSubset(nums);
    EXPECT_EQ(ret.size(), 8);
}

TEST(Subset, HandleDuplicate) {
    Input nums{1, 3, 3};
    auto  ret = getAllSubsetHandleDuplicate(nums);
    EXPECT_EQ(ret.size(), 6);

    Input nums1{1, 5, 3, 3};
    auto  ret1 = getAllSubsetHandleDuplicate(nums1);
    EXPECT_EQ(ret1.size(), 12);
}
