/**
 * Problem: Longest Increasing Subsequence
 * LeetCode #300
 * Difficulty: Medium
 * Pattern: 1D
 *
 * Find length of longest strictly increasing subsequence.
 *
 * Example:
 *   Input: nums = [10,9,2,5,3,7,101,18]
 *   Output: 4 ([2,3,7,101])
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int lengthOfLIS(vector<int>& nums) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LIS, Example1) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(lengthOfLIS(nums), 4);
}

TEST(LIS, Increasing) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(lengthOfLIS(nums), 5);
}

TEST(LIS, Decreasing) {
    vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(lengthOfLIS(nums), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
