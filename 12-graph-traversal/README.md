# 🕸️ Graph Traversal Pattern (BFS/DFS)

## Overview

**Graph traversal** systematically visits all vertices and edges in a graph. Unlike trees, graphs can have cycles, so we need to track visited nodes. The two main approaches are BFS (Breadth-First Search) and DFS (Depth-First Search).

---

## 🧠 When to Use Graph Traversal

Use this pattern when:
- Need to explore all nodes in a graph
- Find **shortest path** in unweighted graph (BFS)
- Detect **cycles** (DFS)
- Find **connected components**
- Check if graph is **bipartite**
- Keywords: "connected", "path", "reachable", "islands", "network"

---

## 🎯 BFS vs DFS

| Aspect | BFS | DFS |
|--------|-----|-----|
| Data Structure | Queue | Stack/Recursion |
| Traversal Order | Level by level | Deep first |
| Shortest Path | ✓ (unweighted) | ✗ |
| Space | O(width) | O(depth) |
| Use Cases | Shortest path, level order | Cycle detection, topological sort |

---

## 📐 General Templates

### BFS Template
```cpp
void bfs(vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<int> q;
    
    visited.insert(start);
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        process(node);
        
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

### BFS with Distance
```cpp
void bfsDistance(vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<pair<int, int>> q;  // (node, distance)
    
    visited.insert(start);
    q.push({start, 0});
    
    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push({neighbor, dist + 1});
            }
        }
    }
}
```

### DFS Template (Recursive)
```cpp
void dfs(vector<vector<int>>& graph, int node, unordered_set<int>& visited) {
    visited.insert(node);
    process(node);
    
    for (int neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfs(graph, neighbor, visited);
        }
    }
}
```

### DFS Template (Iterative)
```cpp
void dfsIterative(vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    stack<int> stk;
    stk.push(start);
    
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        
        if (visited.count(node)) continue;
        
        visited.insert(node);
        process(node);
        
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                stk.push(neighbor);
            }
        }
    }
}
```

---

## 💡 Key Insights

### 1. Graph Representations
```cpp
// Adjacency List (most common)
vector<vector<int>> graph = {
    {1, 2},     // node 0 connects to 1, 2
    {0, 3},     // node 1 connects to 0, 3
    {0},        // node 2 connects to 0
    {1}         // node 3 connects to 1
};

// Edge List
vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}};

// Adjacency Matrix
vector<vector<int>> matrix = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 0},
    {0, 1, 0, 0}
};
```

### 2. Building Graph from Edges
```cpp
vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges, bool directed = false) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        if (!directed) {
            graph[edge[1]].push_back(edge[0]);
        }
    }
    return graph;
}
```

### 3. Grid as Graph
```cpp
// For 2D grid problems
vector<pair<int,int>> getNeighbors(vector<vector<int>>& grid, int row, int col) {
    vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<pair<int,int>> neighbors;
    
    for (auto& [dr, dc] : directions) {
        int r = row + dr, c = col + dc;
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
            neighbors.push_back({r, c});
        }
    }
    return neighbors;
}
```

### 4. Cycle Detection
```cpp
// DFS with colors: WHITE=0, GRAY=1, BLACK=2
bool hasCycle(vector<vector<int>>& graph, int n) {
    vector<int> color(n, 0);
    
    function<bool(int)> dfs = [&](int node) -> bool {
        color[node] = 1;  // Visiting
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 1) {  // Back edge
                return true;
            }
            if (color[neighbor] == 0 && dfs(neighbor)) {
                return true;
            }
        }
        
        color[node] = 2;  // Done
        return false;
    };
    
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i)) {
            return true;
        }
    }
    return false;
}
```

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| BFS/DFS | O(V + E) | O(V) |
| Grid BFS/DFS | O(m × n) | O(m × n) |

---

## 🎓 Example Walkthrough: Number of Islands

**Problem:** Count number of islands (groups of '1's connected horizontally/vertically).

```
Input:
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Output: 3
```

**Solution (DFS):**
```cpp
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int rows = grid.size(), cols = grid[0].size();
    int count = 0;
    
    function<void(int, int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
            return;
        }
        
        grid[r][c] = '0';  // Mark visited
        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    };
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(r, c);
            }
        }
    }
    
    return count;
}
```

---

## 🔗 Related Patterns

- **Tree BFS/DFS:** Special case (no cycles)
- **Topological Sort:** Extension for DAGs
- **Union Find:** Alternative for connectivity
- **Shortest Path:** Dijkstra, Bellman-Ford for weighted graphs

---

## 🚨 Common Mistakes

1. **Forgetting visited set:** Causes infinite loops with cycles
2. **Adding to visited too late:** Add when pushing to queue, not when popping
3. **Wrong neighbor bounds:** Always check grid boundaries
4. **Modifying input:** Sometimes need to restore or use separate visited set

---

*Next: [See Practice Questions →](./questions.md)*
