/**
 * Problem: Minimum Depth of Binary Tree
 * LeetCode #111
 * Difficulty: Easy
 * Pattern: Min Depth
 *
 * Find minimum depth (shortest root-to-leaf path).
 *
 * Example:
 *   Input:     3
 *             / \
 *            9  20
 *              /  \
 *             15   7
 *   Output: 2 (path 3→9)
 *
 * Key Insight:
 *   - BFS finds shortest path first
 *   - Return immediately when leaf node found
 *
 * Constraints:
 *   - Number of nodes in range [0, 10^5]
 *   - -1000 <= Node.val <= 1000
 */

#include <gtest/gtest.h>
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
int minDepth(TreeNode* root) {
    // Your implementation here
    // BFS finds shortest path first - return when leaf found
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level =1;
    while (!q.empty()) {
        int levelSize = q.size(); 
        for(int i =0; i < levelSize; i++) {
            auto node = q.front();
            q.pop();
            if(!node->left && !node->right)
            return level;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        level++;
    }
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinDepth, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    EXPECT_EQ(minDepth(root), 2);
}

TEST(MinDepth, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(minDepth(root), 1);
}

TEST(MinDepth, Empty) {
    EXPECT_EQ(minDepth(nullptr), 0);
}

TEST(MinDepth, LeftSkewed) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    EXPECT_EQ(minDepth(root), 3);
}

TEST(MinDepth, RightSkewed) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    EXPECT_EQ(minDepth(root), 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
