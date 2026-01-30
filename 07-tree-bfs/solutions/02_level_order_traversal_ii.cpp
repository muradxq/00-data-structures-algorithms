/**
 * Problem: Binary Tree Level Order Traversal II
 * LeetCode #107
 * Difficulty: Medium
 * Pattern: Reverse
 *
 * Return level order from bottom to top.
 *
 * Example:
 *   Input:     3
 *             / \
 *            9  20
 *              /  \
 *             15   7
 *   Output: [[15,7], [9,20], [3]]
 *
 * Approach:
 *   - Standard BFS level order traversal
 *   - Reverse result at the end (or insert at front)
 *
 * Constraints:
 *   - Number of nodes <= 2000
 *   - -1000 <= Node.val <= 1000
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>
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
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    // Your implementation here
    // Hint: Do standard BFS, then reverse the result
    if(!root) return {};
    vector<vector<int>> res; 
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for(int i =0; i < levelSize; i++) {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        res.push_back(level);
    }
    reverse(res.begin(), res.end());
    return res;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LevelOrderBottom, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> expected = {{15, 7}, {9, 20}, {3}};
    EXPECT_EQ(levelOrderBottom(root), expected);
}

TEST(LevelOrderBottom, SingleNode) {
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(levelOrderBottom(root), expected);
}

TEST(LevelOrderBottom, Empty) {
    vector<vector<int>> expected = {};
    EXPECT_EQ(levelOrderBottom(nullptr), expected);
}

TEST(LevelOrderBottom, TwoLevels) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<vector<int>> expected = {{2, 3}, {1}};
    EXPECT_EQ(levelOrderBottom(root), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
