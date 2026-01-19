/**
 * Problem: Maximum Average Subarray I
 * LeetCode #643
 * Difficulty: Easy
 * Pattern: Fixed Window
 *
 * Find contiguous subarray of length k with maximum average.
 *
 * Example:
 *   Input: nums = [1,12,-5,-6,50,3], k = 4
 *   Output: 12.75 (subarray [12,-5,-6,50])
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
double findMaxAverage(vector<int>& nums, int k) {
    // Your implementation here
    
    return 0.0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MaxAverageSubarray, Example1) {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    EXPECT_NEAR(findMaxAverage(nums, 4), 12.75, 0.00001);
}

TEST(MaxAverageSubarray, Example2) {
    vector<int> nums = {5};
    EXPECT_NEAR(findMaxAverage(nums, 1), 5.0, 0.00001);
}

TEST(MaxAverageSubarray, AllNegative) {
    vector<int> nums = {-1, -2, -3, -4};
    EXPECT_NEAR(findMaxAverage(nums, 2), -1.5, 0.00001);
}

TEST(MaxAverageSubarray, EntireArray) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_NEAR(findMaxAverage(nums, 5), 3.0, 0.00001);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
