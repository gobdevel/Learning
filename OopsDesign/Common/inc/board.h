#pragma once
#include <vector>

#include "square.h"

class Board {
public:
    using BoardArea = std::vector<std::vector<Square>>;
    const BoardArea& getBoardArea() const { return m_boardArea; }

protected:
    Board(int rows, int cols);
    BoardArea m_boardArea;

private:
    int m_rows;
    int m_cols;
};

void printBoard(const Board& board);
