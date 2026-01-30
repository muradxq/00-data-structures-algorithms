/**
 * Problem: Binary Tree Level Order Traversal
 * LeetCode #102
 * Difficulty: Medium
 * Pattern: Basic BFS
 *
 * Return nodes level by level.
 *
 * Example:
 *   Input: [3,9,20,null,null,15,7]
 *   Output: [[3], [9,20], [15,7]]
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
vector<vector<int>> levelOrder(TreeNode* root) {
    // Your implementation here
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
    return res;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LevelOrder, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> expected = {{3}, {9, 20}, {15, 7}};
    EXPECT_EQ(levelOrder(root), expected);
}

TEST(LevelOrder, SingleNode) {
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(levelOrder(root), expected);
}

TEST(LevelOrder, Empty) {
    vector<vector<int>> expected = {};
    EXPECT_EQ(levelOrder(nullptr), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
