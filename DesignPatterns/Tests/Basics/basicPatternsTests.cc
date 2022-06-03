#include "basicPatterns.h"
#include "gtest/gtest.h"

TEST(CRTP, Basic) {
    CRTP::Derived1 d1;
    CRTP::Derived2 d2;

    CRTP::print(d1);
    CRTP::print(d2);

    EXPECT_TRUE(true);
}

TEST(MIXIN, Basic) {
    Mixin::Foo<Mixin::Bar<Mixin::Baz>> x;

    // Now X variable is composed of Foo, Bar, Baz classes
    x.foo();
    x.bar();
    x.baz();

    EXPECT_TRUE(true);
}
