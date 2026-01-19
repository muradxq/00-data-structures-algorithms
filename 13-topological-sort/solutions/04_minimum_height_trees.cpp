/**
 * Problem: Minimum Height Trees
 * LeetCode #310
 * Difficulty: Medium
 * Pattern: Multi-source BFS
 *
 * Find roots that give minimum height trees.
 *
 * Example:
 *   Input: n = 4, edges = [[1,0],[1,2],[1,3]]
 *   Output: [1]
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // Your implementation here
    // Trim leaves layer by layer until 1-2 nodes remain
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinimumHeightTrees, Example1) {
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    auto result = findMinHeightTrees(4, edges);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 1);
}

TEST(MinimumHeightTrees, TwoRoots) {
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    auto result = findMinHeightTrees(6, edges);
    EXPECT_EQ(result.size(), 2);
}

TEST(MinimumHeightTrees, SingleNode) {
    vector<vector<int>> edges;
    auto result = findMinHeightTrees(1, edges);
    EXPECT_EQ(result.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
