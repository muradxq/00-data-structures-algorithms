# 📝 Tree DFS - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Maximum Depth of Binary Tree | Easy | Height | ⬜ |
| 2 | Same Tree | Easy | Compare | ⬜ |
| 3 | Invert Binary Tree | Easy | Transform | ⬜ |
| 4 | Path Sum | Easy | Path | ⬜ |
| 5 | Path Sum II | Medium | All Paths | ⬜ |
| 6 | Sum Root to Leaf Numbers | Medium | Path Value | ⬜ |
| 7 | Diameter of Binary Tree | Medium | Global Max | ⬜ |
| 8 | Binary Tree Maximum Path Sum | Hard | Global Max | ⬜ |
| 9 | Lowest Common Ancestor | Medium | Ancestor | ⬜ |
| 10 | Validate Binary Search Tree | Medium | BST | ⬜ |
| 11 | Serialize and Deserialize | Hard | Structure | ⬜ |

---

## 🟢 Easy Problems

### 1. Maximum Depth of Binary Tree
**LeetCode #104**

Find maximum depth of binary tree.

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: 3
```

**Approach:**
- Recursively find max depth of left and right subtrees
- Add 1 for current node

**Solution:**
```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + max(leftDepth, rightDepth);
}
```
**Complexity:** Time O(n), Space O(h) where h is tree height

---

### 2. Same Tree
**LeetCode #100**

Check if two trees are identical.

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Approach:**
- Compare root values, then recursively compare subtrees

**Solution:**
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```
**Complexity:** Time O(n), Space O(h)

---

### 3. Invert Binary Tree
**LeetCode #226**

Mirror/invert a binary tree.

```
Input:     4           Output:     4
          / \                     / \
         2   7                   7   2
        / \ / \                 / \ / \
       1  3 6  9               9  6 3  1
```

**Approach:**
- Swap left and right children
- Recursively invert subtrees

**Solution:**
```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    // Swap children
    swap(root->left, root->right);
    
    // Recurse
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
```
**Complexity:** Time O(n), Space O(h)

---

### 4. Path Sum
**LeetCode #112**

Check if root-to-leaf path with target sum exists.

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true (5→4→11→2)
```

**Approach:**
- Subtract current value from target
- At leaf, check if remaining target is 0

**Solution:**
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    targetSum -= root->val;
    
    // Leaf node check
    if (!root->left && !root->right) {
        return targetSum == 0;
    }
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
```
**Complexity:** Time O(n), Space O(h)

---

## 🟡 Medium Problems

### 5. Path Sum II
**LeetCode #113**

Find all root-to-leaf paths with target sum.

```
Input:     5         targetSum = 22
          / \
         4   8
        /   / \
       11  13  4
      /  \    / \
     7    2  5   1
Output: [[5,4,11,2], [5,8,4,5]]
```

**Approach:**
- Track current path
- When leaf with correct sum found, add path to result
- Backtrack after exploring

**Solution:**
```cpp
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int target) {
        if (!node) return;
        
        path.push_back(node->val);
        target -= node->val;
        
        if (!node->left && !node->right && target == 0) {
            result.push_back(path);
        }
        
        dfs(node->left, target);
        dfs(node->right, target);
        
        path.pop_back();  // Backtrack
    };
    
    dfs(root, targetSum);
    return result;
}
```
**Complexity:** Time O(n²), Space O(n)

---

### 6. Sum Root to Leaf Numbers
**LeetCode #129**

Each root-to-leaf path represents a number. Find total sum.

```
Input:     1
          / \
         2   3
Numbers: 12, 13
Output: 25
```

**Approach:**
- Pass current number down (multiply by 10 and add current value)
- At leaf, return the number

**Solution:**
```cpp
int sumNumbers(TreeNode* root) {
    function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int currentNum) -> int {
        if (!node) return 0;
        
        currentNum = currentNum * 10 + node->val;
        
        // Leaf node
        if (!node->left && !node->right) {
            return currentNum;
        }
        
        return dfs(node->left, currentNum) + dfs(node->right, currentNum);
    };
    
    return dfs(root, 0);
}
```
**Complexity:** Time O(n), Space O(h)

---

### 7. Diameter of Binary Tree
**LeetCode #543**

Longest path between any two nodes (not necessarily through root).

```
Input:     1
          / \
         2   3
        / \
       4   5
Output: 3 (path: 4-2-1-3 or 5-2-1-3)
```

**Approach:**
- Diameter through a node = left_height + right_height
- Track global maximum while computing heights

**Solution:**
```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    
    function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int leftH = height(node->left);
        int rightH = height(node->right);
        
        // Update diameter
        diameter = max(diameter, leftH + rightH);
        
        return 1 + max(leftH, rightH);
    };
    
    height(root);
    return diameter;
}
```
**Complexity:** Time O(n), Space O(h)

---

### 8. Binary Tree Maximum Path Sum
**LeetCode #124**

Find max path sum (path can start and end at any node).

```
Input:     -10
          /   \
         9    20
             /  \
            15   7
Output: 42 (path: 15-20-7)
```

**Approach:**
- For each node, compute max path through it
- Track global maximum
- Return max single-branch gain for parent computation

**Solution:**
```cpp
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    
    function<int(TreeNode*)> maxGain = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        // Max gain from left/right (ignore negative)
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        // Path through current node
        int currentPath = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPath);
        
        // Return max gain if continuing through this node
        return node->val + max(leftGain, rightGain);
    };
    
    maxGain(root);
    return maxSum;
}
```
**Complexity:** Time O(n), Space O(h)

---

### 9. Lowest Common Ancestor
**LeetCode #235** (BST) / **#236** (Binary Tree)

Find LCA of two nodes.

**BST Solution:**
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}
```

**Binary Tree Solution:**
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;  // p and q in different subtrees
    
    return left ? left : right;
}
```
**Complexity:** Time O(n), Space O(h)

---

### 10. Validate Binary Search Tree
**LeetCode #98**

Check if tree is valid BST.

**Approach:**
- Pass valid range (min, max) for each node
- Each node must be within its valid range

**Solution:**
```cpp
bool isValidBST(TreeNode* root) {
    function<bool(TreeNode*, long, long)> validate = [&](TreeNode* node, long minVal, long maxVal) -> bool {
        if (!node) return true;
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    };
    
    return validate(root, LONG_MIN, LONG_MAX);
}
```
**Complexity:** Time O(n), Space O(h)

---

## 🔴 Hard Problems

### 11. Serialize and Deserialize Binary Tree
**LeetCode #297**

Convert tree to string and back.

**Approach:**
- Preorder traversal with null markers
- Use delimiter to separate values

**Solution:**
```cpp
class Codec {
public:
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
private:
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "null,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }
    
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        getline(iss, val, ',');
        
        if (val == "null") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }
};
```
**Complexity:** Time O(n), Space O(n)

---

## 📚 Study Tips for Tree DFS

1. **Choose traversal order:** Pre, In, or Post based on when you need to process
2. **Track state:** Pass information down via parameters, up via return values
3. **Handle base cases:** Know when to return at null vs at leaf
4. **Global vs local:** Use class variables when you need to track a global maximum

---

*[← Back to Pattern](./README.md) | [Next Pattern: Subsets →](../09-subsets/README.md)*
