/**
 * Problem: Maximum Depth of Binary Tree
 * LeetCode #104
 * Difficulty: Easy
 * Pattern: Height
 *
 * Find maximum depth of binary tree.
 *
 * Example:
 *   Input: [3,9,20,null,null,15,7]
 *   Output: 3
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
int maxDepth(TreeNode* root) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MaxDepth, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    EXPECT_EQ(maxDepth(root), 3);
}

TEST(MaxDepth, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(maxDepth(root), 1);
}

TEST(MaxDepth, Empty) {
    EXPECT_EQ(maxDepth(nullptr), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
