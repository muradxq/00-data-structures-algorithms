/**
 * Problem: Min Cost Climbing Stairs
 * LeetCode #746
 * Difficulty: Easy
 * Pattern: 1D
 *
 * Each step has a cost. Find minimum cost to reach top.
 *
 * Example:
 *   Input: cost = [10,15,20]
 *   Output: 15 (Start at index 1, pay 15, jump to top)
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minCostClimbingStairs(vector<int>& cost) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinCostClimbingStairs, Example1) {
    vector<int> cost = {10, 15, 20};
    EXPECT_EQ(minCostClimbingStairs(cost), 15);
}

TEST(MinCostClimbingStairs, Example2) {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(minCostClimbingStairs(cost), 6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
