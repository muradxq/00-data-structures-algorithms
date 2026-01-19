# 🌲 Tree DFS Pattern (Depth-First Search)

## Overview

**Tree DFS (Depth-First Search)** explores as far as possible along each branch before backtracking. It's implemented using recursion or an explicit stack. DFS is the preferred approach for path-based problems and subtree operations.

---

## 🧠 When to Use Tree DFS

Use this pattern when:
- Finding **paths** from root to leaves
- Computing **path sums** or **path properties**
- Problems involving **subtrees**
- Need to track **parent-to-child** relationships
- Keywords: "path", "sum", "height", "diameter", "subtree"

---

## 🎯 Types of DFS Traversals

```
        1
       / \
      2   3
     / \
    4   5

Pre-order  (Root, Left, Right): 1, 2, 4, 5, 3
In-order   (Left, Root, Right): 4, 2, 5, 1, 3
Post-order (Left, Right, Root): 4, 5, 2, 3, 1
```

### When to Use Each:
- **Pre-order:** When you need to process parent before children (copying trees, prefix expression)
- **In-order:** For BSTs - gives sorted order
- **Post-order:** When you need children's results first (calculating height, deleting trees)

---

## 📐 General Templates

### Recursive DFS Template
```cpp
void dfs(TreeNode* node) {
    if (!node) return;  // Base case
    
    // Pre-order: Process before children
    process(node);
    
    dfs(node->left);
    
    // In-order: Process between children
    
    dfs(node->right);
    
    // Post-order: Process after children
}
```

### DFS with Return Value
```cpp
int dfs(TreeNode* node) {
    if (!node) return 0;  // Base case
    
    int leftResult = dfs(node->left);
    int rightResult = dfs(node->right);
    
    // Combine results
    return combine(leftResult, rightResult, node->val);
}
```

### DFS with Path Tracking
```cpp
void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& result) {
    if (!node) return;
    
    path.push_back(node->val);
    
    // Check if leaf
    if (!node->left && !node->right) {
        result.push_back(path);  // Found complete path
    }
    
    dfs(node->left, path, result);
    dfs(node->right, path, result);
    
    path.pop_back();  // Backtrack
}
```

### Iterative DFS Template
```cpp
void iterativeDfs(TreeNode* root) {
    if (!root) return;
    
    stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        process(node);
        
        // Push right first so left is processed first
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}
```

---

## 💡 Key Insights

### 1. Passing Information Down vs Up
```cpp
// Passing DOWN (via parameters)
void dfs(TreeNode* node, int sumSoFar) {
    sumSoFar += node->val;
    dfs(node->left, sumSoFar);
}

// Passing UP (via return values)
int dfs(TreeNode* node) {
    int leftHeight = dfs(node->left);
    int rightHeight = dfs(node->right);
    return 1 + max(leftHeight, rightHeight);
}
```

### 2. Global Variables vs Return Values
```cpp
// Global variable approach (simpler for some problems)
class Solution {
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    
    int dfs(TreeNode* node) {
        // ... update maxSum
    }
};
```

### 3. Leaf vs Non-Leaf Handling
```cpp
int dfs(TreeNode* node) {
    // Leaf node
    if (!node->left && !node->right) {
        return handleLeaf(node);
    }
    
    // Non-leaf: recurse
    // ...
}
```

---

## 📊 Complexity Analysis

| Traversal | Time | Space |
|-----------|------|-------|
| Any DFS | O(n) | O(h) |

Where h = height of tree (O(log n) balanced, O(n) skewed)

---

## 🎓 Example Walkthrough: Path Sum

**Problem:** Determine if tree has root-to-leaf path with given sum.

```
Input:     5       targetSum = 22
          / \
         4   8
        /   / \
       11  13  4
      /  \      \
     7    2      1

Path: 5 → 4 → 11 → 2 = 22 ✓
```

**Solution:**
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    // Update target as we go down
    targetSum -= root->val;
    
    // Check if leaf with zero remaining
    if (!root->left && !root->right) {
        return targetSum == 0;
    }
    
    // Try both subtrees
    return hasPathSum(root->left, targetSum) || 
           hasPathSum(root->right, targetSum);
}
```

---

## 🔗 Related Patterns

- **Tree BFS:** Alternative traversal (level-by-level)
- **Backtracking:** DFS is the foundation of backtracking
- **Graph DFS:** Same concept but needs visited tracking

---

## 🚨 Common Mistakes

1. **Wrong base case:** Returning at `node == nullptr` vs checking leaf
2. **Forgetting to backtrack:** Remove element from path after processing
3. **Confusing traversal orders:** Know which order suits your problem
4. **Stack overflow:** Deep trees may need iterative approach

---

*Next: [See Practice Questions →](./questions.md)*
