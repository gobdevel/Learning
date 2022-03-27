#include "BinaryTree.h"
#include "gtest/gtest.h"

using Results = std::vector<int>;

TEST(BinaryTreeBasic, Pre_Add_Empty) {
    BinaryTree bt;
    Results    result, answer;
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
    bt.remove(10);
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Pre_Add_Single) {
    BinaryTree bt;
    Results    result, answer{12};
    bt.insert(12);
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);

    bt.remove(10);
    EXPECT_EQ(result, answer);

    bt.remove(12);
    answer.pop_back();
    result.clear();
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Pre_Add_Double) {
    BinaryTree bt;
    Results    result, answer{12, 20};
    bt.insert(12);
    bt.insert(20);
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);

    // Remove non
    bt.remove(10);
    EXPECT_EQ(result, answer);

    // Remove 20
    bt.remove(20);
    answer.pop_back();
    result.clear();
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Pre_Add) {
    BinaryTree bt;
    Results    result, answer{12, 6, 20};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Pre_Add_Large) {
    BinaryTree bt;
    Results    result, answer{12, 6, 2, 3, 11, 20, 18, 14, 16};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.insert(18);
    bt.insert(2);
    bt.insert(14);
    bt.insert(11);
    bt.insert(16);
    bt.insert(3);
    bt.preOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Inorder_Add_Empty) {
    BinaryTree bt;
    Results    result, answer;
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Inorder_Add_Single) {
    BinaryTree bt;
    Results    result, answer{12};
    bt.insert(12);
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Inorder_Add_Double) {
    BinaryTree bt;
    Results    result, answer{12, 20};
    bt.insert(12);
    bt.insert(20);
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Inorder_Add) {
    BinaryTree bt;
    Results    result, answer{6, 12, 20};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Inorder_Add_Large) {
    BinaryTree bt;
    Results    result, answer{2, 3, 6, 11, 12, 14, 16, 18, 20};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.insert(18);
    bt.insert(2);
    bt.insert(14);
    bt.insert(11);
    bt.insert(16);
    bt.insert(3);
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);

    bt.remove(11);
    bt.remove(2);
    bt.remove(20);

    result.clear();
    answer = {3, 6, 12, 14, 16, 18};
    bt.inOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Postorder_Add_Empty) {
    BinaryTree bt;
    Results    result, answer;
    bt.postOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Postorder_Add_Single) {
    BinaryTree bt;
    Results    result, answer{12};
    bt.insert(12);
    bt.postOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Postorder_Add_Double) {
    BinaryTree bt;
    Results    result, answer{20, 12};
    bt.insert(12);
    bt.insert(20);
    bt.postOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Postorder_Add) {
    BinaryTree bt;
    Results    result, answer{6, 20, 12};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.postOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}

TEST(BinaryTreeBasic, Postorder_Add_Large) {
    BinaryTree bt;
    Results    result, answer{3, 2, 11, 6, 16, 14, 18, 20, 12};
    bt.insert(12);
    bt.insert(6);
    bt.insert(20);
    bt.insert(18);
    bt.insert(2);
    bt.insert(14);
    bt.insert(11);
    bt.insert(16);
    bt.insert(3);
    bt.postOrder([&result](const auto& num) { result.emplace_back(num); });
    EXPECT_EQ(result, answer);
}
