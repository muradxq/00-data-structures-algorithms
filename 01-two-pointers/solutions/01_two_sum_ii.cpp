/**
 * Problem: Two Sum II - Input Array Is Sorted
 * LeetCode #167
 * Difficulty: Easy
 * Pattern: Opposite Direction
 *
 * Given a 1-indexed sorted array, find two numbers that add up to target.
 * Return indices of the two numbers (1-indexed).
 *
 * Example:
 *   Input: numbers = [2,7,11,15], target = 9
 *   Output: [1,2]
 *   Explanation: numbers[0] + numbers[1] = 2 + 7 = 9
 *
 * Constraints:
 *   - Array is sorted in non-decreasing order
 *   - Exactly one solution exists
 *   - Cannot use same element twice
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> twoSum(vector<int>& numbers, int target) {
    // Your implementation here
    int left = 0;
    int right = numbers.size()-1;
    while(left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            return {left+1, right+1};
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(TwoSumII, Example1) {
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> expected = {1, 2};
    EXPECT_EQ(twoSum(numbers, 9), expected);
}

TEST(TwoSumII, Example2) {
    vector<int> numbers = {2, 3, 4};
    vector<int> expected = {1, 3};
    EXPECT_EQ(twoSum(numbers, 6), expected);
}

TEST(TwoSumII, Example3) {
    vector<int> numbers = {-1, 0};
    vector<int> expected = {1, 2};
    EXPECT_EQ(twoSum(numbers, -1), expected);
}

TEST(TwoSumII, LargerArray) {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> expected = {1, 10};
    EXPECT_EQ(twoSum(numbers, 11), expected);
}

TEST(TwoSumII, NegativeNumbers) {
    vector<int> numbers = {-5, -3, -1, 2, 4, 6};
    vector<int> expected = {2, 6};
    EXPECT_EQ(twoSum(numbers, 3), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
