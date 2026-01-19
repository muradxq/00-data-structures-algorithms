/**
 * Problem: Meeting Rooms
 * LeetCode #252 (Premium)
 * Difficulty: Easy
 * Pattern: Overlap Check
 *
 * Determine if a person could attend all meetings.
 *
 * Example:
 *   Input: [[0,30],[5,10],[15,20]]
 *   Output: false (meetings overlap)
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool canAttendMeetings(vector<vector<int>>& intervals) {
    // Your implementation here
    
    return true;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MeetingRooms, Example1) {
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    EXPECT_FALSE(canAttendMeetings(intervals));
}

TEST(MeetingRooms, Example2) {
    vector<vector<int>> intervals = {{7,10},{2,4}};
    EXPECT_TRUE(canAttendMeetings(intervals));
}

TEST(MeetingRooms, Empty) {
    vector<vector<int>> intervals = {};
    EXPECT_TRUE(canAttendMeetings(intervals));
}

TEST(MeetingRooms, SingleMeeting) {
    vector<vector<int>> intervals = {{1,5}};
    EXPECT_TRUE(canAttendMeetings(intervals));
}

TEST(MeetingRooms, Adjacent) {
    vector<vector<int>> intervals = {{1,5},{5,10}};
    EXPECT_TRUE(canAttendMeetings(intervals));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
