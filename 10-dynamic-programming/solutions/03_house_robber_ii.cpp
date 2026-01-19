/**
 * Problem: House Robber II
 * LeetCode #213
 * Difficulty: Medium
 * Pattern: 1D Circular
 *
 * Houses in a circle (first and last are adjacent).
 *
 * Example:
 *   Input: nums = [2,3,2]
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int rob(vector<int>& nums) {
    // Your implementation here
    // Either skip first house or skip last house
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(HouseRobberII, Example1) {
    vector<int> nums = {2, 3, 2};
    EXPECT_EQ(rob(nums), 3);
}

TEST(HouseRobberII, Example2) {
    vector<int> nums = {1, 2, 3, 1};
    EXPECT_EQ(rob(nums), 4);
}

TEST(HouseRobberII, SingleHouse) {
    vector<int> nums = {5};
    EXPECT_EQ(rob(nums), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
