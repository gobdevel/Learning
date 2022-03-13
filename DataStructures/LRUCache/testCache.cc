#include <iostream>

#include "LRUCache.h"

int main() {
    LRUCache<int, int> cache(5);
    cache.add(10, 100);
    cache.add(20, 200);
    cache.add(30, 300);

    auto val = cache.get(20);
    std::cout << val->m_value << "\n";
}
