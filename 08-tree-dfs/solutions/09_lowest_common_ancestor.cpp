/**
 * Problem: Lowest Common Ancestor of a Binary Tree
 * LeetCode #236
 * Difficulty: Medium
 * Pattern: Ancestor
 *
 * Find lowest common ancestor of two nodes.
 *
 * Example:
 *   Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 *   Output: 3
 */

#include <gtest/gtest.h>

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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Your implementation here
    
    return nullptr;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LCA, Example1) {
    TreeNode* root = new TreeNode(3);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    root->left = p;
    root->right = q;
    
    EXPECT_EQ(lowestCommonAncestor(root, p, q), root);
}

TEST(LCA, SameSubtree) {
    TreeNode* root = new TreeNode(3);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(4);
    root->left = p;
    p->right = new TreeNode(2);
    p->right->right = q;
    
    EXPECT_EQ(lowestCommonAncestor(root, p, q), p);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
