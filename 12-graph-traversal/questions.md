# 📝 Graph Traversal - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Number of Islands | Medium | DFS/BFS Grid | ⬜ |
| 2 | Clone Graph | Medium | DFS/BFS | ⬜ |
| 3 | Pacific Atlantic Water Flow | Medium | Multi-source BFS | ⬜ |
| 4 | Rotting Oranges | Medium | Multi-source BFS | ⬜ |
| 5 | Word Ladder | Hard | BFS Shortest Path | ⬜ |
| 6 | Course Schedule | Medium | Cycle Detection | ⬜ |
| 7 | Graph Valid Tree | Medium | Cycle + Connected | ⬜ |
| 8 | Number of Connected Components | Medium | Union Find/DFS | ⬜ |

---

## 🟡 Medium Problems

### 1. Number of Islands
**LeetCode #200**

Count islands (groups of connected '1's).

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**DFS Solution:**
```python
def numIslands(grid):
    if not grid:
        return 0
    
    rows, cols = len(grid), len(grid[0])
    count = 0
    
    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] != '1':
            return
        grid[r][c] = '0'
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)
    
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '1':
                count += 1
                dfs(r, c)
    
    return count
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 2. Clone Graph
**LeetCode #133**

Return deep copy of graph.

**Solution:**
```python
def cloneGraph(node):
    if not node:
        return None
    
    clones = {}
    
    def dfs(node):
        if node in clones:
            return clones[node]
        
        clone = Node(node.val)
        clones[node] = clone
        
        for neighbor in node.neighbors:
            clone.neighbors.append(dfs(neighbor))
        
        return clone
    
    return dfs(node)
```
**Complexity:** Time O(V+E), Space O(V)

---

### 3. Rotting Oranges
**LeetCode #994**

Find minimum minutes for all oranges to rot (multi-source BFS).

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Solution:**
```python
from collections import deque

def orangesRotting(grid):
    rows, cols = len(grid), len(grid[0])
    queue = deque()
    fresh = 0
    
    # Find all rotten oranges and count fresh
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 2:
                queue.append((r, c))
            elif grid[r][c] == 1:
                fresh += 1
    
    if fresh == 0:
        return 0
    
    minutes = 0
    directions = [(0,1), (0,-1), (1,0), (-1,0)]
    
    while queue:
        minutes += 1
        for _ in range(len(queue)):
            r, c = queue.popleft()
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    queue.append((nr, nc))
    
    return minutes - 1 if fresh == 0 else -1
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 4. Pacific Atlantic Water Flow
**LeetCode #417**

Find cells that can flow to both Pacific and Atlantic oceans.

**Solution:**
```python
def pacificAtlantic(heights):
    if not heights:
        return []
    
    rows, cols = len(heights), len(heights[0])
    pacific = set()
    atlantic = set()
    
    def dfs(r, c, visited, prev_height):
        if (r < 0 or r >= rows or c < 0 or c >= cols or
            (r, c) in visited or heights[r][c] < prev_height):
            return
        
        visited.add((r, c))
        dfs(r+1, c, visited, heights[r][c])
        dfs(r-1, c, visited, heights[r][c])
        dfs(r, c+1, visited, heights[r][c])
        dfs(r, c-1, visited, heights[r][c])
    
    # Start from ocean borders
    for c in range(cols):
        dfs(0, c, pacific, 0)        # Pacific top
        dfs(rows-1, c, atlantic, 0)  # Atlantic bottom
    
    for r in range(rows):
        dfs(r, 0, pacific, 0)        # Pacific left
        dfs(r, cols-1, atlantic, 0)  # Atlantic right
    
    return list(pacific & atlantic)
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 5. Course Schedule
**LeetCode #207**

Can finish all courses given prerequisites? (Cycle detection)

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true (Take course 0, then course 1)
```

**Solution:**
```python
def canFinish(numCourses, prerequisites):
    graph = [[] for _ in range(numCourses)]
    for course, prereq in prerequisites:
        graph[course].append(prereq)
    
    # 0: unvisited, 1: visiting, 2: visited
    state = [0] * numCourses
    
    def has_cycle(course):
        if state[course] == 1:  # Currently visiting = cycle
            return True
        if state[course] == 2:  # Already done
            return False
        
        state[course] = 1
        for prereq in graph[course]:
            if has_cycle(prereq):
                return True
        state[course] = 2
        return False
    
    for course in range(numCourses):
        if has_cycle(course):
            return False
    
    return True
```
**Complexity:** Time O(V+E), Space O(V+E)

---

## 🔴 Hard Problems

### 6. Word Ladder
**LeetCode #127**

Find shortest transformation from beginWord to endWord.

```
Input: beginWord = "hit", endWord = "cog", 
       wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5 ("hit" -> "hot" -> "dot" -> "dog" -> "cog")
```

**Solution:**
```python
from collections import deque

def ladderLength(beginWord, endWord, wordList):
    word_set = set(wordList)
    if endWord not in word_set:
        return 0
    
    queue = deque([(beginWord, 1)])
    visited = {beginWord}
    
    while queue:
        word, length = queue.popleft()
        
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                
                if next_word == endWord:
                    return length + 1
                
                if next_word in word_set and next_word not in visited:
                    visited.add(next_word)
                    queue.append((next_word, length + 1))
    
    return 0
```
**Complexity:** Time O(m² × n), Space O(m × n) where m = word length, n = word count

---

## 📚 Study Tips for Graph Traversal

1. **Choose BFS or DFS:** BFS for shortest path, DFS for exploration
2. **Track visited early:** Add to visited when adding to queue
3. **Know your representation:** Adjacency list is usually best
4. **Handle disconnected graphs:** Loop through all nodes

---

*[← Back to Pattern](./README.md) | [Next Pattern: Topological Sort →](../13-topological-sort/README.md)*
