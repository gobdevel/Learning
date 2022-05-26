#include "flyWeightPattern.h"
#include "gtest/gtest.h"

using namespace FlyWeightPattern;

TEST(FlyWeight, Basic) {
    User user1("Gobind", "Prasad");
    User user2("Gobind", "Prasad");
    User user3("Deepshikha", "Prasad");

    EXPECT_EQ(user1.getFirstname(), user2.getFirstname());
    EXPECT_EQ(user1.getLastname(), user2.getLastname());
    EXPECT_EQ(user1.getLastname(), user3.getLastname());
    EXPECT_NE(user1.getFirstname(), user3.getFirstname());
}
