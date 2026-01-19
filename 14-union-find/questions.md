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

**Solution:**
```python
def findCircleNum(isConnected):
    n = len(isConnected)
    parent = list(range(n))
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        px, py = find(x), find(y)
        if px != py:
            parent[px] = py
    
    for i in range(n):
        for j in range(i + 1, n):
            if isConnected[i][j]:
                union(i, j)
    
    return len(set(find(i) for i in range(n)))
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

**Solution:**
```python
def findRedundantConnection(edges):
    n = len(edges)
    parent = list(range(n + 1))
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    for u, v in edges:
        pu, pv = find(u), find(v)
        if pu == pv:
            return [u, v]  # Already connected = cycle
        parent[pu] = pv
    
    return []
```
**Complexity:** Time O(nα(n)), Space O(n)

---

### 3. Graph Valid Tree
**LeetCode #261** (Premium)

Check if edges form a valid tree (connected, no cycles).

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Solution:**
```python
def validTree(n, edges):
    if len(edges) != n - 1:  # Tree has exactly n-1 edges
        return False
    
    parent = list(range(n))
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    for u, v in edges:
        pu, pv = find(u), find(v)
        if pu == pv:
            return False  # Cycle detected
        parent[pu] = pv
    
    return True
```
**Complexity:** Time O(nα(n)), Space O(n)

---

### 4. Accounts Merge
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

**Solution:**
```python
from collections import defaultdict

def accountsMerge(accounts):
    parent = {}
    email_to_name = {}
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        px, py = find(x), find(y)
        if px != py:
            parent[px] = py
    
    # Initialize parent and map emails to names
    for account in accounts:
        name = account[0]
        for email in account[1:]:
            if email not in parent:
                parent[email] = email
            email_to_name[email] = name
            union(account[1], email)
    
    # Group emails by root
    groups = defaultdict(list)
    for email in parent:
        groups[find(email)].append(email)
    
    # Build result
    result = []
    for root, emails in groups.items():
        name = email_to_name[root]
        result.append([name] + sorted(emails))
    
    return result
```
**Complexity:** Time O(nkα(nk) + nk log(nk)), Space O(nk)

---

## 📚 Study Tips for Union Find

1. **Always use path compression:** Dramatically improves performance
2. **Consider union by rank:** Keeps tree balanced
3. **Know when to use:** Dynamic connectivity problems
4. **Count components:** Track count during union operations

---

*[← Back to Pattern](./README.md) | [Next Pattern: Heaps →](../15-heaps-top-k/README.md)*
