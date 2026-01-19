/**
 * Problem: Design Add and Search Words Data Structure
 * LeetCode #211
 * Difficulty: Medium
 * Pattern: Wildcard
 *
 * Support '.' wildcard in search.
 *
 * Example:
 *   addWord("bad"), addWord("dad"), addWord("mad")
 *   search("pad") -> false
 *   search("bad") -> true
 *   search(".ad") -> true
 *   search("b..") -> true
 */

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class WordDictionary {
public:
    WordDictionary() {
        // Your implementation here
    }
    
    void addWord(string word) {
        // Your implementation here
    }
    
    bool search(string word) {
        // Your implementation here
        // Handle '.' wildcard with recursion
        return false;
    }
    
private:
    // Trie node structure
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(WordDictionary, Example1) {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    EXPECT_FALSE(wd.search("pad"));
    EXPECT_TRUE(wd.search("bad"));
    EXPECT_TRUE(wd.search(".ad"));
    EXPECT_TRUE(wd.search("b.."));
}

TEST(WordDictionary, Empty) {
    WordDictionary wd;
    EXPECT_FALSE(wd.search("a"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
