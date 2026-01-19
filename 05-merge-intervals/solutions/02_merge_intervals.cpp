/**
 * Problem: Merge Intervals
 * LeetCode #56
 * Difficulty: Medium
 * Pattern: Merge
 *
 * Merge all overlapping intervals.
 *
 * Example:
 *   Input: [[1,3],[2,6],[8,10],[15,18]]
 *   Output: [[1,6],[8,10],[15,18]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MergeIntervals, Example1) {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> expected = {{1,6},{8,10},{15,18}};
    EXPECT_EQ(merge(intervals), expected);
}

TEST(MergeIntervals, Example2) {
    vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> expected = {{1,5}};
    EXPECT_EQ(merge(intervals), expected);
}

TEST(MergeIntervals, NoOverlap) {
    vector<vector<int>> intervals = {{1,2},{3,4},{5,6}};
    vector<vector<int>> expected = {{1,2},{3,4},{5,6}};
    EXPECT_EQ(merge(intervals), expected);
}

TEST(MergeIntervals, AllOverlap) {
    vector<vector<int>> intervals = {{1,4},{2,5},{3,6}};
    vector<vector<int>> expected = {{1,6}};
    EXPECT_EQ(merge(intervals), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
