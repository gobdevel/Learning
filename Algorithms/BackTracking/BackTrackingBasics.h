#ifndef __BACTRACKING_H__
#define __BACTRACKING_H__

/**
 * Backtracking is a general algorithm for finding all (or some) solutions to
 * some computational problems (notably Constraint satisfaction problems or
 * CSPs), which incrementally builds candidates to the solution and abandons a
 * candidate ("backtracks") as soon as it determines that the candidate cannot
 * lead to a valid solution. [1]
 */

/**
 * The N-queens puzzle is the problem of placing N{N}N queens on an [N×N] 
 * hessboard such that no two queens can attack each other. One i asked to
 * count the number of solutions to place the N{N}N queens on the board.

Solution :
In order to count the number of possible solutions to place the N queens, we can
break it down into the following steps:

        (1). Overall, we iterate over each row in the board, i.e. once we reach
the last row of the board, we should have explored all the possible solutions.

        (2). At each iteration (we are located at certain row), we then further
iterate over each column of the board, along the current row. At this second
iteration, we then can explore the possibility of placing a queen on a
particular cell.

        (3). Before, we place a queen on the cell with index of (row, col), we
need to check if this cell is under the attacking zone of the queens that have
been placed on the board before. Let us assume there is a function called
i_not_under_attack(row, col) that can do the check.

        (4). Once the check passes, we then can proceed to place a queen. Along
with the placement, one should also mark out the attacking zone of this
newly-placed queen. Let us assume there is another function called
place_queen(row, col) that can help us to do so.

        (5). As an important behaviour of backtracking, we should be able to
abandon our previous decision at the moment we decide to move on to the next
candidate. Let us assume there is a function called remove_queen(row, col) that
can help us to revert the decision along with the changes in step (4). s
 */

#endif
