#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

using Num       = int;
using Nums      = std::vector<Num>;
using ListNums  = std::vector<Nums>;
using NumRange  = std::pair<Num, Num>;
using NumPair   = std::pair<Num, Num>;
using NumMatrix = ListNums;
using FloatNums = std::vector<float>;

template <typename T>
using remove_cv_ref_t = typename std::remove_cv_t<std::remove_reference_t<T>>;

template <typename Container>
void printThis(const Container& c) {
    for (const auto& i : c) {
        std::cout << i << ", ";
    }
    std::cout << "\n";
}

template <typename T, typename Container = std::vector<T>>
Container getSampleData(std::size_t count) {
    Container          c;
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, count * 10);

    for (std::size_t i = 0; i < count; ++i) {
        c.push_back(distrib(gen));
    }
    return c;
}

#endif
