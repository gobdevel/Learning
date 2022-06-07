#include <memory>

#include "player.h"
#include "ticTacToeGame.h"

int main() {
    TicTacToeGame        game;
    TicTacToeGame::State state(
        std::make_unique<HumanPlayer>("Gobind", "Bengaluru",
                                      std::make_shared<Round>()),
        std::make_unique<HumanPlayer>("Deepshikha", "Bengaluru",
                                      std::make_shared<Cross>()));
    game.run(state);
}
