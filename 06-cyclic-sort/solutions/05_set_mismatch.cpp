/**
 * Problem: Set Mismatch
 * LeetCode #645
 * Difficulty: Easy
 * Pattern: Missing + Duplicate
 *
 * Find the duplicate and missing number.
 *
 * Example:
 *   Input: nums = [1,2,2,4]
 *   Output: [2,3] (2 is duplicated, 3 is missing)
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findErrorNums(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SetMismatch, Example1) {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> expected = {2, 3};
    EXPECT_EQ(findErrorNums(nums), expected);
}

TEST(SetMismatch, Example2) {
    vector<int> nums = {1, 1};
    vector<int> expected = {1, 2};
    EXPECT_EQ(findErrorNums(nums), expected);
}

TEST(SetMismatch, DuplicateAtEnd) {
    vector<int> nums = {2, 2};
    vector<int> expected = {2, 1};
    EXPECT_EQ(findErrorNums(nums), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
