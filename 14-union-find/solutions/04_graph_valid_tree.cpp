/**
 * Problem: Graph Valid Tree
 * LeetCode #261 (Premium)
 * Difficulty: Medium
 * Pattern: Tree Check
 *
 * Check if edges form a valid tree (connected, no cycles).
 *
 * Example:
 *   Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 *   Output: true
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool validTree(int n, vector<vector<int>>& edges) {
    // Your implementation here
    // Tree has exactly n-1 edges and no cycles
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(GraphValidTree, ValidTree) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    EXPECT_TRUE(validTree(5, edges));
}

TEST(GraphValidTree, HasCycle) {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    EXPECT_FALSE(validTree(5, edges));
}

TEST(GraphValidTree, Disconnected) {
    vector<vector<int>> edges = {{0, 1}, {2, 3}};
    EXPECT_FALSE(validTree(4, edges));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
