/**
 * Problem: Pacific Atlantic Water Flow
 * LeetCode #417
 * Difficulty: Medium
 * Pattern: Multi-source BFS
 *
 * Find cells that can flow to both Pacific and Atlantic oceans.
 *
 * Example:
 *   Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 *   Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PacificAtlantic, Example1) {
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto result = pacificAtlantic(heights);
    EXPECT_EQ(result.size(), 7);
}

TEST(PacificAtlantic, SingleCell) {
    vector<vector<int>> heights = {{1}};
    auto result = pacificAtlantic(heights);
    EXPECT_EQ(result.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
