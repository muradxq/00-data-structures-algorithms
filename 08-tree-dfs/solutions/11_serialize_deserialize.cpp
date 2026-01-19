/**
 * Problem: Serialize and Deserialize Binary Tree
 * LeetCode #297
 * Difficulty: Hard
 * Pattern: Structure
 *
 * Convert tree to string and back.
 *
 * Example:
 *   Input: [1,2,3,null,null,4,5]
 *   Serialized: "1,2,null,null,3,4,null,null,5,null,null"
 */

#include <gtest/gtest.h>
#include <string>
#include <sstream>
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Your implementation here
        
        return "";
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Your implementation here
        
        return nullptr;
    }
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SerializeDeserialize, Example1) {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    EXPECT_EQ(deserialized->val, 1);
    EXPECT_EQ(deserialized->left->val, 2);
    EXPECT_EQ(deserialized->right->val, 3);
}

TEST(SerializeDeserialize, Empty) {
    Codec codec;
    string serialized = codec.serialize(nullptr);
    TreeNode* deserialized = codec.deserialize(serialized);
    EXPECT_EQ(deserialized, nullptr);
}

TEST(SerializeDeserialize, SingleNode) {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    EXPECT_EQ(deserialized->val, 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
