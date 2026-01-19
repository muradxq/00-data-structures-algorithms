# 🔗 Union Find Pattern (Disjoint Set)

## Overview

**Union Find** (also called Disjoint Set Union) is a data structure that efficiently tracks elements partitioned into disjoint (non-overlapping) sets. It supports two main operations: **Find** (which set does element belong to?) and **Union** (merge two sets).

---

## 🧠 When to Use Union Find

Use this pattern when:
- Need to track **connected components**
- Determine if two elements are **in the same group**
- **Merge groups** dynamically
- Problems involving **connectivity** in graphs
- Keywords: "connected", "same group", "merge", "union", "components"

---

## 📐 Implementation

### Basic Union Find
```cpp
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int count;  // Number of components
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return false;  // Already connected
        }
        
        // Union by rank
        if (rank[px] < rank[py]) {
            swap(px, py);
        }
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
        
        count--;
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

---

## 💡 Key Optimizations

### 1. Path Compression
Flatten the tree during `find()`:
```cpp
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
```

### 2. Union by Rank/Size
Attach smaller tree under larger tree:
```cpp
if (rank[px] < rank[py]) {
    parent[px] = py;
} else {
    parent[py] = px;
}
```

### Combined Optimization
With both optimizations, operations are nearly O(1) - specifically O(α(n)) where α is the inverse Ackermann function.

---

## 📊 Complexity Analysis

| Operation | Without Optimization | With Both Optimizations |
|-----------|---------------------|------------------------|
| Find | O(n) | O(α(n)) ≈ O(1) |
| Union | O(n) | O(α(n)) ≈ O(1) |

---

## 🎓 Example: Number of Provinces

**Problem:** Find number of connected provinces (groups of connected cities).

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

**Solution:**
```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j]) {
                uf.unite(i, j);
            }
        }
    }
    
    return uf.count;
}
```

---

## 🔗 Union Find vs DFS/BFS

| Aspect | Union Find | DFS/BFS |
|--------|-----------|---------|
| Dynamic updates | ✓ Excellent | ✗ Must recompute |
| Query connectivity | O(1) after setup | O(V+E) each query |
| Best for | Dynamic connectivity | One-time traversal |

---

*Next: [See Practice Questions →](./questions.md)*
