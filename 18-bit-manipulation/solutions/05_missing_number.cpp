/**
 * Problem: Missing Number
 * LeetCode #268
 * Difficulty: Easy
 * Pattern: XOR
 *
 * Find missing number in [0, n].
 *
 * Example:
 *   Input: nums = [3,0,1]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int missingNumber(vector<int>& nums) {
    // Your implementation here
    // XOR all numbers with indices
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MissingNumber, Example1) {
    vector<int> nums = {3, 0, 1};
    EXPECT_EQ(missingNumber(nums), 2);
}

TEST(MissingNumber, Example2) {
    vector<int> nums = {0, 1};
    EXPECT_EQ(missingNumber(nums), 2);
}

TEST(MissingNumber, ZeroMissing) {
    vector<int> nums = {1};
    EXPECT_EQ(missingNumber(nums), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
