/**
 * Problem: Binary Tree Right Side View
 * LeetCode #199
 * Difficulty: Medium
 * Pattern: Side View
 *
 * Return values visible from right side.
 *
 * Example:
 *   Input:     1
 *             / \
 *            2   3
 *             \   \
 *              5   4
 *   Output: [1, 3, 4]
 *
 * Approach:
 *   - BFS level by level
 *   - Last node in each level is visible from right
 *
 * Constraints:
 *   - Number of nodes in range [0, 100]
 *   - -100 <= Node.val <= 100
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

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
vector<int> rightSideView(TreeNode* root) {
    // Your implementation here
    // Hint: Take last node from each level
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RightSideView, Example1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    vector<int> expected = {1, 3, 4};
    EXPECT_EQ(rightSideView(root), expected);
}

TEST(RightSideView, LeftOnly) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    vector<int> expected = {1, 2, 3};
    EXPECT_EQ(rightSideView(root), expected);
}

TEST(RightSideView, Empty) {
    vector<int> expected = {};
    EXPECT_EQ(rightSideView(nullptr), expected);
}

TEST(RightSideView, SingleNode) {
    TreeNode* root = new TreeNode(1);
    vector<int> expected = {1};
    EXPECT_EQ(rightSideView(root), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
