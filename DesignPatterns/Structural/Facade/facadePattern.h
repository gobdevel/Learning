#ifndef __FACADE_PATTERN_H__
#define __FACADE_PATTERN_H__
#include <algorithm>
#include <cstdlib>
#include <numeric>

#include "utils.h"

namespace FacadePattern {

/**
 *  A Facade pattern is a way of putting a simple interface in front of one or
 *  more complecated subsystem. It provides ease of use yet, at the same time,
 *  may expose customization points for power users to fine-tune the operation
 *  of the facade.
 */

struct Generator {
    virtual Nums generate(const int count) const {
        Nums result(count);
        std::generate(result.begin(), result.end(), [&]() {
            { return 1 + rand() % 9; }
        });
        return result;
    }
};

// TODO WORKING HERE
struct Splitter {
    ListNums split(ListNums& nums) const {
        ListNums result;
        return result;
    }
};

struct Verifier {
    bool verify(ListNums listNums) const {
        if (listNums.empty()) return false;
        auto expected =
            std::accumulate(listNums[0].begin(), listNums[0].end(), 0);

        return std::all_of(
            listNums.begin(), listNums.end(), [&expected](auto& nums) {
                return std::accumulate(nums.begin(), nums.end(), 0) == expected;
            });
    }
};

// Facade for generating complecated magic square
struct MagicSquareGenerator {
    ListNums generate(int size) {
        Generator g;
        Splitter  s;
        Verifier  v;

        ListNums square;
        do {
            square.clear();
            for (int i = 0; i < size; ++i) {
                square.emplace_back(g.generate(size));
            }
        } while (!v.verify(s.split(square)));
        return square;
    }
};
}  // namespace FacadePattern

#endif
