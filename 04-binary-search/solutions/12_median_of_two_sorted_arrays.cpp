/**
 * Problem: Median of Two Sorted Arrays
 * LeetCode #4
 * Difficulty: Hard
 * Pattern: Advanced Binary Search
 *
 * Find median of two sorted arrays in O(log(m+n)).
 *
 * Example:
 *   Input: nums1 = [1,3], nums2 = [2]
 *   Output: 2.0
 */

#include <gtest/gtest.h>
#include <vector>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Your implementation here
    // Key: Binary search for correct partition
    
    return 0.0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MedianTwoArrays, Example1) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    EXPECT_NEAR(findMedianSortedArrays(nums1, nums2), 2.0, 0.00001);
}

TEST(MedianTwoArrays, Example2) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    EXPECT_NEAR(findMedianSortedArrays(nums1, nums2), 2.5, 0.00001);
}

TEST(MedianTwoArrays, OneEmpty) {
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    EXPECT_NEAR(findMedianSortedArrays(nums1, nums2), 1.0, 0.00001);
}

TEST(MedianTwoArrays, OneEmpty2) {
    vector<int> nums1 = {2};
    vector<int> nums2 = {};
    EXPECT_NEAR(findMedianSortedArrays(nums1, nums2), 2.0, 0.00001);
}

TEST(MedianTwoArrays, SameElements) {
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {1, 1};
    EXPECT_NEAR(findMedianSortedArrays(nums1, nums2), 1.0, 0.00001);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
