/**
 * Problem: Subarray Product Less Than K
 * LeetCode #713
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Count subarrays where product of all elements is less than k.
 *
 * Example:
 *   Input: nums = [10,5,2,6], k = 100
 *   Output: 8
 *   Explanation: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]
 *
 * Key Insight:
 *   - For each ending position, count new valid subarrays
 *   - New subarrays ending at 'end' = end - start + 1
 *
 * Constraints:
 *   - 1 <= nums.length <= 3 * 10^4
 *   - 1 <= nums[i] <= 1000
 *   - 0 <= k <= 10^6
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // Your implementation here
    // Track product, shrink when product >= k
    // Count subarrays ending at each position
    if (k <= 1) return 0;  // Edge case: no subarray can have product < 1 or < 0
    
    int l = 0;
    int count = 0;
    long long product = 1;  // Use long long to avoid overflow
    
    for (int r = 0; r < nums.size(); r++) {
        product *= nums[r];
        // Shrink window while product >= k
        while (l <= r && product >= k) {
            product /= nums[l];
            l++;
        }
        // Count all subarrays ending at r: [l..r], [l+1..r], ..., [r..r]
        count += (r - l + 1);
    }
    
    return count;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SubarrayProduct, Example1) {
    vector<int> nums = {10, 5, 2, 6};
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 100), 8);
}

TEST(SubarrayProduct, Example2) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 0), 0);
}

TEST(SubarrayProduct, AllValid) {
    vector<int> nums = {1, 1, 1};
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 2), 6);
}

TEST(SubarrayProduct, SingleElement) {
    vector<int> nums = {5};
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 10), 1);
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 5), 0);
}

TEST(SubarrayProduct, LargeK) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(numSubarrayProductLessThanK(nums, 1000), 15);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
