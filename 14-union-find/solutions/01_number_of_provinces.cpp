/**
 * Problem: Number of Provinces
 * LeetCode #547
 * Difficulty: Medium
 * Pattern: Basic Union Find
 *
 * Find number of connected groups.
 *
 * Example:
 *   Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findCircleNum(vector<vector<int>>& isConnected) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NumProvinces, Example1) {
    vector<vector<int>> conn = {{1,1,0},{1,1,0},{0,0,1}};
    EXPECT_EQ(findCircleNum(conn), 2);
}

TEST(NumProvinces, Example2) {
    vector<vector<int>> conn = {{1,0,0},{0,1,0},{0,0,1}};
    EXPECT_EQ(findCircleNum(conn), 3);
}

TEST(NumProvinces, AllConnected) {
    vector<vector<int>> conn = {{1,1,1},{1,1,1},{1,1,1}};
    EXPECT_EQ(findCircleNum(conn), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
