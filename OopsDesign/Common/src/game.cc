#include "game.h"

void Game::run(State& state) {
    // Copy initial state;
    // m_state.players.swap(state.players);
    // m_state.currentPlayer = state.currentPlayer;
    // m_state.winningPlayer = state.winningPlayer;

    // Call Start
    start(state);

    do {
        takeTurn(state);
    } while (!isFinished(state));
}
