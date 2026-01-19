/**
 * Problem: Implement Trie (Prefix Tree)
 * LeetCode #208
 * Difficulty: Medium
 * Pattern: Basic Trie
 *
 * Implement insert, search, and startsWith.
 */

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class Trie {
public:
    Trie() {
        // Your implementation here
    }
    
    void insert(string word) {
        // Your implementation here
    }
    
    bool search(string word) {
        // Your implementation here
        return false;
    }
    
    bool startsWith(string prefix) {
        // Your implementation here
        return false;
    }
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Trie, BasicOperations) {
    Trie trie;
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_FALSE(trie.search("app"));
    EXPECT_TRUE(trie.startsWith("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("app"));
}

TEST(Trie, EmptySearch) {
    Trie trie;
    EXPECT_FALSE(trie.search("a"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
