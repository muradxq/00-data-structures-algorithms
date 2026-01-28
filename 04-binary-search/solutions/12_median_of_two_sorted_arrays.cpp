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
    // Ensure nums1 is smaller
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size(), n = nums2.size();
    int l = 0, r = m;
    int half = (m + n + 1) / 2;
    
    while (l <= r) {
        int i = l + (r - l) / 2;   // Partition in nums1
        int j = half - i;          // Partition in nums2
        
        int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int R1 = (i == m) ? INT_MAX : nums1[i];
        int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int R2 = (j == n) ? INT_MAX : nums2[j];
        
        if (L1 > R2) {
            r = i - 1;  // Too far right in nums1
        } else if (L2 > R1) {
            l = i + 1;  // Too far left in nums1
        } else {
            // Valid partition found
            if ((m + n) % 2 == 1) {
                return max(L1, L2);  // Odd: median is max of left
            }
            return (max(L1, L2) + min(R1, R2)) / 2.0;  // Even: average
        }
    }
    
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
