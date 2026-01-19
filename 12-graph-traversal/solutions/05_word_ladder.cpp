/**
 * Problem: Word Ladder
 * LeetCode #127
 * Difficulty: Hard
 * Pattern: BFS Shortest Path
 *
 * Find shortest transformation from beginWord to endWord.
 *
 * Example:
 *   Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 *   Output: 5 ("hit" -> "hot" -> "dot" -> "dog" -> "cog")
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(WordLadder, Example1) {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    EXPECT_EQ(ladderLength("hit", "cog", wordList), 5);
}

TEST(WordLadder, NoSolution) {
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    EXPECT_EQ(ladderLength("hit", "cog", wordList), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
