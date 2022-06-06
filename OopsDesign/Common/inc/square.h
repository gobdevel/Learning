#pragma once
#include <algorithm>

#include "position.h"

class Piece {
public:
    virtual int         getId() const   = 0;
    virtual std::string getName() const = 0;
};

class Square {
public:
    Square(Position pos) : m_position(std::move(pos)) {}
    Square(int row, int col) : m_position{row, col} {}

    void         placeItem(const Piece* piece) { m_piece = piece; }
    const Piece* getPiece() const { return m_piece; }

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
    Position     m_position;
    const Piece* m_piece{nullptr};
};
