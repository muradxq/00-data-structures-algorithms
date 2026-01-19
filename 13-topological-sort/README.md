# 📊 Topological Sort Pattern

## Overview

**Topological Sort** produces a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every edge (u, v), u comes before v. It's used for scheduling tasks with dependencies.

---

## 🧠 When to Use Topological Sort

Use this pattern when:
- Problems involve **dependencies** or **prerequisites**
- Need to find an **order** to complete tasks
- Working with a **DAG** (Directed Acyclic Graph)
- Keywords: "schedule", "order", "dependency", "prerequisite", "before/after"

---

## 🎯 Two Approaches

### 1. Kahn's Algorithm (BFS)
Uses in-degree counting:
1. Calculate in-degree for all nodes
2. Add nodes with in-degree 0 to queue
3. Process queue: remove node, reduce neighbors' in-degree
4. Add neighbors with in-degree 0 to queue

### 2. DFS-based
Uses post-order traversal:
1. Run DFS from each unvisited node
2. Add node to result after visiting all descendants
3. Reverse the result

---

## 📐 General Templates

### Kahn's Algorithm (BFS)
```cpp
vector<int> topologicalSortBFS(int n, vector<vector<int>>& edges) {
    // Build graph and calculate in-degrees
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);
    
    for (auto& edge : edges) {  // edge[0] -> edge[1]
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }
    
    // Start with nodes having no dependencies
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Check if valid topological order exists
    if (result.size() != n) {
        return {};  // Cycle detected
    }
    
    return result;
}
```

### DFS-based Topological Sort
```cpp
vector<int> topologicalSortDFS(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    vector<int> visited(n, 0);  // 0: unvisited, 1: visiting, 2: visited
    vector<int> result;
    bool hasCycle = false;
    
    function<void(int)> dfs = [&](int node) {
        if (hasCycle) return;
        if (visited[node] == 1) {  // Cycle detected
            hasCycle = true;
            return;
        }
        if (visited[node] == 2) return;
        
        visited[node] = 1;
        for (int neighbor : graph[node]) {
            dfs(neighbor);
        }
        
        visited[node] = 2;
        result.push_back(node);
    };
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    
    if (hasCycle) return {};
    
    reverse(result.begin(), result.end());
    return result;
}
```

---

## 💡 Key Insights

### 1. Cycle Detection
- **BFS:** If result length < n, there's a cycle
- **DFS:** If we visit a node that's currently being visited (state=1), there's a cycle

### 2. Multiple Valid Orders
Topological sort is not unique. Different valid orderings exist when there are nodes with equal "priority."

### 3. Lexicographic Order
Use priority queue instead of regular queue:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
        pq.push(i);
    }
}
```

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Topological Sort | O(V + E) | O(V + E) |

---

## 🎓 Example Walkthrough: Course Schedule II

**Problem:** Return course order to finish all courses.

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]

Graph:
0 → 1 → 3
↓       ↑
2 ------+

Output: [0,1,2,3] or [0,2,1,3]
```

**Step-by-step (Kahn's):**
```
inDegree: [0, 1, 1, 2]
queue: [0]

Process 0:
  result = [0]
  Decrease inDegree of 1,2: [0, 0, 0, 2]
  queue: [1, 2]

Process 1:
  result = [0, 1]
  Decrease inDegree of 3: [0, 0, 0, 1]
  queue: [2]

Process 2:
  result = [0, 1, 2]
  Decrease inDegree of 3: [0, 0, 0, 0]
  queue: [3]

Process 3:
  result = [0, 1, 2, 3]
```

---

## 🔗 Related Patterns

- **Graph BFS/DFS:** Topological sort is built on these
- **Cycle Detection:** Inherent in topological sort

---

*Next: [See Practice Questions →](./questions.md)*
