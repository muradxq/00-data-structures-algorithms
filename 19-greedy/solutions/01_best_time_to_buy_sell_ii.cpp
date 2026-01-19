/**
 * Problem: Best Time to Buy and Sell Stock II
 * LeetCode #122
 * Difficulty: Medium
 * Pattern: Trading
 *
 * Multiple transactions allowed. Maximum profit?
 *
 * Example:
 *   Input: prices = [7,1,5,3,6,4]
 *   Output: 7 (buy@1, sell@5, buy@3, sell@6)
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int maxProfit(vector<int>& prices) {
    // Your implementation here
    // Capture every positive difference
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(BestTimeToBuySellII, Example1) {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit(prices), 7);
}

TEST(BestTimeToBuySellII, Increasing) {
    vector<int> prices = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit(prices), 4);
}

TEST(BestTimeToBuySellII, Decreasing) {
    vector<int> prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit(prices), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
