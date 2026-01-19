/**
 * Problem: Insert Interval
 * LeetCode #57
 * Difficulty: Medium
 * Pattern: Insert
 *
 * Insert new interval into sorted non-overlapping intervals, merging if needed.
 *
 * Example:
 *   Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *   Output: [[1,5],[6,9]]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(InsertInterval, Example1) {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> expected = {{1,5},{6,9}};
    EXPECT_EQ(insert(intervals, newInterval), expected);
}

TEST(InsertInterval, Example2) {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    vector<vector<int>> expected = {{1,2},{3,10},{12,16}};
    EXPECT_EQ(insert(intervals, newInterval), expected);
}

TEST(InsertInterval, Empty) {
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {5,7};
    vector<vector<int>> expected = {{5,7}};
    EXPECT_EQ(insert(intervals, newInterval), expected);
}

TEST(InsertInterval, InsertAtStart) {
    vector<vector<int>> intervals = {{3,5},{6,9}};
    vector<int> newInterval = {1,2};
    vector<vector<int>> expected = {{1,2},{3,5},{6,9}};
    EXPECT_EQ(insert(intervals, newInterval), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
