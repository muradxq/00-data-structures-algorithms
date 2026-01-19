/**
 * Problem: N-Queens
 * LeetCode #51
 * Difficulty: Hard
 * Pattern: Board
 *
 * Place N queens on N×N board so none attack each other.
 *
 * Example:
 *   Input: n = 4
 *   Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<string>> solveNQueens(int n) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NQueens, N4) {
    auto result = solveNQueens(4);
    EXPECT_EQ(result.size(), 2);
}

TEST(NQueens, N1) {
    auto result = solveNQueens(1);
    EXPECT_EQ(result.size(), 1);
}

TEST(NQueens, N2) {
    auto result = solveNQueens(2);
    EXPECT_EQ(result.size(), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
