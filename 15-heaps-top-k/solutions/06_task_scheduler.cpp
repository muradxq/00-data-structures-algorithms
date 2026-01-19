/**
 * Problem: Task Scheduler
 * LeetCode #621
 * Difficulty: Medium
 * Pattern: Greedy + Heap
 *
 * Find minimum intervals to execute all tasks with cooldown.
 *
 * Example:
 *   Input: tasks = ["A","A","A","B","B","B"], n = 2
 *   Output: 8 (A -> B -> idle -> A -> B -> idle -> A -> B)
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int leastInterval(vector<char>& tasks, int n) {
    // Your implementation here
    // Use max-heap to always schedule most frequent task
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(TaskScheduler, Example1) {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(leastInterval(tasks, 2), 8);
}

TEST(TaskScheduler, NoCooldown) {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(leastInterval(tasks, 0), 6);
}

TEST(TaskScheduler, SingleTask) {
    vector<char> tasks = {'A', 'A', 'A'};
    EXPECT_EQ(leastInterval(tasks, 2), 7);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
