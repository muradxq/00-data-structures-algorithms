/**
 * Problem: Binary Tree Maximum Path Sum
 * LeetCode #124
 * Difficulty: Hard
 * Pattern: Global Max
 *
 * Find max path sum (path can start and end at any node).
 *
 * Example:
 *   Input:     -10
 *             /   \
 *            9    20
 *                /  \
 *               15   7
 *   Output: 42 (path: 15-20-7)
 */

#include <gtest/gtest.h>
#include <algorithm>
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
int maxPathSum(TreeNode* root) {
    // Your implementation here
    // Track global max while computing max gain from each node
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MaxPathSum, Example1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    EXPECT_EQ(maxPathSum(root), 6);
}

TEST(MaxPathSum, Example2) {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    EXPECT_EQ(maxPathSum(root), 42);
}

TEST(MaxPathSum, SingleNegative) {
    TreeNode* root = new TreeNode(-3);
    EXPECT_EQ(maxPathSum(root), -3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
