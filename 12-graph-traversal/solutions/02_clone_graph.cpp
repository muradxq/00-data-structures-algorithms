/**
 * Problem: Clone Graph
 * LeetCode #133
 * Difficulty: Medium
 * Pattern: DFS/BFS
 *
 * Return deep copy of graph.
 *
 * Example:
 *   Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
 *   Output: [[2,4],[1,3],[2,4],[1,3]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
Node* cloneGraph(Node* node) {
    // Your implementation here
    
    return nullptr;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CloneGraph, Empty) {
    EXPECT_EQ(cloneGraph(nullptr), nullptr);
}

TEST(CloneGraph, SingleNode) {
    Node* node = new Node(1);
    Node* clone = cloneGraph(node);
    EXPECT_NE(clone, nullptr);
    EXPECT_EQ(clone->val, 1);
    EXPECT_NE(clone, node);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
