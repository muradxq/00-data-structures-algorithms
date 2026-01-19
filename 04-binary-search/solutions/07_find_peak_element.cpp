/**
 * Problem: Find Peak Element
 * LeetCode #162
 * Difficulty: Medium
 * Pattern: Modified Binary Search
 *
 * Find any peak element (greater than neighbors).
 *
 * Example:
 *   Input: nums = [1,2,3,1]
 *   Output: 2 (index of peak element 3)
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findPeakElement(vector<int>& nums) {
    // Your implementation here
    // Key: Move toward the higher neighbor
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FindPeak, Example1) {
    vector<int> nums = {1, 2, 3, 1};
    EXPECT_EQ(findPeakElement(nums), 2);
}

TEST(FindPeak, Example2) {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int result = findPeakElement(nums);
    EXPECT_TRUE(result == 1 || result == 5); // Either peak is valid
}

TEST(FindPeak, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(findPeakElement(nums), 0);
}

TEST(FindPeak, Increasing) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(findPeakElement(nums), 4);
}

TEST(FindPeak, Decreasing) {
    vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(findPeakElement(nums), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
