/**
 * Problem: Path Sum
 * LeetCode #112
 * Difficulty: Easy
 * Pattern: Path
 *
 * Check if root-to-leaf path with target sum exists.
 *
 * Example:
 *   Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 *   Output: true
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
bool hasPathSum(TreeNode* root, int targetSum) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PathSum, Example1) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    
    EXPECT_TRUE(hasPathSum(root, 22));
}

TEST(PathSum, NoPath) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    EXPECT_FALSE(hasPathSum(root, 5));
}

TEST(PathSum, Empty) {
    EXPECT_FALSE(hasPathSum(nullptr, 0));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
