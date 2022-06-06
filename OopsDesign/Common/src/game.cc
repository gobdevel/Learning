#include "game.h"

void Game::run(State state) {
    // Copy initial state;
    m_state = state;

    // Call Start
    start(m_state);

    do {
        takeTurn(m_state);
    } while (!isFinished(m_state));
}
