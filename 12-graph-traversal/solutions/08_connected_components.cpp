/**
 * Problem: Number of Connected Components in Undirected Graph
 * LeetCode #323
 * Difficulty: Medium
 * Pattern: Union Find/DFS
 *
 * Count number of connected components.
 *
 * Example:
 *   Input: n = 5, edges = [[0,1],[1,2],[3,4]]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int countComponents(int n, vector<vector<int>>& edges) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ConnectedComponents, Example1) {
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    EXPECT_EQ(countComponents(5, edges), 2);
}

TEST(ConnectedComponents, AllConnected) {
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};
    EXPECT_EQ(countComponents(5, edges), 1);
}

TEST(ConnectedComponents, NoEdges) {
    vector<vector<int>> edges;
    EXPECT_EQ(countComponents(5, edges), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
