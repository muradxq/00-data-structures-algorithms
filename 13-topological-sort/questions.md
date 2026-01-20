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

Can finish all courses? (Kahn's algorithm)

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
```

**Approach:**
- Build graph and compute in-degrees
- BFS from nodes with 0 in-degree
- If all nodes processed, no cycle exists

**Solution:**
```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
        inDegree[prereq[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return count == numCourses;
}
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

**Approach:**
- Same as Course Schedule but collect the order
- Return empty if cycle detected

**Solution:**
```cpp
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
        inDegree[prereq[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
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
    
    return result.size() == numCourses ? result : vector<int>();
}
```
**Complexity:** Time O(V+E), Space O(V+E)

---

### 4. Minimum Height Trees
**LeetCode #310**

Find roots that give minimum height trees.

```
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
```

**Approach:**
- Center of tree gives minimum height
- Remove leaves layer by layer until 1-2 nodes remain

**Solution:**
```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    
    vector<unordered_set<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }
    
    // Find initial leaves
    queue<int> leaves;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            leaves.push(i);
        }
    }
    
    int remaining = n;
    while (remaining > 2) {
        int leafCount = leaves.size();
        remaining -= leafCount;
        
        for (int i = 0; i < leafCount; i++) {
            int leaf = leaves.front();
            leaves.pop();
            
            int neighbor = *graph[leaf].begin();
            graph[neighbor].erase(leaf);
            
            if (graph[neighbor].size() == 1) {
                leaves.push(neighbor);
            }
        }
    }
    
    vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }
    return result;
}
```
**Complexity:** Time O(V), Space O(V)

---

### 5. Sequence Reconstruction
**LeetCode #444** (Premium)

Check if original sequence can be uniquely reconstructed from sequences.

```
Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
```

**Approach:**
- Build graph from sequences
- Topological sort must give unique order matching org
- Unique order: exactly one node with 0 in-degree at each step

**Solution:**
```cpp
bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int n = org.size();
    vector<unordered_set<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    unordered_set<int> nodes;
    
    // Build graph
    for (auto& seq : seqs) {
        for (int i = 0; i < seq.size(); i++) {
            nodes.insert(seq[i]);
            if (seq[i] < 1 || seq[i] > n) return false;
            
            if (i > 0 && !graph[seq[i-1]].count(seq[i])) {
                graph[seq[i-1]].insert(seq[i]);
                inDegree[seq[i]]++;
            }
        }
    }
    
    if (nodes.size() != n) return false;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    int idx = 0;
    while (!q.empty()) {
        if (q.size() > 1) return false;  // Not unique
        
        int node = q.front();
        q.pop();
        
        if (idx >= n || org[idx] != node) return false;
        idx++;
        
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return idx == n;
}
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

**Approach:**
- Compare adjacent words to find character ordering
- Build directed graph of character precedence
- Topological sort gives the order

**Solution:**
```cpp
string alienOrder(vector<string>& words) {
    // Build graph
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> inDegree;
    
    // Initialize all characters
    for (const string& word : words) {
        for (char c : word) {
            if (!inDegree.count(c)) {
                inDegree[c] = 0;
                graph[c] = {};
            }
        }
    }
    
    // Build edges from adjacent word comparisons
    for (int i = 0; i < words.size() - 1; i++) {
        string& w1 = words[i];
        string& w2 = words[i + 1];
        
        // Invalid: prefix comes after longer word
        if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
            return "";
        }
        
        for (int j = 0; j < min(w1.size(), w2.size()); j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]].count(w2[j])) {
                    graph[w1[j]].insert(w2[j]);
                    inDegree[w2[j]]++;
                }
                break;
            }
        }
    }
    
    // Topological sort
    queue<char> q;
    for (auto& [c, degree] : inDegree) {
        if (degree == 0) q.push(c);
    }
    
    string result;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        result += c;
        
        for (char neighbor : graph[c]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result.size() == inDegree.size() ? result : "";
}
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
