/**
 * Problem: Generate Parentheses
 * LeetCode #22
 * Difficulty: Medium
 * Pattern: Valid Sequences
 *
 * Generate all valid combinations of n pairs of parentheses.
 *
 * Example:
 *   Input: n = 3
 *   Output: ["((()))","(()())","(())()","()(())","()()()"]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<string> generateParenthesis(int n) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(GenerateParentheses, N3) {
    auto result = generateParenthesis(3);
    EXPECT_EQ(result.size(), 5);
}

TEST(GenerateParentheses, N1) {
    auto result = generateParenthesis(1);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "()");
}

TEST(GenerateParentheses, N2) {
    auto result = generateParenthesis(2);
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
