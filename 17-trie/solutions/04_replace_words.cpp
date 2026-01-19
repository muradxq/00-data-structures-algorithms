/**
 * Problem: Replace Words
 * LeetCode #648
 * Difficulty: Medium
 * Pattern: Prefix
 *
 * Replace words in sentence with their root from dictionary.
 *
 * Example:
 *   Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
 *   Output: "the cat was rat by the bat"
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
string replaceWords(vector<string>& dictionary, string sentence) {
    // Your implementation here
    // Build Trie from dictionary, find shortest prefix for each word
    
    return "";
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ReplaceWords, Example1) {
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    EXPECT_EQ(replaceWords(dictionary, sentence), "the cat was rat by the bat");
}

TEST(ReplaceWords, Example2) {
    vector<string> dictionary = {"a", "b", "c"};
    string sentence = "aadsfasf absbs bbab cadsfabd";
    EXPECT_EQ(replaceWords(dictionary, sentence), "a]a b c");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
