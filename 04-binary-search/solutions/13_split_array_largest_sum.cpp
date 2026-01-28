/**
 * Problem: Split Array Largest Sum
 * LeetCode #410
 * Difficulty: Hard
 * Pattern: Answer Space Binary Search
 *
 * Split array into k subarrays to minimize largest sum.
 *
 * Example:
 *   Input: nums = [7,2,5,10,8], k = 2
 *   Output: 18 (Split: [7,2,5] and [10,8])
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int splitArray(vector<int>& nums, int k) {
    // Your implementation here
    // Hint: Binary search on [max(nums), sum(nums)]
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    while (l < r) {
        int mid = l + (r - l) / 2;
        // Can we split with max subarray sum = mid?
        int subarrays = 1;
        int currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > mid) {
                subarrays++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        if (subarrays <= k) {
            r = mid;      // Can do it, try smaller max sum
        } else {
            l = mid + 1;  // Need larger max sum
        }
    }
    
    return l;
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SplitArray, Example1) {
    vector<int> nums = {7, 2, 5, 10, 8};
    EXPECT_EQ(splitArray(nums, 2), 18);
}

TEST(SplitArray, Example2) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(splitArray(nums, 2), 9);
}

TEST(SplitArray, SingleElement) {
    vector<int> nums = {1, 4, 4};
    EXPECT_EQ(splitArray(nums, 3), 4);
}

TEST(SplitArray, KEqualsN) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(splitArray(nums, 3), 3);
}

TEST(SplitArray, KEqualsOne) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(splitArray(nums, 1), 15);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
