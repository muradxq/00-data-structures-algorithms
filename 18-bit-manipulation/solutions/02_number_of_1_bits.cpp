/**
 * Problem: Number of 1 Bits
 * LeetCode #191
 * Difficulty: Easy
 * Pattern: Count Bits
 *
 * Count set bits (Hamming weight).
 *
 * Example:
 *   Input: n = 11 (binary: 1011)
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <cstdint>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int hammingWeight(uint32_t n) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(HammingWeight, Example1) {
    EXPECT_EQ(hammingWeight(11), 3);
}

TEST(HammingWeight, Example2) {
    EXPECT_EQ(hammingWeight(128), 1);
}

TEST(HammingWeight, AllOnes) {
    EXPECT_EQ(hammingWeight(0xFFFFFFFF), 32);
}

TEST(HammingWeight, Zero) {
    EXPECT_EQ(hammingWeight(0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
