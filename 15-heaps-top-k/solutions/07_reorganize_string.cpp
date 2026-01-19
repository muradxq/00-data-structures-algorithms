/**
 * Problem: Reorganize String
 * LeetCode #767
 * Difficulty: Medium
 * Pattern: Greedy + Heap
 *
 * Reorganize string so no two adjacent chars are the same.
 *
 * Example:
 *   Input: s = "aab"
 *   Output: "aba"
 */

#include <gtest/gtest.h>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
string reorganizeString(string s) {
    // Your implementation here
    // Use max-heap to always place most frequent char
    
    return "";
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ReorganizeString, Example1) {
    string result = reorganizeString("aab");
    EXPECT_EQ(result, "aba");
}

TEST(ReorganizeString, Impossible) {
    string result = reorganizeString("aaab");
    EXPECT_TRUE(result.empty());
}

TEST(ReorganizeString, AllSame) {
    string result = reorganizeString("a");
    EXPECT_EQ(result, "a");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
