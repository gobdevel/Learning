#ifndef __BASIC_SORTING_H__
#define __BASIC_SORTING_H__

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename ForwardIterator>
void SelectionSort(ForwardIterator start, ForwardIterator end) {
    for (; start != end; ++start) {
        std::iter_swap(std::min_element(start, end), start);
    }
}

template <typename ForwardIterator>
void BubbleSort(ForwardIterator start, ForwardIterator end) {
    for (; start != end; ++start) {
        for (auto j = std::next(start); j != end; ++j) {
            if (*std::prev(j) < *j) {
                std::iter_swap(std::prev(j), j);
            }
        }
        std::iter_swap(start, std::prev(end));
    }
}

template <typename BidirectionalIterator>
void InsertionSort(BidirectionalIterator start, BidirectionalIterator end) {
    if (start == end) return;
    for (auto curr = std::next(start); curr != end; ++curr) {
        for (auto j = curr; j > start && *j < *std::prev(j); --j) {
            std::iter_swap(j, std::prev(j));
        }
    }
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator myPartition(ForwardIterator start, ForwardIterator end,
                            Predicate P) {
    start = std::find_if_not(start, end, P);
    if (start == end) return start;
    for (auto i = std::next(start); i != end; ++i) {
        if (P(*i)) {
            std::iter_swap(start, i);
            ++start;
        }
    }
    return start;
}

template <typename ForwardIterator>
void Merge(ForwardIterator start, ForwardIterator mid, ForwardIterator end) {
    using ValueType = typename ForwardIterator::value_type;
    std::vector<ValueType> left(start, mid);
    std::vector<ValueType> right(mid, end);

    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            *start++ = left[i++];
        } else {
            *start++ = right[j++];
        }
    }

    while (i < left.size()) {
        *start++ = left[i++];
    }

    while (j < right.size()) {
        *start++ = right[j++];
    }
}

template <typename ForwardIterator>
void MergeSort(ForwardIterator start, ForwardIterator end) {
    auto dist = std::distance(start, end);
    if (dist > 1) {
        auto mid = start + dist / 2;
        MergeSort(start, mid);
        MergeSort(mid, end);
        // std::inplace_merge(start, mid, end);
        Merge(start, mid, end);
    }
}

template <typename ForwardIterator>
void QuickSort(ForwardIterator start, ForwardIterator end) {
    if (start != end) {
        auto pivot = *std::next(start, std::distance(start, end) / 2);
        auto mid1  = myPartition(start, end, [&pivot](const auto& entry) {
            return (entry < pivot);
         });
        auto mid2  = myPartition(mid1, end, [&pivot](const auto& entry) {
            return !(pivot < entry);
         });
        QuickSort(start, mid1);
        QuickSort(mid2, end);
    }
}

#endif
