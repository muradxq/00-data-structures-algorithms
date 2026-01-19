/**
 * Problem: Palindrome Partitioning
 * LeetCode #131
 * Difficulty: Medium
 * Pattern: String
 *
 * Partition string so every substring is a palindrome.
 *
 * Example:
 *   Input: s = "aab"
 *   Output: [["a","a","b"],["aa","b"]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<string>> partition(string s) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PalindromePartition, Example1) {
    auto result = partition("aab");
    EXPECT_EQ(result.size(), 2);
}

TEST(PalindromePartition, SingleChar) {
    auto result = partition("a");
    EXPECT_EQ(result.size(), 1);
}

TEST(PalindromePartition, AllPalindrome) {
    auto result = partition("aa");
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
