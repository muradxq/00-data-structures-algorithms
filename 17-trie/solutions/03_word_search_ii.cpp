/**
 * Problem: Word Search II
 * LeetCode #212
 * Difficulty: Hard
 * Pattern: Grid + Trie
 *
 * Find all dictionary words in grid.
 *
 * Example:
 *   Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], 
 *          words = ["oath","pea","eat","rain"]
 *   Output: ["eat","oath"]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // Your implementation here
    // Build Trie from words, then DFS on board
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(WordSearchII, Example1) {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    auto result = findWords(board, words);
    
    unordered_set<string> resultSet(result.begin(), result.end());
    EXPECT_TRUE(resultSet.count("eat"));
    EXPECT_TRUE(resultSet.count("oath"));
    EXPECT_EQ(result.size(), 2);
}

TEST(WordSearchII, NoMatch) {
    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    vector<string> words = {"xyz"};
    auto result = findWords(board, words);
    EXPECT_TRUE(result.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
