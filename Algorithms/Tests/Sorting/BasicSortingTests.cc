#include "BasicSorting.h"
#include "gtest/gtest.h"
#include "utils.h"

using Container = std::vector<int>;

Container getBasic() {
    Container data{4, 3, 2};
    return data;
}

Container getEmpty() {
    Container data;
    return data;
}

Container getSingle() {
    Container data{1};
    return data;
}

Container getDouble() {
    Container data{2, 1};
    return data;
}

Container getLarge() { return getSampleData<int>(10000); }

// SELECTION SORT
TEST(SelectionSort, Basic) {
    auto data = getBasic();
    SelectionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(SelectionSort, Empty) {
    auto data = getEmpty();
    SelectionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(SelectionSort, Single) {
    auto data = getSingle();
    SelectionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(SelectionSort, Double) {
    auto data = getDouble();
    SelectionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(SelectionSort, Large) {
    auto data = getLarge();
    SelectionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

// BUBBLE SORT
TEST(BubbleSort, Basic) {
    auto data = getBasic();
    BubbleSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSort, Empty) {
    auto data = getEmpty();
    BubbleSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSort, Single) {
    auto data = getSingle();
    BubbleSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSort, Double) {
    auto data = getDouble();
    BubbleSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSort, Large) {
    auto data = getLarge();
    BubbleSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(InsertionSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    InsertionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(InsertionSort, Empty) {
    auto data = getEmpty();
    InsertionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(InsertionSort, Single) {
    auto data = getSingle();
    InsertionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(InsertionSort, Double) {
    auto data = getDouble();
    InsertionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(InsertionSort, Large) {
    auto data = getLarge();
    InsertionSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(QuickSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    QuickSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(QuickSort, Empty) {
    auto data = getEmpty();
    QuickSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(QuickSort, Single) {
    auto data = getSingle();
    QuickSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(QuickSort, Double) {
    auto data = getDouble();
    QuickSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(QuickSort, Large) {
    auto data = getLarge();
    QuickSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(MergeSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    MergeSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(MergeSort, Empty) {
    auto data = getEmpty();
    MergeSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(MergeSort, Single) {
    auto data = getSingle();
    MergeSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(MergeSort, Double) {
    auto data = getDouble();
    MergeSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(MergeSort, Large) {
    auto data = getLarge();
    MergeSort(data.begin(), data.end());
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}
