#include "BridgePattern.h"
#include "gtest/gtest.h"

using namespace BridgePattern;

TEST(BridgePattern, Basic) {
    DrawingApi_1 api1;
    DrawingApi_2 api2;

    Circle c1(&api1);
    EXPECT_EQ(c1.draw(), 1);

    Circle c2(&api2);
    EXPECT_EQ(c2.draw(), 2);
}
