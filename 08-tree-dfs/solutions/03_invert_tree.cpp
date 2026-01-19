/**
 * Problem: Invert Binary Tree
 * LeetCode #226
 * Difficulty: Easy
 * Pattern: Transform
 *
 * Mirror/invert a binary tree.
 *
 * Example:
 *   Input: [4,2,7,1,3,6,9]
 *   Output: [4,7,2,9,6,3,1]
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
TreeNode* invertTree(TreeNode* root) {
    // Your implementation here
    
    return nullptr;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(InvertTree, Example1) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode* inverted = invertTree(root);
    EXPECT_EQ(inverted->val, 4);
    EXPECT_EQ(inverted->left->val, 7);
    EXPECT_EQ(inverted->right->val, 2);
}

TEST(InvertTree, Empty) {
    EXPECT_EQ(invertTree(nullptr), nullptr);
}

TEST(InvertTree, SingleNode) {
    TreeNode* root = new TreeNode(1);
    TreeNode* inverted = invertTree(root);
    EXPECT_EQ(inverted->val, 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
