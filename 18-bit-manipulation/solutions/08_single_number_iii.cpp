/**
 * Problem: Single Number III
 * LeetCode #260
 * Difficulty: Medium
 * Pattern: XOR + Partition
 *
 * Find two elements that appear once (others appear twice).
 *
 * Example:
 *   Input: nums = [1,2,1,3,2,5]
 *   Output: [3,5]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> singleNumber(vector<int>& nums) {
    // Your implementation here
    // XOR all, find diff bit, partition by that bit
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SingleNumberIII, Example1) {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    auto result = singleNumber(nums);
    sort(result.begin(), result.end());
    vector<int> expected = {3, 5};
    EXPECT_EQ(result, expected);
}

TEST(SingleNumberIII, Example2) {
    vector<int> nums = {-1, 0};
    auto result = singleNumber(nums);
    sort(result.begin(), result.end());
    vector<int> expected = {-1, 0};
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
