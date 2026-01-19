/**
 * Problem: Diameter of Binary Tree
 * LeetCode #543
 * Difficulty: Medium
 * Pattern: Global Max
 *
 * Longest path between any two nodes.
 *
 * Example:
 *   Input: [1,2,3,4,5]
 *   Output: 3 (path: 4-2-1-3 or 5-2-1-3)
 */

#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int diameterOfBinaryTree(TreeNode* root) {
    // Your implementation here
    // Key: Diameter through a node = left_height + right_height
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Diameter, Example1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    EXPECT_EQ(diameterOfBinaryTree(root), 3);
}

TEST(Diameter, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(diameterOfBinaryTree(root), 0);
}

TEST(Diameter, TwoNodes) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    EXPECT_EQ(diameterOfBinaryTree(root), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
