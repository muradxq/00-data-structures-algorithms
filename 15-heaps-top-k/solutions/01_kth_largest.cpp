/**
 * Problem: Kth Largest Element in an Array
 * LeetCode #215
 * Difficulty: Medium
 * Pattern: Top K
 *
 * Find kth largest element.
 *
 * Example:
 *   Input: nums = [3,2,1,5,6,4], k = 2
 *   Output: 5
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findKthLargest(vector<int>& nums, int k) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(KthLargest, Example1) {
    vector<int> nums = {3,2,1,5,6,4};
    EXPECT_EQ(findKthLargest(nums, 2), 5);
}

TEST(KthLargest, Example2) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(findKthLargest(nums, 4), 4);
}

TEST(KthLargest, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(findKthLargest(nums, 1), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
