/**
 * Problem: Partition Equal Subset Sum
 * LeetCode #416
 * Difficulty: Medium
 * Pattern: 0/1 Knapsack
 *
 * Can array be partitioned into two subsets with equal sum?
 *
 * Example:
 *   Input: nums = [1,5,11,5]
 *   Output: true ([1,5,5] and [11])
 */

#include <gtest/gtest.h>
#include <vector>
#include <numeric>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool canPartition(vector<int>& nums) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PartitionEqualSubsetSum, Example1) {
    vector<int> nums = {1, 5, 11, 5};
    EXPECT_TRUE(canPartition(nums));
}

TEST(PartitionEqualSubsetSum, Example2) {
    vector<int> nums = {1, 2, 3, 5};
    EXPECT_FALSE(canPartition(nums));
}

TEST(PartitionEqualSubsetSum, OddSum) {
    vector<int> nums = {1, 2, 5};
    EXPECT_FALSE(canPartition(nums));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
