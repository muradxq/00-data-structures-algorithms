/**
 * Problem: Sudoku Solver
 * LeetCode #37
 * Difficulty: Hard
 * Pattern: Board
 *
 * Solve a Sudoku puzzle.
 *
 * Constraints:
 *   - board.length == 9
 *   - board[i].length == 9
 *   - board[i][j] is a digit or '.'
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
void solveSudoku(vector<vector<char>>& board) {
    // Your implementation here
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SudokuSolver, Example1) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    solveSudoku(board);
    
    // Check that no empty cells remain
    bool solved = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') solved = false;
        }
    }
    EXPECT_TRUE(solved);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
