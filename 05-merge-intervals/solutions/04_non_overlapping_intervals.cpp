/**
 * Problem: Non-overlapping Intervals
 * LeetCode #435
 * Difficulty: Medium
 * Pattern: Remove (Greedy)
 *
 * Find minimum number of intervals to remove to make rest non-overlapping.
 *
 * Example:
 *   Input: [[1,2],[2,3],[3,4],[1,3]]
 *   Output: 1 (Remove [1,3])
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Your implementation here
    // Key: Greedy - always keep interval that ends earliest
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NonOverlapping, Example1) {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    EXPECT_EQ(eraseOverlapIntervals(intervals), 1);
}

TEST(NonOverlapping, Example2) {
    vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
    EXPECT_EQ(eraseOverlapIntervals(intervals), 2);
}

TEST(NonOverlapping, Example3) {
    vector<vector<int>> intervals = {{1,2},{2,3}};
    EXPECT_EQ(eraseOverlapIntervals(intervals), 0);
}

TEST(NonOverlapping, Empty) {
    vector<vector<int>> intervals = {};
    EXPECT_EQ(eraseOverlapIntervals(intervals), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
