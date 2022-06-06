#pragma once
#include "position.h"
#include "square.h"
#include "user.h"

class Cross : public Piece {
public:
    int         getId() const override { return m_id; }
    std::string getName() const override { return std::string{m_name}; }

private:
    const char m_name{'x'};
    const int  m_id = 'x';
};

class Round : public Piece {
public:
    int         getId() const override { return m_id; }
    std::string getName() const override { return std::string{m_name}; }

private:
    const char m_name{'o'};
    const int  m_id = 'o';
};

class Player : public User {
public:
    Player(std::string name, std::string address, const Piece *piece)
        : User(std::move(name), std::move(address)), m_piece{piece} {}

    virtual Position nextMove() = 0;
    const Piece     *getPiece() { return m_piece; }

private:
    const Piece *m_piece;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string name, std::string address, const Piece *piece)
        : Player(std::move(name), std::move(address), piece) {}
    Position nextMove() override;
};
