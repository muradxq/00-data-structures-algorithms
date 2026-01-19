/**
 * Problem: Sum of Two Integers
 * LeetCode #371
 * Difficulty: Medium
 * Pattern: No arithmetic
 *
 * Sum without + or - operators.
 *
 * Example:
 *   Input: a = 1, b = 2
 *   Output: 3
 */

#include <gtest/gtest.h>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int getSum(int a, int b) {
    // Your implementation here
    // XOR for sum, AND for carry
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SumOfTwoIntegers, Positive) {
    EXPECT_EQ(getSum(1, 2), 3);
}

TEST(SumOfTwoIntegers, Negative) {
    EXPECT_EQ(getSum(-1, 1), 0);
}

TEST(SumOfTwoIntegers, BothNegative) {
    EXPECT_EQ(getSum(-1, -2), -3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
