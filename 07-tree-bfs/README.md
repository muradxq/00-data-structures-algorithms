# 🌳 Tree BFS Pattern (Level-Order Traversal)

## Overview

**Tree BFS (Breadth-First Search)** processes tree nodes level by level using a queue. It's the go-to pattern for any problem that requires processing nodes at the same depth together.

---

## 🧠 When to Use Tree BFS

Use this pattern when:
- Need to process tree **level by level**
- Finding **level averages**, **level sums**, or **level order** output
- Finding **minimum depth** (BFS finds it faster than DFS)
- Problems involving **cousins**, **siblings**, or **same-level** relationships
- Keywords: "level", "depth", "breadth", "zigzag"

---

## 🎯 Core Concept

```
        1
       / \
      2   3
     / \ / \
    4  5 6  7

BFS visits: Level 0: [1]
            Level 1: [2, 3]
            Level 2: [4, 5, 6, 7]
```

---

## 📐 General Templates

### Basic Level Order Traversal
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    
    vector<vector<int>> result;
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

### BFS with Parent/Depth Tracking
```cpp
void bfsWithTracking(TreeNode* root) {
    queue<tuple<TreeNode*, int, TreeNode*>> q;  // (node, depth, parent)
    q.push({root, 0, nullptr});
    
    while (!q.empty()) {
        auto [node, depth, parent] = q.front();
        q.pop();
        
        // Process node with depth and parent info
        
        if (node->left) {
            q.push({node->left, depth + 1, node});
        }
        if (node->right) {
            q.push({node->right, depth + 1, node});
        }
    }
}
```

---

## 💡 Key Insights

### 1. Level Boundary Technique
The key to BFS is processing one level at a time:
```cpp
while (!q.empty()) {
    int levelSize = q.size();  // Capture current level size
    for (int i = 0; i < levelSize; i++) {  // Process exactly this many nodes
        // All these nodes are at same level
    }
}
```

### 2. Common Variations
```cpp
// Reverse level order: Insert at beginning
result.insert(result.begin(), currentLevel);
// Or: push_back then reverse at the end

// Zigzag: Alternate direction per level
if (isLeftToRight) {
    currentLevel.push_back(node->val);
} else {
    currentLevel.insert(currentLevel.begin(), node->val);
}
isLeftToRight = !isLeftToRight;

// Right side view: Take last node of each level
result.push_back(currentLevel.back());
```

### 3. BFS vs DFS for Trees
| Use BFS | Use DFS |
|---------|---------|
| Level-by-level processing | Path-based problems |
| Minimum depth | Maximum depth |
| Right/left side view | Path sum problems |
| Level averages | Subtree operations |

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Level Order | O(n) | O(n) |

Space is O(n) in worst case (complete tree's bottom level has n/2 nodes).

---

## 🎓 Example Walkthrough: Binary Tree Level Order Traversal

**Problem:** Return level order traversal as list of lists.

```
Input:     3
          / \
         9  20
           /  \
          15   7
```

**Step-by-step:**
```
Queue: [3], result = []

Level 0:
  size = 1
  Pop 3, add to level: [3]
  Add 9, 20 to queue
  Queue: [9, 20]
  result = [[3]]

Level 1:
  size = 2
  Pop 9, add to level: [9]
  Pop 20, add to level: [9, 20]
  Add 15, 7 to queue
  Queue: [15, 7]
  result = [[3], [9, 20]]

Level 2:
  size = 2
  Pop 15, add to level: [15]
  Pop 7, add to level: [15, 7]
  Queue: []
  result = [[3], [9, 20], [15, 7]]

Output: [[3], [9, 20], [15, 7]]
```

---

## 🔗 Related Patterns

- **Graph BFS:** Same technique, but handles cycles with visited set
- **Tree DFS:** Alternative traversal strategy
- **Queue:** Fundamental data structure for BFS

---

## 🚨 Common Mistakes

1. **Forgetting levelSize:** Must capture before processing
2. **Adding null nodes:** Check before adding to queue
3. **Empty tree:** Handle `root == nullptr` case

---

*Next: [See Practice Questions →](./questions.md)*
