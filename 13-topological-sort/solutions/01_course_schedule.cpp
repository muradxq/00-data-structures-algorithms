/**
 * Problem: Course Schedule
 * LeetCode #207
 * Difficulty: Medium
 * Pattern: Cycle Detection
 *
 * Can finish all courses given prerequisites?
 *
 * Example:
 *   Input: numCourses = 2, prerequisites = [[1,0]]
 *   Output: true
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Your implementation here
    // Use Kahn's algorithm (BFS with in-degrees)
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CourseSchedule, CanFinish) {
    vector<vector<int>> prereqs = {{1, 0}};
    EXPECT_TRUE(canFinish(2, prereqs));
}

TEST(CourseSchedule, HasCycle) {
    vector<vector<int>> prereqs = {{1, 0}, {0, 1}};
    EXPECT_FALSE(canFinish(2, prereqs));
}

TEST(CourseSchedule, NoPrereqs) {
    vector<vector<int>> prereqs;
    EXPECT_TRUE(canFinish(2, prereqs));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
