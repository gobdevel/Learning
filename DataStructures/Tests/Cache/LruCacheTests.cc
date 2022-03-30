#include "LruCache.h"
#include "gtest/gtest.h"

TEST(LruCache, Basic) {
    LruCache<int, int> cache(5);
    EXPECT_FALSE(cache.get(5).first);

    EXPECT_EQ(cache.put(1, 10), std::error_code());
    EXPECT_TRUE(cache.get(1).first);
    EXPECT_EQ(cache.get(1).second->m_value, 10);

    cache.put(2, 20);
    cache.put(3, 20);
    cache.put(4, 20);
    cache.put(5, 20);
    cache.put(6, 20);

    EXPECT_FALSE(cache.get(1).first);
    EXPECT_TRUE(cache.get(2).first);
    cache.put(7, 20);
    EXPECT_FALSE(cache.get(2).first);
}

TEST(LruCache, Remove) {
    LruCache<int, int> cache(5);
    cache.put(1, 20);
    cache.put(2, 20);
    cache.put(3, 20);
    cache.put(4, 20);
    cache.put(5, 20);
    cache.put(6, 20);

    cache.remove(1);
    cache.remove(2);
    cache.remove(3);
    cache.remove(4);
    cache.remove(5);

    EXPECT_FALSE(cache.get(2).first);
    EXPECT_TRUE(cache.get(6).first);
    cache.put(7, 20);
    EXPECT_EQ(cache.get(7).second->m_value, 20);
}
