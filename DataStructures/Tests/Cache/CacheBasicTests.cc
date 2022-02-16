#include "Cache.h"
#include "gtest/gtest.h"

TEST(Cache, Basic) {
    LRUCache<int, int> cache{5};
    EXPECT_FALSE(cache.get(5).first);

    EXPECT_EQ(cache.insert(1, 10), std::error_code());
    EXPECT_TRUE(cache.get(1).first);

    cache.insert(2, 20);
    cache.insert(3, 20);
    cache.insert(4, 20);
    cache.insert(5, 20);
    cache.insert(6, 20);

    EXPECT_FALSE(cache.get(1).first);
    EXPECT_TRUE(cache.get(2).first);
    cache.insert(7, 20);
    EXPECT_FALSE(cache.get(3).first);
}
