/**
 * Problem: Course Schedule II
 * LeetCode #210
 * Difficulty: Medium
 * Pattern: Find Order
 *
 * Return order to finish all courses.
 *
 * Example:
 *   Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 *   Output: [0,1,2,3] or [0,2,1,3]
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Your implementation here
    // Use topological sort to find valid ordering
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CourseScheduleII, Example1) {
    vector<vector<int>> prereqs = {{1, 0}};
    auto result = findOrder(2, prereqs);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
}

TEST(CourseScheduleII, HasCycle) {
    vector<vector<int>> prereqs = {{1, 0}, {0, 1}};
    auto result = findOrder(2, prereqs);
    EXPECT_TRUE(result.empty());
}

TEST(CourseScheduleII, NoPrereqs) {
    vector<vector<int>> prereqs;
    auto result = findOrder(2, prereqs);
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
