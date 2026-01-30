/**
 * Problem: Cousins in Binary Tree
 * LeetCode #993
 * Difficulty: Easy
 * Pattern: Relationships
 *
 * Two nodes are cousins if they are at same depth but have different parents.
 *
 * Example:
 *   Input: root = [1,2,3,4], x = 4, y = 3
 *          1
 *         / \
 *        2   3
 *       /
 *      4
 *   Output: false (4 and 3 are at different depths)
 *
 *   Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 *          1
 *         / \
 *        2   3
 *         \   \
 *          4   5
 *   Output: true (4 and 5 are at same depth with different parents)
 *
 * Approach:
 *   - BFS level by level
 *   - Track parent of each node
 *   - Check if x and y found at same level with different parents
 *
 * Constraints:
 *   - Number of nodes in range [2, 100]
 *   - 1 <= Node.val <= 100
 *   - Each node has unique value
 *   - x != y
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
bool isCousins(TreeNode* root, int x, int y) {
    // Your implementation here
    // Track (node, parent) pairs
    // Check same level + different parents
    queue<tuple<TreeNode*, int, TreeNode*>> q;  // (node, depth, parent)
    q.push({root, 0, nullptr});
    
    int xDepth = -1, yDepth = -1;
    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;
    
    while (!q.empty()) {
        auto [node, depth, parent] = q.front();
        q.pop();
        
        // Check if this node is x or y
        if (node->val == x) {
            xDepth = depth;
            xParent = parent;
        }
        if (node->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        
        // Early exit if both found
        if (xDepth != -1 && yDepth != -1) {
            break;
        }
        
        if (node->left) {
            q.push({node->left, depth + 1, node});
        }
        if (node->right) {
            q.push({node->right, depth + 1, node});
        }
    }
    
    return xDepth == yDepth && xParent != yParent;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CousinsInBinaryTree, Example1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    EXPECT_FALSE(isCousins(root, 4, 3));
}

TEST(CousinsInBinaryTree, Example2) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    EXPECT_TRUE(isCousins(root, 5, 4));
}

TEST(CousinsInBinaryTree, Siblings) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    // Siblings are NOT cousins (same parent)
    EXPECT_FALSE(isCousins(root, 2, 3));
}

TEST(CousinsInBinaryTree, DifferentDepths) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    EXPECT_FALSE(isCousins(root, 2, 3));
}

TEST(CousinsInBinaryTree, ActualCousins) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    EXPECT_TRUE(isCousins(root, 4, 5));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
