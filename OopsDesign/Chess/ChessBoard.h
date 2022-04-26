#ifndef __CHESS_BOARD_H__
#define __CHESS_BOARD_H__

#include "ChessCommon.h"
#include "ChessPieces.h"

class Board {
public:
    static constexpr int size = 8;
    Board() : squares(size, std::vector<Square>{}) {
        auto map = PieceFactory::getPieces();

        Color col = Color::Black;
        for (int i = 0; i < size; ++i) {
            col = (i % 2 == 0) ? Color::White : Color::Black;
            for (int j = 0; j < size; ++j) {
                col = static_cast<Color>((static_cast<int>(col) ^ 1));
                Location loc(Row(i + 1), static_cast<Column>(j));
                squares[i].emplace_back(col, std::move(loc));
                if (auto it = map.find(squares[i][j].getLocation().toString());
                    it != map.end()) {
                    squares[i][j].setPiecePtr(it->second);
                }
            }
        }
    }

    void toString() {
        for (auto& r : squares) {
            for (auto& j : r) {
                std::cout << j << "\t";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<Square>> squares;
};

#endif
