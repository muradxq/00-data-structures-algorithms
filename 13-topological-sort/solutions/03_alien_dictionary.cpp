/**
 * Problem: Alien Dictionary
 * LeetCode #269 (Premium)
 * Difficulty: Hard
 * Pattern: Build Graph
 *
 * Derive alphabet order from sorted alien words.
 *
 * Example:
 *   Input: words = ["wrt","wrf","er","ett","rftt"]
 *   Output: "wertf"
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
string alienOrder(vector<string>& words) {
    // Your implementation here
    // Build graph from adjacent word comparisons, then topological sort
    
    return "";
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(AlienDictionary, Example1) {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string result = alienOrder(words);
    // Valid result contains all chars in correct order
    EXPECT_FALSE(result.empty());
}

TEST(AlienDictionary, InvalidOrder) {
    vector<string> words = {"abc", "ab"};  // Invalid: prefix comes after
    string result = alienOrder(words);
    EXPECT_TRUE(result.empty());
}

TEST(AlienDictionary, SingleWord) {
    vector<string> words = {"z"};
    string result = alienOrder(words);
    EXPECT_EQ(result, "z");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
