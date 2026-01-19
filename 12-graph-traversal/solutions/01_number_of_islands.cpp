/**
 * Problem: Number of Islands
 * LeetCode #200
 * Difficulty: Medium
 * Pattern: DFS/BFS Grid
 *
 * Count islands (groups of connected '1's).
 *
 * Example:
 *   Input: grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int numIslands(vector<vector<char>>& grid) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NumIslands, Example1) {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    EXPECT_EQ(numIslands(grid), 1);
}

TEST(NumIslands, Example2) {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    EXPECT_EQ(numIslands(grid), 3);
}

TEST(NumIslands, AllWater) {
    vector<vector<char>> grid = {{'0','0'},{'0','0'}};
    EXPECT_EQ(numIslands(grid), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
