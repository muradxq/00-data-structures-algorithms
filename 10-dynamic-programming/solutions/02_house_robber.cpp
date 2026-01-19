/**
 * Problem: House Robber
 * LeetCode #198
 * Difficulty: Medium
 * Pattern: 1D DP
 *
 * Can't rob adjacent houses. Maximize money.
 *
 * Example:
 *   Input: nums = [2,7,9,3,1]
 *   Output: 12 (2 + 9 + 1)
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
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(HouseRobber, Example1) {
    vector<int> nums = {1, 2, 3, 1};
    EXPECT_EQ(rob(nums), 4);
}

TEST(HouseRobber, Example2) {
    vector<int> nums = {2, 7, 9, 3, 1};
    EXPECT_EQ(rob(nums), 12);
}

TEST(HouseRobber, SingleHouse) {
    vector<int> nums = {5};
    EXPECT_EQ(rob(nums), 5);
}

TEST(HouseRobber, TwoHouses) {
    vector<int> nums = {1, 2};
    EXPECT_EQ(rob(nums), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
