/**
 * Problem: Single Number II
 * LeetCode #137
 * Difficulty: Medium
 * Pattern: Bit Count
 *
 * Every element appears three times except one.
 *
 * Example:
 *   Input: nums = [2,2,3,2]
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int singleNumber(vector<int>& nums) {
    // Your implementation here
    // Count bits modulo 3
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SingleNumberII, Example1) {
    vector<int> nums = {2, 2, 3, 2};
    EXPECT_EQ(singleNumber(nums), 3);
}

TEST(SingleNumberII, Example2) {
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    EXPECT_EQ(singleNumber(nums), 99);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
