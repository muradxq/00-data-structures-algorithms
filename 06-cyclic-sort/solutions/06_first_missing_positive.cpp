/**
 * Problem: First Missing Positive
 * LeetCode #41
 * Difficulty: Hard
 * Pattern: Find Missing
 *
 * Find smallest missing positive integer.
 *
 * Example:
 *   Input: nums = [3,4,-1,1]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int firstMissingPositive(vector<int>& nums) {
    // Your implementation here
    // Key: Answer must be in range [1, n+1]
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FirstMissingPositive, Example1) {
    vector<int> nums = {1, 2, 0};
    EXPECT_EQ(firstMissingPositive(nums), 3);
}

TEST(FirstMissingPositive, Example2) {
    vector<int> nums = {3, 4, -1, 1};
    EXPECT_EQ(firstMissingPositive(nums), 2);
}

TEST(FirstMissingPositive, Example3) {
    vector<int> nums = {7, 8, 9, 11, 12};
    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, Consecutive) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(firstMissingPositive(nums), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
