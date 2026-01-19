/**
 * Problem: Letter Combinations of a Phone Number
 * LeetCode #17
 * Difficulty: Medium
 * Pattern: Cartesian Product
 *
 * Generate all letter combinations for phone digits.
 *
 * Example:
 *   Input: digits = "23"
 *   Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<string> letterCombinations(string digits) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LetterCombinations, Example1) {
    auto result = letterCombinations("23");
    EXPECT_EQ(result.size(), 9);
}

TEST(LetterCombinations, SingleDigit) {
    auto result = letterCombinations("2");
    EXPECT_EQ(result.size(), 3);
}

TEST(LetterCombinations, Empty) {
    auto result = letterCombinations("");
    EXPECT_TRUE(result.empty());
}

TEST(LetterCombinations, WithSeven) {
    auto result = letterCombinations("7");
    EXPECT_EQ(result.size(), 4);  // pqrs
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
