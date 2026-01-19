/**
 * Problem: Redundant Connection
 * LeetCode #684
 * Difficulty: Medium
 * Pattern: Cycle Detection
 *
 * Find edge that can be removed to make tree.
 *
 * Example:
 *   Input: edges = [[1,2],[1,3],[2,3]]
 *   Output: [2,3]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RedundantConnection, Example1) {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> expected = {2,3};
    EXPECT_EQ(findRedundantConnection(edges), expected);
}

TEST(RedundantConnection, Example2) {
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> expected = {1,4};
    EXPECT_EQ(findRedundantConnection(edges), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
