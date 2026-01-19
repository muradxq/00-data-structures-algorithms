/**
 * Problem: Meeting Rooms II
 * LeetCode #253 (Premium)
 * Difficulty: Medium
 * Pattern: Count Rooms
 *
 * Find minimum number of conference rooms required.
 *
 * Example:
 *   Input: [[0,30],[5,10],[15,20]]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minMeetingRooms(vector<vector<int>>& intervals) {
    // Your implementation here
    // Approach 1: Two pointers with sorted starts/ends
    // Approach 2: Min heap tracking end times
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MeetingRoomsII, Example1) {
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    EXPECT_EQ(minMeetingRooms(intervals), 2);
}

TEST(MeetingRoomsII, Example2) {
    vector<vector<int>> intervals = {{7,10},{2,4}};
    EXPECT_EQ(minMeetingRooms(intervals), 1);
}

TEST(MeetingRoomsII, Empty) {
    vector<vector<int>> intervals = {};
    EXPECT_EQ(minMeetingRooms(intervals), 0);
}

TEST(MeetingRoomsII, AllOverlap) {
    vector<vector<int>> intervals = {{1,5},{2,6},{3,7}};
    EXPECT_EQ(minMeetingRooms(intervals), 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
