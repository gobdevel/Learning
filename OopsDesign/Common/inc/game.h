#pragma once

#include <memory>
#include <vector>

#include "user.h"

using UserPtr = std::unique_ptr<User>;
using Players = std::vector<UserPtr>;

class Game {
public:
    struct State {
        State(UserPtr p1, UserPtr p2) {
            players.emplace_back(std::move(p1));
            players.emplace_back(std::move(p2));
        }
        Players players;
        int     currentPlayer{0};
        int     winningPlayer{-1};
    };
    void run(State &state);

private:
    virtual void start(Game::State &)      = 0;
    virtual void takeTurn(Game::State &)   = 0;
    virtual bool isFinished(Game::State &) = 0;
};
