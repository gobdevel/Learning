#include "ObserverPattern.h"
#include "gtest/gtest.h"

TEST(Observer, Simple) {
    Student p(20);

    TestPersonObserver tpo;
    p.subscribe(&tpo);
    p.setAge(21);
    p.setAge(23);
    EXPECT_TRUE(true);
}
