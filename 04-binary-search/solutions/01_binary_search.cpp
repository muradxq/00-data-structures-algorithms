/**
 * Problem: Binary Search
 * LeetCode #704
 * Difficulty: Easy
 * Pattern: Standard
 *
 * Standard binary search for target in sorted array.
 *
 * Example:
 *   Input: nums = [-1,0,3,5,9,12], target = 9
 *   Output: 4
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int search(vector<int>& nums, int target) {
    // Your implementation here
    
    return -1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(BinarySearch, Example1) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(search(nums, 9), 4);
}

TEST(BinarySearch, Example2) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(search(nums, 2), -1);
}

TEST(BinarySearch, SingleElement) {
    vector<int> nums = {5};
    EXPECT_EQ(search(nums, 5), 0);
}

TEST(BinarySearch, FirstElement) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(search(nums, 1), 0);
}

TEST(BinarySearch, LastElement) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(search(nums, 5), 4);
}

TEST(BinarySearch, NotFound) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(search(nums, 6), -1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
