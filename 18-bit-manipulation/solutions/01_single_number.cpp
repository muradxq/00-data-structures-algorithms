/**
 * Problem: Single Number
 * LeetCode #136
 * Difficulty: Easy
 * Pattern: XOR
 *
 * Find element that appears once (others appear twice).
 *
 * Example:
 *   Input: nums = [2,2,1]
 *   Output: 1
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int singleNumber(vector<int>& nums) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SingleNumber, Example1) {
    vector<int> nums = {2,2,1};
    EXPECT_EQ(singleNumber(nums), 1);
}

TEST(SingleNumber, Example2) {
    vector<int> nums = {4,1,2,1,2};
    EXPECT_EQ(singleNumber(nums), 4);
}

TEST(SingleNumber, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(singleNumber(nums), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
