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
    // Key: Move toward the higher neighbor
    int l = 0; 
    int r = nums.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1]) {
            // Peak is at mid or to the left
            r = mid;
        } else {
            // Peak is to the right
            l = mid + 1;
        }
    }
    return l;
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
