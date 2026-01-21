/**
 * Problem: Max Consecutive Ones III
 * LeetCode #1004
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Find longest subarray of 1s after flipping at most k 0s.
 *
 * Example:
 *   Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 *   Output: 6
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int longestOnes(vector<int>& nums, int k) {
    // Your implementation here
    int l = 0;
    int maxLen = 0;
    int numZeros = 0;
    for (int r = 0; r < nums.size(); r++) {
        // update status
        if(nums[r] == 0) numZeros++;
        // shrink windows
        while(numZeros > k) {
            if (nums[l] == 0)
                numZeros--;
            l++;
        }
        // valid window
        maxLen = max(maxLen, r-l+1);
    }
    return maxLen;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MaxConsecutiveOnes, Example1) {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    EXPECT_EQ(longestOnes(nums, 2), 6);
}

TEST(MaxConsecutiveOnes, Example2) {
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    EXPECT_EQ(longestOnes(nums, 3), 10);
}

TEST(MaxConsecutiveOnes, AllOnes) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(longestOnes(nums, 0), 4);
}

TEST(MaxConsecutiveOnes, AllZeros) {
    vector<int> nums = {0, 0, 0, 0};
    EXPECT_EQ(longestOnes(nums, 2), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
