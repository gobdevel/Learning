#include "HashMap.h"
#include "gtest/gtest.h"
#include "utils.h"

TEST(HASH, Basic) {
    HashMap<int, int> h;
    h.insert(10, 100);
    h.insert(20, 200);
    h.insert(100, 1000);
    EXPECT_EQ(h.size(), 3);
    h.remove(20);
    EXPECT_EQ(h.size(), 2);
    EXPECT_EQ(h[100], 1000);
}

TEST(HASH, Collision) {
    HashMap<int, int> h;
    h.insert(10, 10);
    h.insert(100, 100);
    h.insert(1000, 1000);
    h.insert(10000, 10000);
    h.insert(100000, 100000);
    EXPECT_EQ(h.size(), 5);
    h.remove(100);
    h.remove(1000);
    h.remove(10000);
    h.remove(100000);
    EXPECT_EQ(h.size(), 1);
    h.remove(100000);
    EXPECT_EQ(h.size(), 1);
}

TEST(HASH, WithClass) {
    struct A {
        A(int&& a, std::string&& n) : a(std::move(a)), name(std::move(n)) {}
        int         a;
        std::string name;
    };
    HashMap<int, A> h;
    h.insert(10, A(10, "Gobind"));
    EXPECT_EQ(h[10].name, "Gobind");
}
