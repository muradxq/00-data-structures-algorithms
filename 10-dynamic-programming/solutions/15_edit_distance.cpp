/**
 * Problem: Edit Distance
 * LeetCode #72
 * Difficulty: Medium
 * Pattern: 2D String
 *
 * Minimum operations (insert, delete, replace) to convert word1 to word2.
 *
 * Example:
 *   Input: word1 = "horse", word2 = "ros"
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minDistance(string word1, string word2) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(EditDistance, Example1) {
    EXPECT_EQ(minDistance("horse", "ros"), 3);
}

TEST(EditDistance, Example2) {
    EXPECT_EQ(minDistance("intention", "execution"), 5);
}

TEST(EditDistance, Empty) {
    EXPECT_EQ(minDistance("", "abc"), 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
