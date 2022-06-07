#include "ticTacToeBoard.h"

TicTacToeBoard::Status TicTacToeBoard::place(Position        position,
                                             const PiecePtr& piece) {
    auto row = position.getRow();
    auto col = position.getCol();

    if (!m_boardArea[row][col].isEmpty()) {
        return Status::NotEmpty;
    }
    m_boardArea[row][col].placeItem(piece);
    --m_numPlacements;
    return Status::Success;
}

Result checkForWinner(Position position, const TicTacToeBoard& tb) {
    if (tb.getNumPlacements() == 0) return Result::Draw;
    const auto& b = tb.getBoardArea();
    // check row
    auto row = position.getRow();
    auto col = position.getCol();

    if ((b[row][0] == b[row][1]) && (b[row][0] == b[row][2])) {
        return Result::Win;
    }

    if ((b[0][col] == b[1][col]) && (b[0][col] == b[2][col])) {
        return Result::Win;
    }

    if (row == 0 && col == 0 || row == 2 && col == 2) {
        if (b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
            return Result::Win;
        }
    }

    if (row == 1 && col == 1) {
        if (b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
            return Result::Win;
        }
        if (b[0][2] == b[1][1] && b[0][2] == b[2][0]) {
            return Result::Win;
        }
    }

    if (row == 0 && col == 2 || row == 2 && col == 0) {
        if (b[0][2] == b[1][1] && b[0][2] == b[2][0]) {
            return Result::Win;
        }
    }
    return Result::None;
}
