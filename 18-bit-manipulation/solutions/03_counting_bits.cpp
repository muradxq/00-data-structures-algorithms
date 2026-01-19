/**
 * Problem: Counting Bits
 * LeetCode #338
 * Difficulty: Easy
 * Pattern: DP + Bits
 *
 * Count bits for all numbers from 0 to n.
 *
 * Example:
 *   Input: n = 5
 *   Output: [0,1,1,2,1,2]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> countBits(int n) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CountingBits, Example1) {
    vector<int> expected = {0,1,1};
    EXPECT_EQ(countBits(2), expected);
}

TEST(CountingBits, Example2) {
    vector<int> expected = {0,1,1,2,1,2};
    EXPECT_EQ(countBits(5), expected);
}

TEST(CountingBits, Zero) {
    vector<int> expected = {0};
    EXPECT_EQ(countBits(0), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
