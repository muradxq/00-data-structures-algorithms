/**
 * Problem: Word Search
 * LeetCode #79
 * Difficulty: Medium
 * Pattern: Grid
 *
 * Find if word exists in grid (adjacent cells horizontally/vertically).
 *
 * Example:
 *   Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 *   Output: true
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool exist(vector<vector<char>>& board, string word) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(WordSearch, Example1) {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    EXPECT_TRUE(exist(board, "ABCCED"));
}

TEST(WordSearch, Example2) {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    EXPECT_TRUE(exist(board, "SEE"));
}

TEST(WordSearch, NotFound) {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    EXPECT_FALSE(exist(board, "ABCB"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
