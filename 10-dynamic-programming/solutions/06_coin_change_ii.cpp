/**
 * Problem: Coin Change II
 * LeetCode #518
 * Difficulty: Medium
 * Pattern: Count Ways
 *
 * Count number of ways to make amount.
 *
 * Example:
 *   Input: amount = 5, coins = [1,2,5]
 *   Output: 4 (5, 2+2+1, 2+1+1+1, 1+1+1+1+1)
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int change(int amount, vector<int>& coins) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CoinChangeII, Example1) {
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(change(5, coins), 4);
}

TEST(CoinChangeII, NoWays) {
    vector<int> coins = {2};
    EXPECT_EQ(change(3, coins), 0);
}

TEST(CoinChangeII, Zero) {
    vector<int> coins = {10};
    EXPECT_EQ(change(0, coins), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
