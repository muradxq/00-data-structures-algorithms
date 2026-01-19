/**
 * Problem: Course Schedule
 * LeetCode #207
 * Difficulty: Medium
 * Pattern: Cycle Detection
 *
 * Can finish all courses given prerequisites? (Cycle detection)
 *
 * Example:
 *   Input: numCourses = 2, prerequisites = [[1,0]]
 *   Output: true (Take course 0, then course 1)
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CourseSchedule, Example1) {
    vector<vector<int>> prerequisites = {{1, 0}};
    EXPECT_TRUE(canFinish(2, prerequisites));
}

TEST(CourseSchedule, HasCycle) {
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    EXPECT_FALSE(canFinish(2, prerequisites));
}

TEST(CourseSchedule, Empty) {
    vector<vector<int>> prerequisites;
    EXPECT_TRUE(canFinish(2, prerequisites));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
