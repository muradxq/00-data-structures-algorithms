# 📝 Tree BFS - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Variant | Status |
|---|---------|------------|---------|--------|
| 1 | Average of Levels in Binary Tree | Easy | Level Stats | ⬜ |
| 2 | Minimum Depth of Binary Tree | Easy | Min Depth | ⬜ |
| 3 | Cousins in Binary Tree | Easy | Relationships | ⬜ |
| 4 | Binary Tree Level Order Traversal | Medium | Basic | ⬜ |
| 5 | Binary Tree Level Order Traversal II | Medium | Reverse | ⬜ |
| 6 | Binary Tree Zigzag Level Order | Medium | Zigzag | ⬜ |
| 7 | Binary Tree Right Side View | Medium | Side View | ⬜ |
| 8 | Populating Next Right Pointers | Medium | Connect Nodes | ⬜ |

---

## 🟢 Easy Problems

### 1. Average of Levels in Binary Tree
**LeetCode #637**

Return average value of nodes at each level.

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: [3.0, 14.5, 11.0]
```

**Approach:**
- BFS with level tracking
- Sum all values at each level and divide by count

**Solution:**
```cpp
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        double levelSum = 0;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(levelSum / levelSize);
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 2. Minimum Depth of Binary Tree
**LeetCode #111**

Find minimum depth (shortest root-to-leaf path).

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: 2 (path 3→9)
```

**Approach:**
- BFS finds shortest path first
- Return immediately when leaf node is found

**Solution:**
```cpp
int minDepth(TreeNode* root) {
    if (!root) return 0;
    
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    
    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        
        // Found leaf node - return immediately
        if (!node->left && !node->right) {
            return depth;
        }
        
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    
    return 0;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 3. Cousins in Binary Tree
**LeetCode #993**

Two nodes are cousins if same depth but different parents.

```
Input: root = [1,2,3,4], x = 4, y = 3
       1
      / \
     2   3
    /
   4
Output: false (different depths)
```

**Approach:**
- Track parent and depth for both nodes
- Compare at end of each level

**Solution:**
```cpp
bool isCousins(TreeNode* root, int x, int y) {
    queue<pair<TreeNode*, TreeNode*>> q;  // {node, parent}
    q.push({root, nullptr});
    
    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;
        
        for (int i = 0; i < levelSize; i++) {
            auto [node, parent] = q.front();
            q.pop();
            
            if (node->val == x) xParent = parent;
            if (node->val == y) yParent = parent;
            
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }
        
        // Check after processing level
        if (xParent && yParent) {
            return xParent != yParent;  // Same level, different parents
        }
        if (xParent || yParent) {
            return false;  // Different levels
        }
    }
    
    return false;
}
```
**Complexity:** Time O(n), Space O(n)

---

## 🟡 Medium Problems

### 4. Binary Tree Level Order Traversal
**LeetCode #102**

Return nodes level by level.

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: [[3], [9,20], [15,7]]
```

**Approach:**
- Standard BFS, capture level size before processing each level

**Solution:**
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 5. Binary Tree Level Order Traversal II
**LeetCode #107**

Return level order from bottom to top.

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: [[15,7], [9,20], [3]]
```

**Approach:**
- Same as level order, then reverse the result

**Solution:**
```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 6. Binary Tree Zigzag Level Order Traversal
**LeetCode #103**

Zigzag level order (alternate left-right, right-left).

```
Input:     3
          / \
         9  20
           /  \
          15   7
Output: [[3], [20,9], [15,7]]
```

**Approach:**
- Alternate insertion direction at each level

**Solution:**
```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int levelSize = q.size();
        deque<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (leftToRight) {
                currentLevel.push_back(node->val);
            } else {
                currentLevel.push_front(node->val);
            }
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(vector<int>(currentLevel.begin(), currentLevel.end()));
        leftToRight = !leftToRight;
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 7. Binary Tree Right Side View
**LeetCode #199**

Return values visible from right side.

```
Input:     1
          / \
         2   3
          \   \
           5   4
Output: [1, 3, 4]
```

**Approach:**
- Take last node of each level

**Solution:**
```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            // Last node in level = rightmost
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 8. Populating Next Right Pointers in Each Node
**LeetCode #116**

Connect nodes at same level using next pointer.

```
Input:     1               1 → NULL
          / \             / \
         2   3           2 → 3 → NULL
        / \ / \         / \ / \
       4  5 6  7       4→5→6→7 → NULL
```

**Approach (BFS):**
- Connect each node to next node in same level

```cpp
Node* connect(Node* root) {
    if (!root) return root;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        Node* prev = nullptr;
        
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            
            if (prev) prev->next = node;
            prev = node;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return root;
}
```

**O(1) Space Solution (Perfect Binary Tree):**
```cpp
Node* connect(Node* root) {
    if (!root) return root;
    
    Node* leftmost = root;
    
    while (leftmost->left) {
        Node* head = leftmost;
        
        while (head) {
            // Connect left child to right child
            head->left->next = head->right;
            
            // Connect right child to next node's left child
            if (head->next) {
                head->right->next = head->next->left;
            }
            
            head = head->next;
        }
        
        leftmost = leftmost->left;
    }
    
    return root;
}
```
**Complexity:** Time O(n), Space O(1) for perfect binary tree

---

## 📚 Study Tips for Tree BFS

1. **Level boundary:** Always capture `queue.size()` before processing
2. **Track extra info:** Use pairs `{node, depth}` or `{node, parent}` when needed
3. **Early return:** BFS finds shortest paths first - use for minimum problems
4. **Variations:** Zigzag, reverse, and side views are simple modifications

---

*[← Back to Pattern](./README.md) | [Next Pattern: Tree DFS →](../08-tree-dfs/README.md)*
