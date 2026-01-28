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
    if (intervals.empty()) return 0;
    // Sort by END time (greedy: keep earliest ending)
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });
    int kept =1;
    int lastEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (lastEnd <= intervals[i][0]) {
            kept++;
            lastEnd = intervals[i][1];
        }
    }
    return intervals.size() - kept;
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
