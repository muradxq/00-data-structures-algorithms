/**
 * Problem: Employee Free Time
 * LeetCode #759 (Premium)
 * Difficulty: Hard
 * Pattern: Merge
 *
 * Find common free time across all employees.
 * Each employee has a list of non-overlapping intervals representing working times.
 *
 * Example:
 *   Input: schedule = [[[1,2],[5,6]], [[1,3]], [[4,10]]]
 *   Output: [[3,4]]
 *   Explanation: 
 *     Employee 1: busy [1,2] and [5,6]
 *     Employee 2: busy [1,3]
 *     Employee 3: busy [4,10]
 *     Combined busy: [1,3] and [4,10]
 *     Free time: [3,4]
 *
 * Approach:
 *   1. Flatten all intervals
 *   2. Sort by start time
 *   3. Merge overlapping intervals (find all busy times)
 *   4. Find gaps between merged intervals (free times)
 *
 * Constraints:
 *   - 1 <= schedule.length, schedule[i].length <= 50
 *   - 0 <= start < end <= 10^8
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    // Step 1: Flatten all intervals into one list
    vector<vector<int>> intervals;
    for (auto& employee : schedule) {
        for (auto& interval : employee) {
            intervals.push_back(interval);
        }
    }
    
    if (intervals.empty()) return {};
    
    // Step 2: Sort by start time
    sort(intervals.begin(), intervals.end());
    
    // Step 3: Merge overlapping intervals
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            // Overlap - extend
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // No overlap - add new interval
            merged.push_back(intervals[i]);
        }
    }
    
    // Step 4: Find gaps between merged intervals (free times)
    vector<vector<int>> freeTime;
    for (size_t i = 1; i < merged.size(); i++) {
        freeTime.push_back({merged[i-1][1], merged[i][0]});
    }
    
    return freeTime;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(EmployeeFreeTime, Example1) {
    vector<vector<vector<int>>> schedule = {{{1,2},{5,6}}, {{1,3}}, {{4,10}}};
    vector<vector<int>> expected = {{3,4}};
    EXPECT_EQ(employeeFreeTime(schedule), expected);
}

TEST(EmployeeFreeTime, Example2) {
    vector<vector<vector<int>>> schedule = {{{1,3},{6,7}}, {{2,4}}, {{2,5},{9,12}}};
    vector<vector<int>> expected = {{5,6},{7,9}};
    EXPECT_EQ(employeeFreeTime(schedule), expected);
}

TEST(EmployeeFreeTime, NoFreeTime) {
    vector<vector<vector<int>>> schedule = {{{1,10}}, {{1,10}}};
    vector<vector<int>> expected = {};
    EXPECT_EQ(employeeFreeTime(schedule), expected);
}

TEST(EmployeeFreeTime, SingleEmployee) {
    vector<vector<vector<int>>> schedule = {{{1,2},{3,4}}};
    vector<vector<int>> expected = {{2,3}};
    EXPECT_EQ(employeeFreeTime(schedule), expected);
}

TEST(EmployeeFreeTime, MultipleFreeSlots) {
    vector<vector<vector<int>>> schedule = {{{1,2}}, {{5,6}}, {{9,10}}};
    vector<vector<int>> expected = {{2,5},{6,9}};
    EXPECT_EQ(employeeFreeTime(schedule), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
