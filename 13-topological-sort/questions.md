# 📝 Topological Sort - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Variant | Status |
|---|---------|------------|---------|--------|
| 1 | Course Schedule | Medium | Cycle Detection | ⬜ |
| 2 | Course Schedule II | Medium | Find Order | ⬜ |
| 3 | Alien Dictionary | Hard | Build Graph | ⬜ |
| 4 | Minimum Height Trees | Medium | Multi-source BFS | ⬜ |
| 5 | Sequence Reconstruction | Medium | Unique Order | ⬜ |

---

## 🟡 Medium Problems

### 1. Course Schedule
**LeetCode #207**

Can finish all courses?

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
```

**Solution:**
```python
from collections import deque

def canFinish(numCourses, prerequisites):
    graph = [[] for _ in range(numCourses)]
    in_degree = [0] * numCourses
    
    for course, prereq in prerequisites:
        graph[prereq].append(course)
        in_degree[course] += 1
    
    queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
    count = 0
    
    while queue:
        node = queue.popleft()
        count += 1
        
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return count == numCourses
```
**Complexity:** Time O(V+E), Space O(V+E)

---

### 2. Course Schedule II
**LeetCode #210**

Return order to finish all courses.

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
```

**Solution:**
```python
from collections import deque

def findOrder(numCourses, prerequisites):
    graph = [[] for _ in range(numCourses)]
    in_degree = [0] * numCourses
    
    for course, prereq in prerequisites:
        graph[prereq].append(course)
        in_degree[course] += 1
    
    queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
    result = []
    
    while queue:
        node = queue.popleft()
        result.append(node)
        
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return result if len(result) == numCourses else []
```
**Complexity:** Time O(V+E), Space O(V+E)

---

## 🔴 Hard Problems

### 3. Alien Dictionary
**LeetCode #269** (Premium)

Derive alphabet order from sorted alien words.

```
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
```

**Solution:**
```python
from collections import deque

def alienOrder(words):
    # Build graph
    graph = {c: set() for word in words for c in word}
    in_degree = {c: 0 for c in graph}
    
    for i in range(len(words) - 1):
        w1, w2 = words[i], words[i + 1]
        
        # Check for invalid case: prefix comes after longer word
        if len(w1) > len(w2) and w1[:len(w2)] == w2:
            return ""
        
        for c1, c2 in zip(w1, w2):
            if c1 != c2:
                if c2 not in graph[c1]:
                    graph[c1].add(c2)
                    in_degree[c2] += 1
                break
    
    # Topological sort
    queue = deque([c for c in in_degree if in_degree[c] == 0])
    result = []
    
    while queue:
        c = queue.popleft()
        result.append(c)
        
        for neighbor in graph[c]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return ''.join(result) if len(result) == len(graph) else ""
```
**Complexity:** Time O(C) where C = total characters, Space O(U) where U = unique characters

---

## 📚 Study Tips for Topological Sort

1. **Build the graph correctly:** Understand direction of edges
2. **Check for cycles:** If result length ≠ n, cycle exists
3. **Count in-degrees:** Key for BFS approach
4. **Know both approaches:** BFS (Kahn's) and DFS

---

*[← Back to Pattern](./README.md) | [Next Pattern: Union Find →](../14-union-find/README.md)*
