/**
 * Problem: Populating Next Right Pointers in Each Node
 * LeetCode #116
 * Difficulty: Medium
 * Pattern: Connect Nodes
 *
 * Connect nodes at same level using next pointer.
 *
 * Example:
 *   Input:     1               1 → NULL
 *             / \             / \
 *            2   3           2 → 3 → NULL
 *           / \ / \         / \ / \
 *          4  5 6  7       4→5→6→7 → NULL
 *
 * Approach 1 (BFS):
 *   - Process level by level
 *   - Connect each node to next in queue
 *
 * Approach 2 (O(1) space for perfect binary tree):
 *   - Use already established next pointers
 *   - Process level by level using next pointers
 *
 * Constraints:
 *   - Number of nodes in range [0, 2^12 - 1]
 *   - -1000 <= Node.val <= 1000
 */

#include <gtest/gtest.h>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
Node* connect(Node* root) {
    // Your implementation here
    // BFS approach: connect nodes at each level
    // Or use O(1) space by using already established next pointers
    
    return root;
}

// ============================================================================
// Helper to verify connections
// ============================================================================
bool verifyLevel(Node* leftmost, vector<int>& expected) {
    int i = 0;
    Node* curr = leftmost;
    while (curr) {
        if (i >= expected.size() || curr->val != expected[i]) {
            return false;
        }
        curr = curr->next;
        i++;
    }
    return i == expected.size();
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PopulatingNextPointers, Example1) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    connect(root);
    
    // Verify connections
    EXPECT_EQ(root->next, nullptr);
    EXPECT_EQ(root->left->next, root->right);
    EXPECT_EQ(root->right->next, nullptr);
    EXPECT_EQ(root->left->left->next, root->left->right);
    EXPECT_EQ(root->left->right->next, root->right->left);
    EXPECT_EQ(root->right->left->next, root->right->right);
    EXPECT_EQ(root->right->right->next, nullptr);
}

TEST(PopulatingNextPointers, SingleNode) {
    Node* root = new Node(1);
    connect(root);
    EXPECT_EQ(root->next, nullptr);
}

TEST(PopulatingNextPointers, Empty) {
    EXPECT_EQ(connect(nullptr), nullptr);
}

TEST(PopulatingNextPointers, TwoLevels) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    connect(root);
    
    EXPECT_EQ(root->next, nullptr);
    EXPECT_EQ(root->left->next, root->right);
    EXPECT_EQ(root->right->next, nullptr);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
