#pragma once
#include "board.h"
#include "square.h"

class TicTacToeBoard : public Board {
public:
    static constexpr int rows = 3;
    static constexpr int cols = 3;
    TicTacToeBoard() : Board(rows, cols) {}

    enum class Status { Success, Error, NotEmpty };
    Status place(Position position, const PiecePtr& piece);
    int    getNumPlacements() const { return m_numPlacements; }

private:
    int m_numPlacements{rows * cols};
};

enum class Result { Win, Draw, None };
Result checkForWinner(Position position, const TicTacToeBoard& tb);
