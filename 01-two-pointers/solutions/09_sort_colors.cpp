/**
 * Problem: Sort Colors (Dutch National Flag)
 * LeetCode #75
 * Difficulty: Medium
 * Pattern: Three Pointers
 *
 * Sort array with only 0, 1, 2 in-place using one-pass algorithm.
 *
 * Example:
 *   Input: nums = [2,0,2,1,1,0]
 *   Output: [0,0,1,1,2,2]
 *
 * Constraints:
 *   - n == nums.length
 *   - 1 <= n <= 300
 *   - nums[i] is 0, 1, or 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
void sortColors(vector<int>& nums) {
    // Your implementation here
    // Hint: Use three pointers - low, mid, high
    // 0s go to low region, 2s go to high region
    
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SortColors, Example1) {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> expected = {0, 0, 1, 1, 2, 2};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, Example2) {
    vector<int> nums = {2, 0, 1};
    vector<int> expected = {0, 1, 2};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, AllSame) {
    vector<int> nums = {1, 1, 1};
    vector<int> expected = {1, 1, 1};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, AlreadySorted) {
    vector<int> nums = {0, 0, 1, 1, 2, 2};
    vector<int> expected = {0, 0, 1, 1, 2, 2};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, ReverseSorted) {
    vector<int> nums = {2, 2, 1, 1, 0, 0};
    vector<int> expected = {0, 0, 1, 1, 2, 2};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, SingleElement) {
    vector<int> nums = {0};
    vector<int> expected = {0};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

TEST(SortColors, OnlyZerosAndTwos) {
    vector<int> nums = {2, 0, 2, 0, 2, 0};
    vector<int> expected = {0, 0, 0, 2, 2, 2};
    sortColors(nums);
    EXPECT_EQ(nums, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
