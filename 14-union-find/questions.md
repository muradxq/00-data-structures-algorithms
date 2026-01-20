# 📝 Union Find - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Number of Provinces | Medium | Basic | ⬜ |
| 2 | Redundant Connection | Medium | Cycle Detection | ⬜ |
| 3 | Number of Connected Components | Medium | Count | ⬜ |
| 4 | Graph Valid Tree | Medium | Tree Check | ⬜ |
| 5 | Accounts Merge | Medium | Grouping | ⬜ |
| 6 | Longest Consecutive Sequence | Medium | Consecutive | ⬜ |

---

## 🟡 Medium Problems

### 1. Number of Provinces
**LeetCode #547**

Find number of connected groups.

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

**Approach:**
- Union all directly connected cities
- Count distinct root parents

**Solution:**
```cpp
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        
        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

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
    
    unordered_set<int> provinces;
    for (int i = 0; i < n; i++) {
        provinces.insert(uf.find(i));
    }
    return provinces.size();
}
```
**Complexity:** Time O(n²α(n)), Space O(n)

---

### 2. Redundant Connection
**LeetCode #684**

Find edge that can be removed to make tree.

```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

**Approach:**
- Process edges one by one
- If both nodes have same parent, this edge creates cycle

**Solution:**
```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
    
    function<int(int)> find = [&](int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    for (auto& edge : edges) {
        int pu = find(edge[0]);
        int pv = find(edge[1]);
        
        if (pu == pv) {
            return edge;  // Already connected = cycle
        }
        parent[pu] = pv;
    }
    
    return {};
}
```
**Complexity:** Time O(nα(n)), Space O(n)

---

### 3. Number of Connected Components
**LeetCode #323** (Premium)

Count connected components in undirected graph.

```
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
```

**Solution:**
```cpp
int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    function<int(int)> find = [&](int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    int components = n;
    for (auto& edge : edges) {
        int pu = find(edge[0]);
        int pv = find(edge[1]);
        
        if (pu != pv) {
            parent[pu] = pv;
            components--;
        }
    }
    
    return components;
}
```
**Complexity:** Time O(nα(n)), Space O(n)

---

### 4. Graph Valid Tree
**LeetCode #261** (Premium)

Check if edges form a valid tree (connected, no cycles).

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Approach:**
- Tree has exactly n-1 edges
- Union-Find: if adding edge creates cycle, not a tree

**Solution:**
```cpp
bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;
    
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    function<int(int)> find = [&](int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    for (auto& edge : edges) {
        int pu = find(edge[0]);
        int pv = find(edge[1]);
        
        if (pu == pv) return false;  // Cycle detected
        parent[pu] = pv;
    }
    
    return true;
}
```
**Complexity:** Time O(nα(n)), Space O(n)

---

### 5. Accounts Merge
**LeetCode #721**

Merge accounts with common emails.

```
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
                   ["John","johnsmith@mail.com","john00@mail.com"],
                   ["Mary","mary@mail.com"],
                   ["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
         ["Mary","mary@mail.com"],
         ["John","johnnybravo@mail.com"]]
```

**Approach:**
- Union emails that belong to same account
- Group emails by root parent

**Solution:**
```cpp
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;
    
    function<string(string)> find = [&](string x) -> string {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    auto unite = [&](string x, string y) {
        string px = find(x), py = find(y);
        if (px != py) parent[px] = py;
    };
    
    // Initialize parent and map emails to names
    for (auto& account : accounts) {
        string name = account[0];
        for (int i = 1; i < account.size(); i++) {
            if (!parent.count(account[i])) {
                parent[account[i]] = account[i];
            }
            emailToName[account[i]] = name;
            unite(account[1], account[i]);
        }
    }
    
    // Group emails by root
    unordered_map<string, set<string>> groups;
    for (auto& [email, _] : parent) {
        groups[find(email)].insert(email);
    }
    
    // Build result
    vector<vector<string>> result;
    for (auto& [root, emails] : groups) {
        vector<string> account = {emailToName[root]};
        account.insert(account.end(), emails.begin(), emails.end());
        result.push_back(account);
    }
    
    return result;
}
```
**Complexity:** Time O(nkα(nk) + nk log(nk)), Space O(nk)

---

### 6. Longest Consecutive Sequence
**LeetCode #128**

Find length of longest consecutive sequence.

```
Input: nums = [100,4,200,1,3,2]
Output: 4 (sequence: [1,2,3,4])
```

**Approach (Union-Find):**
- Union consecutive numbers
- Track size of each component

```cpp
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    
    function<int(int)> find = [&](int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    auto unite = [&](int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            parent[px] = py;
            size[py] += size[px];
        }
    };
    
    for (int num : nums) {
        if (parent.count(num)) continue;
        parent[num] = num;
        size[num] = 1;
        
        if (parent.count(num - 1)) unite(num, num - 1);
        if (parent.count(num + 1)) unite(num, num + 1);
    }
    
    int maxLen = 0;
    for (auto& [num, _] : parent) {
        maxLen = max(maxLen, size[find(num)]);
    }
    return maxLen;
}
```
**Complexity:** Time O(nα(n)), Space O(n)

---

## 📚 Study Tips for Union Find

1. **Always use path compression:** Dramatically improves performance
2. **Consider union by rank:** Keeps tree balanced
3. **Know when to use:** Dynamic connectivity problems
4. **Count components:** Track count during union operations

---

*[← Back to Pattern](./README.md) | [Next Pattern: Heaps →](../15-heaps-top-k/README.md)*
