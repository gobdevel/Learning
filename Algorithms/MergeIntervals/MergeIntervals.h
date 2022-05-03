#ifndef __MERGE_INTERVALS_H__
#define __MERGE_INTERVALS_H__

#include <vector>

struct Interval {
    Interval(int start, int end) : m_start(start), m_end(end) {}
    int m_start, m_end;

    friend bool operator==(const Interval& lhs, const Interval& rhs) {
        return (std::tie(lhs.m_start, lhs.m_end) ==
                std::tie(rhs.m_start, rhs.m_end));
    }
};

using Intervals = std::vector<Interval>;

/*
 * Merging a sorted intervals to produce unique intervals
 */

static Intervals merge(Intervals& sortedIntervals) {
    Intervals result;
    auto      curr = sortedIntervals.begin();
    for (auto next = std::next(curr); next != sortedIntervals.end(); ++next) {
        // If next starts before curr's end
        if (next->m_start <= curr->m_end) {
            curr->m_end = std::max(curr->m_end, next->m_end);
        } else {
            result.emplace_back(*curr);
            curr = next;
        }
    }
    result.emplace_back(*curr);
    return result;
}

/*
 * Find mutual exclusive intervals
 */

static Intervals findMutualExclusiveIntervals(Intervals& intvs) {
    if (intvs.size() < 2) return intvs;

    std::sort(intvs.begin(), intvs.end(), [](const auto& a, const auto& b) {
        return (a.m_start < b.m_start);
    });
    return merge(intvs);
}

/*
 * Add in sorted intervals
 */
static Intervals InsertInSortedIntervalsAndMerge(Intervals& sortedIntervals,
                                                 Interval   newElement) {
    // First skip intervals which comes prior to new interval.
    auto curr = sortedIntervals.begin();
    for (; curr != sortedIntervals.end(); ++curr) {
        // Skip all which ends before start of new element
        if (curr->m_end >= newElement.m_start) break;
    }

    // First overlap or end
    auto pos = curr;
    // Check where to insert newElement after curr or before current
    if (curr != sortedIntervals.end() && curr->m_start < newElement.m_start) {
        pos = std::next(curr);
    }

    sortedIntervals.emplace(pos, std::move(newElement));
    return merge(sortedIntervals);
}

static Intervals findDisjointIntervalIntersections(Intervals& a, Intervals& b) {
    Intervals results;
    auto      i = a.begin();
    auto      j = b.begin();

    while (i != a.end() && j != b.end()) {
        if ((i->m_start >= j->m_start && i->m_start <= j->m_end) ||
            (j->m_start >= i->m_start && j->m_start <= i->m_end)) {
            results.emplace_back(std::max(i->m_start, j->m_start),
                                 std::min(i->m_end, j->m_end));
        }
        if (i->m_end < j->m_end) {
            ++i;
        } else {
            ++j;
        }
    }
    return results;
}

#endif
