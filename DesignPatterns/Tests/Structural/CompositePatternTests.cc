#include "CompositePattern.h"
#include "gtest/gtest.h"

using namespace CompositePattern;

TEST(CompositePattern, Simple) {
    Group group(1);

    Circle c1(2), c2(3);

    group.m_objects.emplace_back(&c1);

    Group subgroup(4);
    subgroup.m_objects.emplace_back(&c2);

    group.m_objects.emplace_back(&subgroup);

    Nums expected{1, 2, 4, 3};
    EXPECT_EQ(group.draw(), expected);
}
