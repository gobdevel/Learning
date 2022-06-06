#include "player.h"
#include "ticTacToeGame.h"

int main() {
    HumanPlayer u1{"Gobind", "Bengaluru", new Round()};
    HumanPlayer u2{"Deepshikha", "Bengaluru", new Cross()};

    TicTacToeGame        game;
    TicTacToeGame::State state;
    state.player.push_back(&u1);
    state.player.push_back(&u2);
    state.currentPlayer = 0;
    state.winningPlayer = -1;

    game.run(state);
}
