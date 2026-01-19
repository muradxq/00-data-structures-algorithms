/**
 * Problem: Sequence Reconstruction
 * LeetCode #444 (Premium)
 * Difficulty: Medium
 * Pattern: Unique Order
 *
 * Check if org is the only sequence that can be reconstructed from seqs.
 *
 * Example:
 *   Input: org = [1,2,3], seqs = [[1,2],[1,3]]
 *   Output: false
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    // Your implementation here
    // Check if topological sort gives unique order matching org
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SequenceReconstruction, NotUnique) {
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}};
    EXPECT_FALSE(sequenceReconstruction(org, seqs));
}

TEST(SequenceReconstruction, Unique) {
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}, {2, 3}};
    EXPECT_TRUE(sequenceReconstruction(org, seqs));
}

TEST(SequenceReconstruction, SingleElement) {
    vector<int> org = {1};
    vector<vector<int>> seqs = {{1}};
    EXPECT_TRUE(sequenceReconstruction(org, seqs));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
