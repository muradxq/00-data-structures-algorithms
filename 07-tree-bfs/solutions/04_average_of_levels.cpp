/**
 * Problem: Average of Levels in Binary Tree
 * LeetCode #637
 * Difficulty: Easy
 * Pattern: Level Stats
 *
 * Return average value of nodes at each level.
 *
 * Example:
 *   Input:     3
 *             / \
 *            9  20
 *              /  \
 *             15   7
 *   Output: [3.0, 14.5, 11.0]
 *
 * Approach:
 *   - Standard BFS
 *   - Calculate sum and count for each level
 *
 * Constraints:
 *   - Number of nodes in range [1, 10^4]
 *   - -2^31 <= Node.val <= 2^31 - 1
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
vector<double> averageOfLevels(TreeNode* root) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(AverageOfLevels, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<double> result = averageOfLevels(root);
    ASSERT_EQ(result.size(), 3);
    EXPECT_NEAR(result[0], 3.0, 0.00001);
    EXPECT_NEAR(result[1], 14.5, 0.00001);
    EXPECT_NEAR(result[2], 11.0, 0.00001);
}

TEST(AverageOfLevels, SingleNode) {
    TreeNode* root = new TreeNode(5);
    vector<double> result = averageOfLevels(root);
    ASSERT_EQ(result.size(), 1);
    EXPECT_NEAR(result[0], 5.0, 0.00001);
}

TEST(AverageOfLevels, BalancedTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<double> result = averageOfLevels(root);
    ASSERT_EQ(result.size(), 2);
    EXPECT_NEAR(result[0], 1.0, 0.00001);
    EXPECT_NEAR(result[1], 2.5, 0.00001);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
