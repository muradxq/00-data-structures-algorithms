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

**Approach:**
- DFS/BFS from each unvisited '1'
- Mark visited cells to avoid counting twice
- Each DFS/BFS explores one complete island

**DFS Solution:**
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
**Complexity:** Time O(m×n), Space O(m×n)

---

### 2. Clone Graph
**LeetCode #133**

Return deep copy of graph.

```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: Deep copy of the graph
```

**Approach:**
- Use hashmap to track cloned nodes
- DFS to clone each node and its neighbors

**Solution:**
```cpp
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    
    unordered_map<Node*, Node*> clones;
    
    function<Node*(Node*)> dfs = [&](Node* node) -> Node* {
        if (clones.count(node)) {
            return clones[node];
        }
        
        Node* clone = new Node(node->val);
        clones[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        
        return clone;
    };
    
    return dfs(node);
}
```
**Complexity:** Time O(V+E), Space O(V)

---

### 3. Pacific Atlantic Water Flow
**LeetCode #417**

Find cells that can flow to both Pacific and Atlantic oceans.

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

**Approach:**
- DFS from ocean borders (reverse water flow)
- Find intersection of cells reachable from both oceans

**Solution:**
```cpp
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty()) return {};
    
    int rows = heights.size(), cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
    
    function<void(int, int, vector<vector<bool>>&, int)> dfs = 
        [&](int r, int c, vector<vector<bool>>& visited, int prevHeight) {
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        visited[r][c] = true;
        dfs(r + 1, c, visited, heights[r][c]);
        dfs(r - 1, c, visited, heights[r][c]);
        dfs(r, c + 1, visited, heights[r][c]);
        dfs(r, c - 1, visited, heights[r][c]);
    };
    
    // Start from ocean borders
    for (int c = 0; c < cols; c++) {
        dfs(0, c, pacific, 0);          // Pacific top
        dfs(rows - 1, c, atlantic, 0);  // Atlantic bottom
    }
    for (int r = 0; r < rows; r++) {
        dfs(r, 0, pacific, 0);          // Pacific left
        dfs(r, cols - 1, atlantic, 0);  // Atlantic right
    }
    
    vector<vector<int>> result;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (pacific[r][c] && atlantic[r][c]) {
                result.push_back({r, c});
            }
        }
    }
    
    return result;
}
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 4. Rotting Oranges
**LeetCode #994**

Find minimum minutes for all oranges to rot (multi-source BFS).

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Approach:**
- Multi-source BFS starting from all rotten oranges
- Track minutes level by level

**Solution:**
```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    
    // Find all rotten oranges and count fresh
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                q.push({r, c});
            } else if (grid[r][c] == 1) {
                fresh++;
            }
        }
    }
    
    if (fresh == 0) return 0;
    
    int minutes = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    while (!q.empty()) {
        minutes++;
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    return fresh == 0 ? minutes - 1 : -1;
}
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 6. Course Schedule
**LeetCode #207**

Can finish all courses given prerequisites? (Cycle detection)

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true (Take course 0, then course 1)
```

**Approach:**
- Build adjacency list
- DFS with state tracking: 0=unvisited, 1=visiting, 2=visited
- Cycle exists if we reach a "visiting" node

**Solution:**
```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto& prereq : prerequisites) {
        graph[prereq[0]].push_back(prereq[1]);
    }
    
    // 0: unvisited, 1: visiting, 2: visited
    vector<int> state(numCourses, 0);
    
    function<bool(int)> hasCycle = [&](int course) -> bool {
        if (state[course] == 1) return true;   // Cycle
        if (state[course] == 2) return false;  // Already done
        
        state[course] = 1;
        for (int prereq : graph[course]) {
            if (hasCycle(prereq)) return true;
        }
        state[course] = 2;
        return false;
    };
    
    for (int course = 0; course < numCourses; course++) {
        if (hasCycle(course)) return false;
    }
    
    return true;
}
```
**Complexity:** Time O(V+E), Space O(V+E)

---

### 7. Graph Valid Tree
**LeetCode #261** (Premium)

Check if edges form a valid tree (connected, no cycles).

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Approach:**
- Tree has exactly n-1 edges
- Must be connected (all nodes reachable from any node)
- No cycles

**Solution:**
```cpp
bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;  // Tree has n-1 edges
    
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int count = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return count == n;  // All nodes reachable
}
```
**Complexity:** Time O(V+E), Space O(V+E)

---

### 8. Number of Connected Components
**LeetCode #323** (Premium)

Count connected components in undirected graph.

```
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
```

**Solution:**
```cpp
int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    int count = 0;
    
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }
    
    return count;
}
```
**Complexity:** Time O(V+E), Space O(V+E)

---

## 🔴 Hard Problems

### 5. Word Ladder
**LeetCode #127**

Find shortest transformation from beginWord to endWord.

```
Input: beginWord = "hit", endWord = "cog", 
       wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5 ("hit" -> "hot" -> "dot" -> "dog" -> "cog")
```

**Approach:**
- BFS for shortest path
- Try all possible single-character changes at each step

**Solution:**
```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);
    
    while (!q.empty()) {
        auto [word, length] = q.front();
        q.pop();
        
        for (int i = 0; i < word.size(); i++) {
            string next = word;
            for (char c = 'a'; c <= 'z'; c++) {
                next[i] = c;
                
                if (next == endWord) return length + 1;
                
                if (wordSet.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, length + 1});
                }
            }
        }
    }
    
    return 0;
}
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
