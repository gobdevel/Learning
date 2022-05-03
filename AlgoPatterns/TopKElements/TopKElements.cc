#include "TopKElements.h"

#include <algorithm>

Nums findKLargetsNumbers(const Nums& nums, Num k) {
    // Make min heap on vector itself as we need to return vector
    Nums minHeap(std::begin(nums), std::begin(nums) + k);
    std::make_heap(std::begin(minHeap), std::end(minHeap), std::greater<>{});

    for (int i = k; i < nums.size(); ++i) {
        if (minHeap.front() < nums[i]) {
            std::pop_heap(std::begin(minHeap), std::end(minHeap),
                          std::greater<>{});

            minHeap.pop_back();
            minHeap.push_back(nums[i]);
            std::push_heap(std::begin(minHeap), std::end(minHeap),
                           std::greater<>{});
        }
    }
    return minHeap;
}

Num findKthSmallestNumbers(const Nums& nums, Num k) {
    // Make max heap on vector itself as we need to return vector
    Nums maxHeap(std::begin(nums), std::begin(nums) + k);
    std::make_heap(std::begin(maxHeap), std::end(maxHeap));

    for (int i = k; i < nums.size(); ++i) {
        if (maxHeap.front() > nums[i]) {
            std::pop_heap(std::begin(maxHeap), std::end(maxHeap));

            maxHeap.pop_back();
            maxHeap.push_back(nums[i]);
            std::push_heap(std::begin(maxHeap), std::end(maxHeap));
        }
    }
    return maxHeap.front();
}
