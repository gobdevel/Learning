#ifndef __CHESS_PIECES_H__
#define __CHESS_PIECES_H__

#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include "ChessCommon.h"

class Pawn : public Piece, public Movable {
public:
    Pawn(Color color) : Piece(color, "Pawn") {}
    Moves getValidMoves(const Location& loc) {
        Moves  mv;
        int    r = loc.getRow().getRowNumber();
        Column c = loc.getColumn();

        r = r + 1;
        if (r <= 8) {
            mv.emplace_back(Row(r), c);
            Column c1 = static_cast<Column>(static_cast<int>(c) + 1);
            if (c1 >= Column::A && c1 <= Column::H) {
                mv.emplace_back(Row(r), c1);
            }
            Column c2 = static_cast<Column>(static_cast<int>(c) - 1);
            if (c1 >= Column::A && c1 <= Column::H) {
                mv.emplace_back(Row(r), c2);
            }
        }
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class King : public Piece, public Movable {
public:
    King(Color color) : Piece(color, "King") {}
    Moves getValidMoves(const Location& loc) {
        Moves mv;
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class Queen : public Piece, public Movable {
public:
    Queen(Color color) : Piece(color, "Queen") {}
    Moves getValidMoves(const Location& loc) {
        Moves mv;
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class Bishop : public Piece, public Movable {
public:
    Bishop(Color color) : Piece(color, "Bishop") {}
    Moves getValidMoves(const Location& loc) {
        Moves mv;
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class Rook : public Piece, public Movable {
public:
    Rook(Color color) : Piece(color, "Rook") {}
    Moves getValidMoves(const Location& loc) {
        Moves mv;
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class Knight : public Piece, public Movable {
public:
    Knight(Color color) : Piece(color, "Knight") {}
    Moves getValidMoves(const Location& loc) {
        Moves mv;
        return mv;
    }
    void makeMove(Move mov){};

private:
};

class PieceFactory {
public:
    using PieceMap = std::unordered_map<std::string, PiecePtr>;
    PieceFactory() = delete;
    static PieceMap getPieces() {
        PieceMap pieceMap;

        // Rook
        pieceMap["A1"] = new Rook(Color::White);
        pieceMap["H1"] = new Rook(Color::White);
        pieceMap["A8"] = new Rook(Color::Black);
        pieceMap["H8"] = new Rook(Color::Black);

        // Bishop
        pieceMap["B1"] = new Bishop(Color::White);
        pieceMap["G1"] = new Bishop(Color::White);
        pieceMap["B8"] = new Bishop(Color::Black);
        pieceMap["G8"] = new Bishop(Color::Black);

        // KNIGHT
        pieceMap["C1"] = new Knight(Color::White);
        pieceMap["F1"] = new Knight(Color::White);
        pieceMap["C8"] = new Knight(Color::Black);
        pieceMap["F8"] = new Knight(Color::Black);

        pieceMap["D1"] = new King(Color::White);
        pieceMap["E1"] = new Queen(Color::White);

        pieceMap["D8"] = new Queen(Color::Black);
        pieceMap["E8"] = new King(Color::Black);

        for (char i = 'A'; i < 'A' + 8; ++i) {
            std::string p1(std::string{i} + "2");
            std::string p2(std::string{i} + "7");
            pieceMap[p1] = new Pawn(Color::White);
            pieceMap[p2] = new Pawn(Color::Black);
        }
        return pieceMap;
    }
};

#endif
