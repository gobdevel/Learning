#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>

#include "../Common/User.h"
#include "Square.h"

enum class Status { cont, p1Win, p2Win, draw, error };

class Board {
public:
    Board(int n) : m_board(n, std::vector<Square>{}), m_size(n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m_board[i].emplace_back(Location(i, j));
            }
        }
    }

    Status nextMove(const User& user, Location loc) {
        auto row = loc.getRow();
        auto col = loc.getCol();

        // Validate Row and Column
        if ((row < 0 && row >= m_size) || col < 0 && col >= m_size) {
            return Status::error;
        }

        auto& sq = m_board[row][col];
        if (!sq.isEmpty()) {
            return Status::error;
        }

        int    id = user.getId();
        Marker m  = (id % 2 == 0) ? Marker::p1 : Marker::p2;
        sq.setMarker(m);

        return calculateResult(loc);
    }

private:
    Status calculateResult(Location& loc) {
        int row = loc.getRow();
        int col = loc.getCol();

        // check Row
        Status s      = Status::cont;
        bool   result = true;
        auto   key    = m_board[row][col].getMarker();

        for (int i = 0; i < m_size; ++i) {
            if (m_board[row][i].getMarker() != key) {
                result = false;
                break;
            }
        }

        if (result == true) return Status::p1Win;

        result = true;
        for (int i = 0; i < m_size; ++i) {
            if (m_board[i][col].getMarker() != key) {
                result = false;
                break;
            }
        }

        if (result == true) return Status::p2Win;

        return Status::cont;
    }
    using BoardArea = std::vector<std::vector<Square>>;
    BoardArea m_board;
    int       m_size;
};

#endif
