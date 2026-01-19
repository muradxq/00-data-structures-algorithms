/**
 * Problem: Coin Change
 * LeetCode #322
 * Difficulty: Medium
 * Pattern: Unbounded Knapsack
 *
 * Minimum coins to make amount.
 *
 * Example:
 *   Input: coins = [1,2,5], amount = 11
 *   Output: 3 (5+5+1)
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int coinChange(vector<int>& coins, int amount) {
    // Your implementation here
    
    return -1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CoinChange, Example1) {
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(coinChange(coins, 11), 3);
}

TEST(CoinChange, Example2) {
    vector<int> coins = {2};
    EXPECT_EQ(coinChange(coins, 3), -1);
}

TEST(CoinChange, Zero) {
    vector<int> coins = {1};
    EXPECT_EQ(coinChange(coins, 0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
