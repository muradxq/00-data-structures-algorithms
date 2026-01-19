/**
 * Problem: Jump Game
 * LeetCode #55
 * Difficulty: Medium
 * Pattern: Reachability
 *
 * Can you reach the last index?
 *
 * Example:
 *   Input: nums = [2,3,1,1,4]
 *   Output: true
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool canJump(vector<int>& nums) {
    // Your implementation here
    // Track max reachable position
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(JumpGame, CanReach) {
    vector<int> nums = {2, 3, 1, 1, 4};
    EXPECT_TRUE(canJump(nums));
}

TEST(JumpGame, CannotReach) {
    vector<int> nums = {3, 2, 1, 0, 4};
    EXPECT_FALSE(canJump(nums));
}

TEST(JumpGame, SingleElement) {
    vector<int> nums = {0};
    EXPECT_TRUE(canJump(nums));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
