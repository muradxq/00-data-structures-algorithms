/**
 * Problem: Burst Balloons
 * LeetCode #312
 * Difficulty: Hard
 * Pattern: Interval
 *
 * Burst balloons to maximize coins.
 *
 * Example:
 *   Input: nums = [3,1,5,8]
 *   Output: 167
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int maxCoins(vector<int>& nums) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(BurstBalloons, Example1) {
    vector<int> nums = {3, 1, 5, 8};
    EXPECT_EQ(maxCoins(nums), 167);
}

TEST(BurstBalloons, SingleBalloon) {
    vector<int> nums = {1, 5};
    EXPECT_EQ(maxCoins(nums), 10);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
