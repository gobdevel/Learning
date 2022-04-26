#ifndef __CHESS_COMMON_H__
#define __CHESS_COMMON_H__

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

enum class Color { White = 0, Black = 1 };

enum class Column { A, B, C, D, E, F, G, H };
static constexpr char rowName[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
static constexpr char colName[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
static constexpr const char colorName[2][6] = {"White", "Black"};

class Row {
    constexpr static int maxRow = 8;

private:
    const int m_row;

public:
    explicit Row(int r) : m_row(r) { assert(r > 0 && r <= maxRow); }
    int getRowNumber() { return m_row; }

    friend std::ostream& operator<<(std::ostream& stream, const Row& row) {
        assert(row.m_row > 0 && row.m_row <= maxRow);
        stream << rowName[row.m_row - 1];
        return stream;
    }
};

class Location {
public:
    explicit Location(Row row, Column col) : m_row(row), m_col(col) {}
    friend std::ostream& operator<<(std::ostream& stream, const Location& loc) {
        stream << colName[static_cast<int>(loc.m_col)] << loc.m_row;
        return stream;
    }

    std::string toString() const {
        std::stringstream str;
        str << *this;
        return str.str();
    }

    Row    getRow() const { return m_row; }
    Column getColumn() const { return m_col; }

private:
    const Row    m_row;
    const Column m_col;
};

class Piece {
public:
    // using SquarePtr = std::unique_ptr<Square>;
    Piece(Color color, std::string name)
        : m_color(color), m_name(std::move(name)) {}

    std::string getName() const { return m_name; }
    Color       getColor() const { return m_color; }
    // SquarePtr     getSquarePtr() { return std::move(m_square); }
    // const Square& getSquare() { return *m_square.get(); }
    // void          setSquarePtr(SquarePtr ptr) { m_square = std::move(ptr); }

    friend std::ostream& operator<<(std::ostream& stream, const Piece& piece) {
        stream << piece.m_name << ":"
               << colorName[static_cast<int>(piece.m_color)];
        return stream;
    }

private:
    const Color       m_color;
    const std::string m_name;
    // SquarePtr         m_square;
};

using PiecePtr = Piece*;

class Square {
public:
    explicit Square(Color color, Location loc)
        : m_occupied(false), m_color(color), m_loc(loc) {}

    bool                 isOccupied() { return m_occupied; }
    friend std::ostream& operator<<(std::ostream& stream, const Square& sq) {
        stream << sq.m_loc << ":" << colorName[static_cast<int>(sq.m_color)]
               << "-";
        if (sq.m_piece != nullptr) {
            stream << *sq.m_piece;
        }
        return stream;
    }

    const Location& getLocation() { return m_loc; }

    void     setPiecePtr(PiecePtr ptr) { m_piece = ptr; }
    PiecePtr getPiecePtr() { return m_piece; }

private:
    bool           m_occupied;
    Color          m_color;
    const Location m_loc;
    PiecePtr       m_piece{nullptr};
};

class Movable {
public:
    using Move  = Location;
    using Moves = std::vector<Location>;

    virtual Moves getValidMoves(const Location& loc) = 0;
    virtual void  makeMove(Move mov)                 = 0;
};

#endif
