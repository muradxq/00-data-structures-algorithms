/**
 * Problem: Minimum Number of Arrows to Burst Balloons
 * LeetCode #452
 * Difficulty: Medium
 * Pattern: Greedy
 *
 * Balloons as horizontal intervals. Find minimum arrows (vertical lines) 
 * to burst all balloons.
 *
 * Example:
 *   Input: [[10,16],[2,8],[1,6],[7,12]]
 *   Output: 2
 *   Explanation: Arrow at x=6 bursts [2,8] and [1,6]
 *                Arrow at x=11 bursts [10,16] and [7,12]
 *
 * Key Insight: Same as finding maximum non-overlapping intervals.
 *              Sort by end position, count groups that don't overlap.
 *
 * Constraints:
 *   - 1 <= points.length <= 10^5
 *   - points[i].length == 2
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findMinArrowPoints(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    
    // Sort by end position
    sort(points.begin(), points.end(), 
        [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int arrows = 1;
    int arrowPos = points[0][1];  // Shoot at end of first balloon
    
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i][0] > arrowPos) {
            // Balloon starts after arrow position, need new arrow
            arrows++;
            arrowPos = points[i][1];
        }
        // else: current arrow bursts this balloon too
    }
    
    return arrows;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinArrows, Example1) {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    EXPECT_EQ(findMinArrowPoints(points), 2);
}

TEST(MinArrows, Example2) {
    vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    EXPECT_EQ(findMinArrowPoints(points), 4);
}

TEST(MinArrows, Example3) {
    vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    EXPECT_EQ(findMinArrowPoints(points), 2);
}

TEST(MinArrows, SingleBalloon) {
    vector<vector<int>> points = {{1,5}};
    EXPECT_EQ(findMinArrowPoints(points), 1);
}

TEST(MinArrows, AllOverlap) {
    vector<vector<int>> points = {{1,10},{2,9},{3,8},{4,7}};
    EXPECT_EQ(findMinArrowPoints(points), 1);
}

TEST(MinArrows, TouchingEdges) {
    vector<vector<int>> points = {{1,2},{2,3},{3,4}};
    EXPECT_EQ(findMinArrowPoints(points), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
