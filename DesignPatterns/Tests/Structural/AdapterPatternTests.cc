#include "AdapterPattern.h"
#include "gtest/gtest.h"

TEST(Adapter, Basic) {
    EuSocketInterface *eu = new EuSocket();

    UsSocketAdapter *us = new UsSocketAdapter();
    us->plugin(eu);

    ElectricKettle kettle;
    kettle.plugin(us);

    EXPECT_EQ(kettle.boil(), 0);
}
