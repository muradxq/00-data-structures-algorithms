/**
 * Problem: Minimum Size Subarray Sum
 * LeetCode #209
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Find minimal length subarray with sum >= target.
 *
 * Example:
 *   Input: target = 7, nums = [2,3,1,2,4,3]
 *   Output: 2 ([4,3])
 */

#include <gtest/gtest.h>
#include <vector>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minSubArrayLen(int target, vector<int>& nums) {
    // Your implementation here
    int l = 0;
    int sum = 0;
    int minLen = INT_MAX;
    
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        
        // Shrink window while sum >= target
        while (sum >= target) {
            minLen = min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinSubarraySum, Example1) {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    EXPECT_EQ(minSubArrayLen(7, nums), 2);
}

TEST(MinSubarraySum, Example2) {
    vector<int> nums = {1, 4, 4};
    EXPECT_EQ(minSubArrayLen(4, nums), 1);
}

TEST(MinSubarraySum, NoSolution) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(minSubArrayLen(100, nums), 0);
}

TEST(MinSubarraySum, EntireArray) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(minSubArrayLen(15, nums), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
