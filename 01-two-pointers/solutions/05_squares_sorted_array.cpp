/**
 * Problem: Squares of a Sorted Array
 * LeetCode #977
 * Difficulty: Easy
 * Pattern: Opposite Direction
 *
 * Given sorted array (may have negatives), return sorted array of squares.
 *
 * Example:
 *   Input: nums = [-4,-1,0,3,10]
 *   Output: [0,1,9,16,100]
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^4
 *   - -10^4 <= nums[i] <= 10^4
 *   - nums is sorted in non-decreasing order
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> sortedSquares(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SortedSquares, Example1) {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> expected = {0, 1, 9, 16, 100};
    EXPECT_EQ(sortedSquares(nums), expected);
}

TEST(SortedSquares, Example2) {
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> expected = {4, 9, 9, 49, 121};
    EXPECT_EQ(sortedSquares(nums), expected);
}

TEST(SortedSquares, AllPositive) {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 4, 9, 16, 25};
    EXPECT_EQ(sortedSquares(nums), expected);
}

TEST(SortedSquares, AllNegative) {
    vector<int> nums = {-5, -4, -3, -2, -1};
    vector<int> expected = {1, 4, 9, 16, 25};
    EXPECT_EQ(sortedSquares(nums), expected);
}

TEST(SortedSquares, SingleElement) {
    vector<int> nums = {-3};
    vector<int> expected = {9};
    EXPECT_EQ(sortedSquares(nums), expected);
}

TEST(SortedSquares, WithZero) {
    vector<int> nums = {-2, 0, 2};
    vector<int> expected = {0, 4, 4};
    EXPECT_EQ(sortedSquares(nums), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
