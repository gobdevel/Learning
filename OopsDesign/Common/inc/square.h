#pragma once
#include <algorithm>
#include <memory>

#include "position.h"

class Piece {
public:
    virtual int         getId() const   = 0;
    virtual std::string getName() const = 0;
};

using PiecePtr = std::shared_ptr<const Piece>;

class Square {
public:
    Square(Position pos) : m_position(std::move(pos)) {}
    Square(int row, int col) : m_position{row, col} {}

    void     placeItem(PiecePtr piece) { m_piece.swap(piece); }
    PiecePtr getItem() const { return m_piece; }
    PiecePtr exchangeItem(PiecePtr piece) {
        return std::exchange(m_piece, piece);
    }

    friend bool operator==(const Square& lhs, const Square& rhs) {
        return (lhs.m_piece && rhs.m_piece &&
                lhs.m_piece->getId() == rhs.m_piece->getId());
    }

    friend bool operator!=(const Square& lhs, const Square& rhs) {
        return (lhs.m_piece && rhs.m_piece &&
                lhs.m_piece->getId() != rhs.m_piece->getId());
    }

    bool isEmpty() { return m_piece == nullptr; }

private:
    Position m_position;
    PiecePtr m_piece;
};
