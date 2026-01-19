/**
 * Problem: Validate Binary Search Tree
 * LeetCode #98
 * Difficulty: Medium
 * Pattern: BST
 *
 * Check if tree is valid BST.
 *
 * Example:
 *   Input: [2,1,3]
 *   Output: true
 */

#include <gtest/gtest.h>
#include <climits>

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
bool isValidBST(TreeNode* root) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ValidateBST, Valid) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    EXPECT_TRUE(isValidBST(root));
}

TEST(ValidateBST, Invalid) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    
    EXPECT_FALSE(isValidBST(root));
}

TEST(ValidateBST, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_TRUE(isValidBST(root));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
