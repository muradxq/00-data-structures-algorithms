/**
 * Problem: Same Tree
 * LeetCode #100
 * Difficulty: Easy
 * Pattern: Compare
 *
 * Check if two binary trees are identical.
 *
 * Example:
 *   Input: p = [1,2,3], q = [1,2,3]
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
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SameTree, BothSame) {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    EXPECT_TRUE(isSameTree(p, q));
}

TEST(SameTree, Different) {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);
    
    EXPECT_FALSE(isSameTree(p, q));
}

TEST(SameTree, BothEmpty) {
    EXPECT_TRUE(isSameTree(nullptr, nullptr));
}

TEST(SameTree, OneEmpty) {
    TreeNode* p = new TreeNode(1);
    EXPECT_FALSE(isSameTree(p, nullptr));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
