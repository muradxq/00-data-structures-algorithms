/**
 * Problem: Interval List Intersections
 * LeetCode #986
 * Difficulty: Medium
 * Pattern: Intersection
 *
 * Find intersection of two lists of closed intervals.
 *
 * Example:
 *   Input: firstList = [[0,2],[5,10],[13,23],[24,25]]
 *          secondList = [[1,5],[8,12],[15,24],[25,26]]
 *   Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                          vector<vector<int>>& secondList) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(IntervalIntersection, Example1) {
    vector<vector<int>> first = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> second = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> expected = {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}};
    EXPECT_EQ(intervalIntersection(first, second), expected);
}

TEST(IntervalIntersection, NoIntersection) {
    vector<vector<int>> first = {{1,2},{3,4}};
    vector<vector<int>> second = {{5,6},{7,8}};
    vector<vector<int>> expected = {};
    EXPECT_EQ(intervalIntersection(first, second), expected);
}

TEST(IntervalIntersection, OneEmpty) {
    vector<vector<int>> first = {{1,2}};
    vector<vector<int>> second = {};
    vector<vector<int>> expected = {};
    EXPECT_EQ(intervalIntersection(first, second), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
