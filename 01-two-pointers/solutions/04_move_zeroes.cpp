/**
 * Problem: Move Zeroes
 * LeetCode #283
 * Difficulty: Easy
 * Pattern: Same Direction (Fast & Slow)
 *
 * Move all zeroes to the end while maintaining relative order of non-zero elements.
 * Must do this in-place without making a copy of the array.
 *
 * Example:
 *   Input: nums = [0,1,0,3,12]
 *   Output: [1,3,12,0,0]
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^4
 *   - -2^31 <= nums[i] <= 2^31 - 1
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
void moveZeroes(vector<int>& nums) {
    // Your implementation here
    
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MoveZeroes, Example1) {
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> expected = {1, 3, 12, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, Example2) {
    vector<int> nums = {0};
    vector<int> expected = {0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, NoZeroes) {
    vector<int> nums = {1, 2, 3};
    vector<int> expected = {1, 2, 3};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, AllZeroes) {
    vector<int> nums = {0, 0, 0};
    vector<int> expected = {0, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, ZeroesAtEnd) {
    vector<int> nums = {1, 2, 0, 0};
    vector<int> expected = {1, 2, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, ZeroesAtStart) {
    vector<int> nums = {0, 0, 1, 2};
    vector<int> expected = {1, 2, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroes, SingleNonZero) {
    vector<int> nums = {1};
    vector<int> expected = {1};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
