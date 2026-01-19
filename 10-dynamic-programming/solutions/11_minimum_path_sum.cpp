/**
 * Problem: Minimum Path Sum
 * LeetCode #64
 * Difficulty: Medium
 * Pattern: Grid
 *
 * Find path with minimum sum in grid.
 *
 * Example:
 *   Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 *   Output: 7 (1→3→1→1→1)
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minPathSum(vector<vector<int>>& grid) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinPathSum, Example1) {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    EXPECT_EQ(minPathSum(grid), 7);
}

TEST(MinPathSum, Example2) {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    EXPECT_EQ(minPathSum(grid), 12);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
