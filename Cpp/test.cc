#include <iostream>
#include <unordered_map>

int mian() {
    std::unordered_map<int, int> a;
    a.emplace(std::make_pair(12, 10));
    a.emplace(std::make_pair(12, 10));
    return 0;
}
