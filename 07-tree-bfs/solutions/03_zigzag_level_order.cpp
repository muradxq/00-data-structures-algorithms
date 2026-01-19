/**
 * Problem: Binary Tree Zigzag Level Order Traversal
 * LeetCode #103
 * Difficulty: Medium
 * Pattern: Zigzag
 *
 * Zigzag level order (alternate left-right, right-left).
 *
 * Example:
 *   Input:     3
 *             / \
 *            9  20
 *              /  \
 *             15   7
 *   Output: [[3], [20,9], [15,7]]
 *
 * Approach:
 *   - Standard BFS with direction flag
 *   - Use deque to add from front or back based on direction
 *
 * Constraints:
 *   - Number of nodes <= 2000
 *   - -100 <= Node.val <= 100
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <deque>

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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Your implementation here
    // Hint: Toggle direction each level
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ZigzagOrder, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> expected = {{3}, {20, 9}, {15, 7}};
    EXPECT_EQ(zigzagLevelOrder(root), expected);
}

TEST(ZigzagOrder, SingleNode) {
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(zigzagLevelOrder(root), expected);
}

TEST(ZigzagOrder, Empty) {
    vector<vector<int>> expected = {};
    EXPECT_EQ(zigzagLevelOrder(nullptr), expected);
}

TEST(ZigzagOrder, FourLevels) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    vector<vector<int>> expected = {{1}, {3, 2}, {4, 5}};
    EXPECT_EQ(zigzagLevelOrder(root), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
