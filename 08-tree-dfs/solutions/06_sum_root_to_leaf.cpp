/**
 * Problem: Sum Root to Leaf Numbers
 * LeetCode #129
 * Difficulty: Medium
 * Pattern: Path Value
 *
 * Each root-to-leaf path represents a number. Find total sum.
 *
 * Example:
 *   Input:     1
 *             / \
 *            2   3
 *   Numbers: 12, 13
 *   Output: 25
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
int sumNumbers(TreeNode* root) {
    // Your implementation here
    // Track current number as you traverse
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SumRootToLeaf, Example1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    EXPECT_EQ(sumNumbers(root), 25);  // 12 + 13
}

TEST(SumRootToLeaf, Example2) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    
    EXPECT_EQ(sumNumbers(root), 1026);  // 495 + 491 + 40
}

TEST(SumRootToLeaf, SingleNode) {
    TreeNode* root = new TreeNode(5);
    EXPECT_EQ(sumNumbers(root), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
