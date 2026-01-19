/**
 * Problem: Rotting Oranges
 * LeetCode #994
 * Difficulty: Medium
 * Pattern: Multi-source BFS
 *
 * Find minimum minutes for all oranges to rot.
 *
 * Example:
 *   Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 *   Output: 4
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int orangesRotting(vector<vector<int>>& grid) {
    // Your implementation here
    
    return -1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RottingOranges, Example1) {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    EXPECT_EQ(orangesRotting(grid), 4);
}

TEST(RottingOranges, Impossible) {
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    EXPECT_EQ(orangesRotting(grid), -1);
}

TEST(RottingOranges, AllRotten) {
    vector<vector<int>> grid = {{0,2}};
    EXPECT_EQ(orangesRotting(grid), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
