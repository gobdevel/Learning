#include "board.h"

#include <iostream>

#include "user.h"

std::uint32_t User::s_id = 0;

Board::Board(int rows, int cols)
    : m_rows(rows), m_cols(cols), m_boardArea(rows, std::vector<Square>{}) {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m_boardArea[i].emplace_back(i, j);
        }
    }
}

void printBoard(const Board& board) {
    const auto& b   = board.getBoardArea();
    auto        row = b.size();
    if (row == 0) return;
    auto col = b[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            auto piece = b[i][j].getPiece();
            std::cout << "[" << (piece ? piece->getName() : " ") << "]";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
