/**
 * Problem: Target Sum
 * LeetCode #494
 * Difficulty: Medium
 * Pattern: Knapsack Variant
 *
 * Count ways to assign +/- to make target sum.
 *
 * Example:
 *   Input: nums = [1,1,1,1,1], target = 3
 *   Output: 5
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findTargetSumWays(vector<int>& nums, int target) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(TargetSum, Example1) {
    vector<int> nums = {1, 1, 1, 1, 1};
    EXPECT_EQ(findTargetSumWays(nums, 3), 5);
}

TEST(TargetSum, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(findTargetSumWays(nums, 1), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
