/**
 * Problem: Sqrt(x)
 * LeetCode #69
 * Difficulty: Easy
 * Pattern: Answer Space
 *
 * Compute integer square root of x.
 *
 * Example:
 *   Input: x = 8
 *   Output: 2 (sqrt(8) ≈ 2.83, truncate to 2)
 */

#include <gtest/gtest.h>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int mySqrt(int x) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Sqrt, Example1) {
    EXPECT_EQ(mySqrt(4), 2);
}

TEST(Sqrt, Example2) {
    EXPECT_EQ(mySqrt(8), 2);
}

TEST(Sqrt, Zero) {
    EXPECT_EQ(mySqrt(0), 0);
}

TEST(Sqrt, One) {
    EXPECT_EQ(mySqrt(1), 1);
}

TEST(Sqrt, PerfectSquare) {
    EXPECT_EQ(mySqrt(16), 4);
}

TEST(Sqrt, Large) {
    EXPECT_EQ(mySqrt(2147395599), 46339);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
