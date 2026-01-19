/**
 * Problem: Find First and Last Position of Element in Sorted Array
 * LeetCode #34
 * Difficulty: Medium
 * Pattern: Boundary
 *
 * Find starting and ending position of target.
 *
 * Example:
 *   Input: nums = [5,7,7,8,8,10], target = 8
 *   Output: [3,4]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> searchRange(vector<int>& nums, int target) {
    // Your implementation here
    // Hint: Use two binary searches - one for left bound, one for right
    
    return {-1, -1};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SearchRange, Example1) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> expected = {3, 4};
    EXPECT_EQ(searchRange(nums, 8), expected);
}

TEST(SearchRange, Example2) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> expected = {-1, -1};
    EXPECT_EQ(searchRange(nums, 6), expected);
}

TEST(SearchRange, EmptyArray) {
    vector<int> nums = {};
    vector<int> expected = {-1, -1};
    EXPECT_EQ(searchRange(nums, 0), expected);
}

TEST(SearchRange, SingleElement) {
    vector<int> nums = {5};
    vector<int> expected = {0, 0};
    EXPECT_EQ(searchRange(nums, 5), expected);
}

TEST(SearchRange, AllSame) {
    vector<int> nums = {5, 5, 5, 5, 5};
    vector<int> expected = {0, 4};
    EXPECT_EQ(searchRange(nums, 5), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
