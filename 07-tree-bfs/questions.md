# 📝 Tree BFS - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Variant | Status |
|---|---------|------------|---------|--------|
| 1 | Binary Tree Level Order Traversal | Medium | Basic | ⬜ |
| 2 | Binary Tree Level Order Traversal II | Medium | Reverse | ⬜ |
| 3 | Binary Tree Zigzag Level Order | Medium | Zigzag | ⬜ |
| 4 | Average of Levels in Binary Tree | Easy | Level Stats | ⬜ |
| 5 | Minimum Depth of Binary Tree | Easy | Min Depth | ⬜ |
| 6 | Binary Tree Right Side View | Medium | Side View | ⬜ |
| 7 | Populating Next Right Pointers | Medium | Connect Nodes | ⬜ |
| 8 | Cousins in Binary Tree | Easy | Relationships | ⬜ |

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

**Solution:**
```python
from collections import deque

def averageOfLevels(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        level_sum = 0
        
        for _ in range(level_size):
            node = queue.popleft()
            level_sum += node.val
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level_sum / level_size)
    
    return result
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

**Solution:**
```python
from collections import deque

def minDepth(root):
    if not root:
        return 0
    
    queue = deque([(root, 1)])
    
    while queue:
        node, depth = queue.popleft()
        
        # Found leaf node - return immediately (BFS finds shortest first)
        if not node.left and not node.right:
            return depth
        
        if node.left:
            queue.append((node.left, depth + 1))
        if node.right:
            queue.append((node.right, depth + 1))
    
    return 0
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

**Solution:**
```python
from collections import deque

def isCousins(root, x, y):
    queue = deque([(root, None)])  # (node, parent)
    
    while queue:
        level_size = len(queue)
        x_parent = y_parent = None
        
        for _ in range(level_size):
            node, parent = queue.popleft()
            
            if node.val == x:
                x_parent = parent
            if node.val == y:
                y_parent = parent
            
            if node.left:
                queue.append((node.left, node))
            if node.right:
                queue.append((node.right, node))
        
        # Check after processing level
        if x_parent and y_parent:
            return x_parent != y_parent  # Same level, different parents
        if x_parent or y_parent:
            return False  # Different levels
    
    return False
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

**Solution:**
```python
from collections import deque

def levelOrder(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        current_level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            current_level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(current_level)
    
    return result
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

**Solution:**
```python
from collections import deque

def levelOrderBottom(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        current_level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            current_level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(current_level)
    
    result.reverse()  # Or use result.insert(0, current_level)
    return result
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

**Solution:**
```python
from collections import deque

def zigzagLevelOrder(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    left_to_right = True
    
    while queue:
        level_size = len(queue)
        current_level = deque()
        
        for _ in range(level_size):
            node = queue.popleft()
            
            if left_to_right:
                current_level.append(node.val)
            else:
                current_level.appendleft(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(list(current_level))
        left_to_right = not left_to_right
    
    return result
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

**Solution:**
```python
from collections import deque

def rightSideView(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        
        for i in range(level_size):
            node = queue.popleft()
            
            # Last node in level = rightmost
            if i == level_size - 1:
                result.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    
    return result
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

**Solution:**
```python
from collections import deque

def connect(root):
    if not root:
        return root
    
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        prev = None
        
        for _ in range(level_size):
            node = queue.popleft()
            
            if prev:
                prev.next = node
            prev = node
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    
    return root
```

**O(1) Space Solution (Perfect Binary Tree):**
```python
def connect(root):
    if not root:
        return root
    
    leftmost = root
    
    while leftmost.left:
        head = leftmost
        
        while head:
            # Connect left child to right child
            head.left.next = head.right
            
            # Connect right child to next node's left child
            if head.next:
                head.right.next = head.next.left
            
            head = head.next
        
        leftmost = leftmost.left
    
    return root
```
**Complexity:** Time O(n), Space O(1) for perfect binary tree

---

## 📚 Study Tips for Tree BFS

1. **Level boundary:** Always capture `len(queue)` before processing
2. **Track extra info:** Use tuples `(node, depth, parent)` when needed
3. **Early return:** BFS finds shortest paths first - use for minimum problems
4. **Variations:** Zigzag, reverse, and side views are simple modifications

---

*[← Back to Pattern](./README.md) | [Next Pattern: Tree DFS →](../08-tree-dfs/README.md)*
