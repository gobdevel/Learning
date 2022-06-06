#pragma once
#include "game.h"
#include "position.h"
#include "ticTacToeBoard.h"

class TicTacToeGame : public Game {
private:
    void start(State& state) override;
    void takeTurn(State& state) override;
    bool isFinished(State& state) override;

    TicTacToeBoard m_board;
    Result         m_result;
};
