/**
 * Problem: Find Minimum in Rotated Sorted Array
 * LeetCode #153
 * Difficulty: Medium
 * Pattern: Modified Binary Search
 *
 * Find minimum element in rotated sorted array.
 *
 * Example:
 *   Input: nums = [3,4,5,1,2]
 *   Output: 1
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findMin(vector<int>& nums) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FindMin, Example1) {
    vector<int> nums = {3, 4, 5, 1, 2};
    EXPECT_EQ(findMin(nums), 1);
}

TEST(FindMin, Example2) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(findMin(nums), 0);
}

TEST(FindMin, Example3) {
    vector<int> nums = {11, 13, 15, 17};
    EXPECT_EQ(findMin(nums), 11);
}

TEST(FindMin, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(findMin(nums), 1);
}

TEST(FindMin, TwoElements) {
    vector<int> nums = {2, 1};
    EXPECT_EQ(findMin(nums), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
