/**
 * Problem: Next Greater Element I
 * LeetCode #496
 * Difficulty: Easy
 * Pattern: Next Greater
 *
 * Find next greater element from nums2 for each element in nums1.
 *
 * Example:
 *   Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 *   Output: [-1,3,-1]
 */

#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NextGreaterElementI, Example1) {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> expected = {-1, 3, -1};
    EXPECT_EQ(nextGreaterElement(nums1, nums2), expected);
}

TEST(NextGreaterElementI, Example2) {
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> expected = {3, -1};
    EXPECT_EQ(nextGreaterElement(nums1, nums2), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
