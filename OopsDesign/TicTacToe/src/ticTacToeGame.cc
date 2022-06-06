#include "ticTacToeGame.h"

#include <iostream>

#include "board.h"
#include "player.h"
#include "ticTacToeBoard.h"

void TicTacToeGame::start(State& state) {
    std::cout << "-- TicTacToe Game Started --\n";
    auto p1 = static_cast<Player*>(state.player[0]);
    auto p2 = static_cast<Player*>(state.player[1]);
    std::cout << " Player 1 => " << p1->getName() << " "
              << p1->getPiece()->getName() << "\n";
    std::cout << " Player 2 => " << p2->getName() << " "
              << p2->getPiece()->getName() << "\n";
}

void TicTacToeGame::takeTurn(State& state) {
    auto     status = TicTacToeBoard::Status::Error;
    Position position{-1, -1};

    do {
        printBoard(m_board);
        auto player = static_cast<Player*>(state.player[state.currentPlayer]);
        position    = player->nextMove();
        status      = m_board.move(position, player->getPiece());
    } while (status != TicTacToeBoard::Status::Success);

    // Check for Winner
    if ((m_result = checkForWinner(position, m_board)) == Result::Win) {
        state.winningPlayer = state.currentPlayer;
    }
    // Move to next player
    state.currentPlayer = (state.currentPlayer + 1) % state.player.size();
}

bool TicTacToeGame::isFinished(State& state) {
    if (m_result == Result::Win) {
        std::cout << "Player : " << state.player[state.winningPlayer]->getName()
                  << " won !!!\n";
    }
    return (m_result != Result::None);
}
