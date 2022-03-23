#include "BasicSorting.h"
#include "gtest/gtest.h"

TEST(SelectionSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    SelectionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(SelectionSort, Empty) {
    std::vector<int> data{}, answer{};
    SelectionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(SelectionSort, Single) {
    std::vector<int> data{1}, answer{1};
    SelectionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(SelectionSort, Double) {
    std::vector<int> data{2, 1}, answer{1, 2};
    SelectionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(SelectionSort, Large) {
    std::vector<int> data{2, 1, 10, 8, 4, 9, 7, 6, 3, 5},
        answer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SelectionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(BubbleSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    BubbleSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(BubbleSort, Empty) {
    std::vector<int> data{}, answer{};
    BubbleSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(BubbleSort, Single) {
    std::vector<int> data{1}, answer{1};
    BubbleSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(BubbleSort, Double) {
    std::vector<int> data{2, 1}, answer{1, 2};
    BubbleSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(BubbleSort, Large) {
    std::vector<int> data{2, 1, 10, 8, 4, 9, 7, 6, 3, 5},
        answer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BubbleSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(InsertionSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    InsertionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(InsertionSort, Empty) {
    std::vector<int> data{}, answer{};
    InsertionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(InsertionSort, Single) {
    std::vector<int> data{1}, answer{1};
    InsertionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(InsertionSort, Double) {
    std::vector<int> data{2, 1}, answer{1, 2};
    InsertionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(InsertionSort, Large) {
    std::vector<int> data{2, 1, 10, 8, 4, 9, 7, 6, 3, 5},
        answer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InsertionSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(QuickSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    QuickSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(QuickSort, Empty) {
    std::vector<int> data{}, answer{};
    QuickSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(QuickSort, Single) {
    std::vector<int> data{1}, answer{1};
    QuickSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(QuickSort, Double) {
    std::vector<int> data{2, 1}, answer{1, 2};
    QuickSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(QuickSort, Large) {
    std::vector<int> data{2, 1, 10, 8, 4, 9, 7, 6, 3, 5},
        answer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    QuickSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(MergeSort, Basic) {
    std::vector<int> data{4, 3, 2}, answer{2, 3, 4};
    MergeSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(MergeSort, Empty) {
    std::vector<int> data{}, answer{};
    MergeSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(MergeSort, Single) {
    std::vector<int> data{1}, answer{1};
    MergeSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(MergeSort, Double) {
    std::vector<int> data{2, 1}, answer{1, 2};
    MergeSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}

TEST(MergeSort, Large) {
    std::vector<int> data{2, 1, 10, 8, 4, 9, 7, 6, 3, 5},
        answer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MergeSort(data.begin(), data.end());
    EXPECT_EQ(data, answer);
}
