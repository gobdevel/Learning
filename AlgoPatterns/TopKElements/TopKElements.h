#ifndef __TOP_K_ELEMENTS_H__
#define __TOP_K_ELEMENTS_H__
//#include <tuple>

#include "utils.h"

struct Point {
    Num        x;
    Num        y;
    const bool operator<(const Point& other) const {
        auto distanceToZero = [](const Point& p) {
            return ((p.x * p.x) + (p.y * p.y));
        };
        return (distanceToZero(*this) < distanceToZero(other));
    }
    const bool operator==(const Point& other) const {
        auto distanceToZero = [](const Point& p) {
            return ((p.x * p.x) + (p.y * p.y));
        };
        return (distanceToZero(*this) == distanceToZero(other));
    }
};

using Points = std::vector<Point>;

Nums   findKLargetsNumbers(const Nums& nums, Num k);
Num    findKthSmallestNumbers(const Nums& nums, Num k);
Points findKClosetPointToOrigin(const Points& points, Num k);

#endif
