#include "FactoryPattern.h"
#include "gtest/gtest.h"

TEST(Factory, Simple) {
    Creator *creator  = new ProductACreator();
    auto     productA = creator->create();

    creator       = new ProductBCreator();
    auto productB = creator->create();
    EXPECT_TRUE(true);
}
