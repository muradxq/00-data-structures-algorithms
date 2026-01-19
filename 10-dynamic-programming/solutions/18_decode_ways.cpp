/**
 * Problem: Decode Ways
 * LeetCode #91
 * Difficulty: Medium
 * Pattern: 1D
 *
 * Count ways to decode string of digits ('A'=1, 'B'=2, ..., 'Z'=26).
 *
 * Example:
 *   Input: s = "12"
 *   Output: 2 ("AB" or "L")
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int numDecodings(string s) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(DecodeWays, Example1) {
    EXPECT_EQ(numDecodings("12"), 2);
}

TEST(DecodeWays, Example2) {
    EXPECT_EQ(numDecodings("226"), 3);
}

TEST(DecodeWays, LeadingZero) {
    EXPECT_EQ(numDecodings("06"), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
