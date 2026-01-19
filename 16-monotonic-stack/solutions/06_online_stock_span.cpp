/**
 * Problem: Online Stock Span
 * LeetCode #901
 * Difficulty: Medium
 * Pattern: Span
 *
 * Find span of stock prices (consecutive days with price <= today).
 *
 * Example:
 *   next(100) = 1, next(80) = 1, next(60) = 1
 *   next(70) = 2, next(60) = 1, next(75) = 4
 */

#include <gtest/gtest.h>
#include <stack>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class StockSpanner {
public:
    StockSpanner() {
        // Your implementation here
    }
    
    int next(int price) {
        // Your implementation here
        return 0;
    }
    
private:
    // Use stack of (price, span) pairs
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(StockSpanner, Example1) {
    StockSpanner ss;
    EXPECT_EQ(ss.next(100), 1);
    EXPECT_EQ(ss.next(80), 1);
    EXPECT_EQ(ss.next(60), 1);
    EXPECT_EQ(ss.next(70), 2);
    EXPECT_EQ(ss.next(60), 1);
    EXPECT_EQ(ss.next(75), 4);
    EXPECT_EQ(ss.next(85), 6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
