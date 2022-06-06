#pragma once

#include <vector>

#include "user.h"

class Game {
public:
    struct State {
        std::vector<User *> player;
        int                 currentPlayer;
        int                 winningPlayer;
    };
    void run(State state);

private:
    virtual void start(Game::State &)      = 0;
    virtual void takeTurn(Game::State &)   = 0;
    virtual bool isFinished(Game::State &) = 0;
    State        m_state;
};
