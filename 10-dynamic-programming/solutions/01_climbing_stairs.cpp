/**
 * Problem: Climbing Stairs
 * LeetCode #70
 * Difficulty: Easy
 * Pattern: 1D DP
 *
 * n steps to top. Can climb 1 or 2 steps. How many ways?
 *
 * Example:
 *   Input: n = 3
 *   Output: 3 (1+1+1, 1+2, 2+1)
 */

#include <gtest/gtest.h>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int climbStairs(int n) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ClimbingStairs, Example1) {
    EXPECT_EQ(climbStairs(2), 2);
}

TEST(ClimbingStairs, Example2) {
    EXPECT_EQ(climbStairs(3), 3);
}

TEST(ClimbingStairs, One) {
    EXPECT_EQ(climbStairs(1), 1);
}

TEST(ClimbingStairs, Five) {
    EXPECT_EQ(climbStairs(5), 8);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
