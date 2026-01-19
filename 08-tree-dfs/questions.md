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

**Solution:**
```python
def maxDepth(root):
    if not root:
        return 0
    
    left_depth = maxDepth(root.left)
    right_depth = maxDepth(root.right)
    
    return 1 + max(left_depth, right_depth)
```
**Complexity:** Time O(n), Space O(h)

---

### 2. Same Tree
**LeetCode #100**

Check if two trees are identical.

**Solution:**
```python
def isSameTree(p, q):
    if not p and not q:
        return True
    if not p or not q:
        return False
    if p.val != q.val:
        return False
    
    return isSameTree(p.left, q.left) and isSameTree(p.right, q.right)
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

**Solution:**
```python
def invertTree(root):
    if not root:
        return None
    
    # Swap children
    root.left, root.right = root.right, root.left
    
    # Recurse
    invertTree(root.left)
    invertTree(root.right)
    
    return root
```
**Complexity:** Time O(n), Space O(h)

---

### 4. Path Sum
**LeetCode #112**

Check if root-to-leaf path with target sum exists.

**Solution:**
```python
def hasPathSum(root, targetSum):
    if not root:
        return False
    
    targetSum -= root.val
    
    # Leaf node check
    if not root.left and not root.right:
        return targetSum == 0
    
    return hasPathSum(root.left, targetSum) or hasPathSum(root.right, targetSum)
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

**Solution:**
```python
def pathSum(root, targetSum):
    result = []
    
    def dfs(node, target, path):
        if not node:
            return
        
        path.append(node.val)
        target -= node.val
        
        if not node.left and not node.right and target == 0:
            result.append(list(path))
        
        dfs(node.left, target, path)
        dfs(node.right, target, path)
        
        path.pop()  # Backtrack
    
    dfs(root, targetSum, [])
    return result
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

**Solution:**
```python
def sumNumbers(root):
    def dfs(node, current_num):
        if not node:
            return 0
        
        current_num = current_num * 10 + node.val
        
        # Leaf node
        if not node.left and not node.right:
            return current_num
        
        return dfs(node.left, current_num) + dfs(node.right, current_num)
    
    return dfs(root, 0)
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

**Key Insight:** Diameter through a node = left_height + right_height

**Solution:**
```python
def diameterOfBinaryTree(root):
    diameter = 0
    
    def height(node):
        nonlocal diameter
        if not node:
            return 0
        
        left_h = height(node.left)
        right_h = height(node.right)
        
        # Update diameter
        diameter = max(diameter, left_h + right_h)
        
        return 1 + max(left_h, right_h)
    
    height(root)
    return diameter
```
**Complexity:** Time O(n), Space O(h)

---

### 8. Lowest Common Ancestor of BST
**LeetCode #235**

Find LCA of two nodes in BST.

**Solution:**
```python
def lowestCommonAncestor(root, p, q):
    while root:
        if p.val < root.val and q.val < root.val:
            root = root.left
        elif p.val > root.val and q.val > root.val:
            root = root.right
        else:
            return root
    return None
```

**For regular Binary Tree (LeetCode #236):**
```python
def lowestCommonAncestor(root, p, q):
    if not root or root == p or root == q:
        return root
    
    left = lowestCommonAncestor(root.left, p, q)
    right = lowestCommonAncestor(root.right, p, q)
    
    if left and right:
        return root  # p and q are in different subtrees
    
    return left if left else right
```
**Complexity:** Time O(n), Space O(h)

---

### 9. Validate Binary Search Tree
**LeetCode #98**

Check if tree is valid BST.

**Solution:**
```python
def isValidBST(root):
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (validate(node.left, min_val, node.val) and
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))
```
**Complexity:** Time O(n), Space O(h)

---

## 🔴 Hard Problems

### 10. Binary Tree Maximum Path Sum
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

**Solution:**
```python
def maxPathSum(root):
    max_sum = float('-inf')
    
    def max_gain(node):
        nonlocal max_sum
        if not node:
            return 0
        
        # Max gain from left/right (ignore negative)
        left_gain = max(max_gain(node.left), 0)
        right_gain = max(max_gain(node.right), 0)
        
        # Path through current node
        current_path = node.val + left_gain + right_gain
        max_sum = max(max_sum, current_path)
        
        # Return max gain if continuing through this node
        return node.val + max(left_gain, right_gain)
    
    max_gain(root)
    return max_sum
```
**Complexity:** Time O(n), Space O(h)

---

### 11. Serialize and Deserialize Binary Tree
**LeetCode #297**

Convert tree to string and back.

**Solution:**
```python
class Codec:
    def serialize(self, root):
        result = []
        
        def dfs(node):
            if not node:
                result.append('null')
                return
            result.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        return ','.join(result)
    
    def deserialize(self, data):
        values = iter(data.split(','))
        
        def dfs():
            val = next(values)
            if val == 'null':
                return None
            node = TreeNode(int(val))
            node.left = dfs()
            node.right = dfs()
            return node
        
        return dfs()
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
