/**
 * Problem: Reverse Bits
 * LeetCode #190
 * Difficulty: Easy
 * Pattern: Manipulation
 *
 * Reverse bits of a 32-bit unsigned integer.
 *
 * Example:
 *   Input:  00000010100101000001111010011100
 *   Output: 00111001011110000010100101000000
 */

#include <gtest/gtest.h>
#include <cstdint>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
uint32_t reverseBits(uint32_t n) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ReverseBits, Example1) {
    // 43261596 = 00000010100101000001111010011100
    // reversed = 00111001011110000010100101000000 = 964176192
    EXPECT_EQ(reverseBits(43261596), 964176192);
}

TEST(ReverseBits, AllOnes) {
    EXPECT_EQ(reverseBits(0xFFFFFFFF), 0xFFFFFFFF);
}

TEST(ReverseBits, Zero) {
    EXPECT_EQ(reverseBits(0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
