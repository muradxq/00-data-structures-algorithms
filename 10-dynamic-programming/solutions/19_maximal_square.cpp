/**
 * Problem: Maximal Square
 * LeetCode #221
 * Difficulty: Medium
 * Pattern: Grid
 *
 * Find largest square containing only 1s.
 *
 * Example:
 *   Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 *   Output: 4
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int maximalSquare(vector<vector<char>>& matrix) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MaximalSquare, Example1) {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    EXPECT_EQ(maximalSquare(matrix), 4);
}

TEST(MaximalSquare, AllZeros) {
    vector<vector<char>> matrix = {{'0','0'},{'0','0'}};
    EXPECT_EQ(maximalSquare(matrix), 0);
}

TEST(MaximalSquare, SingleOne) {
    vector<vector<char>> matrix = {{'1'}};
    EXPECT_EQ(maximalSquare(matrix), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
