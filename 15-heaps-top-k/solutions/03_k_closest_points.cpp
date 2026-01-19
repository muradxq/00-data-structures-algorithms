/**
 * Problem: K Closest Points to Origin
 * LeetCode #973
 * Difficulty: Medium
 * Pattern: Top K
 *
 * Find k closest points to origin.
 *
 * Example:
 *   Input: points = [[1,3],[-2,2]], k = 1
 *   Output: [[-2,2]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Your implementation here
    // Use max-heap of size k
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(KClosestPoints, Example1) {
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    auto result = kClosest(points, 1);
    EXPECT_EQ(result.size(), 1);
}

TEST(KClosestPoints, Example2) {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    auto result = kClosest(points, 2);
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
