/**
 * Problem: Path Sum II
 * LeetCode #113
 * Difficulty: Medium
 * Pattern: All Paths
 *
 * Find all root-to-leaf paths with target sum.
 *
 * Example:
 *   Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 *   Output: [[5,4,11,2], [5,8,4,5]]
 */

#include <gtest/gtest.h>
#include <vector>

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
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    // Your implementation here
    // Use backtracking to collect all paths
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PathSumII, Example1) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    
    auto result = pathSum(root, 22);
    EXPECT_EQ(result.size(), 2);
}

TEST(PathSumII, Empty) {
    auto result = pathSum(nullptr, 0);
    EXPECT_TRUE(result.empty());
}

TEST(PathSumII, SingleMatch) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    auto result = pathSum(root, 3);
    EXPECT_EQ(result.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
