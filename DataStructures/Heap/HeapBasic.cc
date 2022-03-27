#include "HeapBasic.h"

// Min Heap
void HeapiFy(Container& nums, int index) {
    auto left  = getLeft(index);
    auto right = getRight(index);

    auto min = index;
    if (left < nums.size() && nums[min] > nums[left]) min = left;
    if (right < nums.size() && nums[min] > nums[right]) min = right;

    if (min != index) {
        std::swap(nums[index], nums[min]);
        HeapiFy(nums, min);
    }
}

void buildHeap(Container& nums) {
    for (int i = nums.size() / 2; i >= 0; --i) {
        HeapiFy(nums, i);
    }
}

void BottomUpFix(Container& nums, int index) {
    auto root = getRoot(index);
    if (root >= 0 && nums[root] > nums[index]) {
        std::swap(nums[root], nums[index]);
        BottomUpFix(nums, root);
    }
}

void insert(Container& nums, int value) {
    nums.emplace_back(value);
    auto index = nums.size() - 1;
    BottomUpFix(nums, index);
}

void remove(Container& nums) {
    if (nums.empty()) return;
    if (nums.size() == 1) {
        nums.pop_back();
        return;
    }
    std::swap(nums.front(), nums.back());
    nums.pop_back();
    HeapiFy(nums, 0);
}
