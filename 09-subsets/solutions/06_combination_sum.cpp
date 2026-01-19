/**
 * Problem: Combination Sum
 * LeetCode #39
 * Difficulty: Medium
 * Pattern: Unlimited Use
 *
 * Find combinations that sum to target. Numbers can be used unlimited times.
 *
 * Example:
 *   Input: candidates = [2,3,6,7], target = 7
 *   Output: [[2,2,3],[7]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CombinationSum, Example1) {
    vector<int> candidates = {2, 3, 6, 7};
    auto result = combinationSum(candidates, 7);
    EXPECT_EQ(result.size(), 2);
}

TEST(CombinationSum, Example2) {
    vector<int> candidates = {2, 3, 5};
    auto result = combinationSum(candidates, 8);
    EXPECT_EQ(result.size(), 3);
}

TEST(CombinationSum, NoSolution) {
    vector<int> candidates = {2};
    auto result = combinationSum(candidates, 1);
    EXPECT_EQ(result.size(), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
