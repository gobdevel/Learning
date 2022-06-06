#include "player.h"

#include <iostream>

Position HumanPlayer::nextMove() {
    int row, col;
    do {
        std::cout << getName() << " Enter row and col : ";
        std::cin >> row;
        std::cin >> col;
        std::cout << " Input row & col " << row << " " << col << " \n";
    } while (row < 0 || row >= 3 || col < 0 || col >= 3);
    return Position{row, col};
}
