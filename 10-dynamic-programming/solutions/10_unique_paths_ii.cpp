/**
 * Problem: Unique Paths II
 * LeetCode #63
 * Difficulty: Medium
 * Pattern: Grid with Obstacles
 *
 * Count paths with obstacles (1 = obstacle).
 *
 * Example:
 *   Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(UniquePathsII, Example1) {
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    EXPECT_EQ(uniquePathsWithObstacles(grid), 2);
}

TEST(UniquePathsII, Blocked) {
    vector<vector<int>> grid = {{0,1},{0,0}};
    EXPECT_EQ(uniquePathsWithObstacles(grid), 1);
}

TEST(UniquePathsII, StartBlocked) {
    vector<vector<int>> grid = {{1,0}};
    EXPECT_EQ(uniquePathsWithObstacles(grid), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
