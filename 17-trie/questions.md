# 📝 Trie - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Implement Trie | Medium | Basic | ⬜ |
| 2 | Design Add and Search Words | Medium | Wildcard | ⬜ |
| 3 | Word Search II | Hard | Grid + Trie | ⬜ |
| 4 | Replace Words | Medium | Prefix | ⬜ |

---

## 🟡 Medium Problems

### 1. Implement Trie (Prefix Tree)
**LeetCode #208**

Implement insert, search, and startsWith.

**Solution:**
```python
class Trie:
    def __init__(self):
        self.children = {}
        self.is_end = False
    
    def insert(self, word):
        node = self
        for c in word:
            if c not in node.children:
                node.children[c] = Trie()
            node = node.children[c]
        node.is_end = True
    
    def search(self, word):
        node = self._find(word)
        return node is not None and node.is_end
    
    def startsWith(self, prefix):
        return self._find(prefix) is not None
    
    def _find(self, prefix):
        node = self
        for c in prefix:
            if c not in node.children:
                return None
            node = node.children[c]
        return node
```
**Complexity:** All operations O(m), Space O(n×m)

---

### 2. Design Add and Search Words Data Structure
**LeetCode #211**

Support '.' wildcard in search.

**Solution:**
```python
class WordDictionary:
    def __init__(self):
        self.children = {}
        self.is_end = False
    
    def addWord(self, word):
        node = self
        for c in word:
            if c not in node.children:
                node.children[c] = WordDictionary()
            node = node.children[c]
        node.is_end = True
    
    def search(self, word):
        return self._search(word, 0)
    
    def _search(self, word, idx):
        if idx == len(word):
            return self.is_end
        
        c = word[idx]
        if c == '.':
            for child in self.children.values():
                if child._search(word, idx + 1):
                    return True
            return False
        elif c in self.children:
            return self.children[c]._search(word, idx + 1)
        return False
```
**Complexity:** Add O(m), Search O(26^m) worst case with all dots

---

## 🔴 Hard Problems

### 3. Word Search II
**LeetCode #212**

Find all dictionary words in grid.

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], 
       words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Solution:**
```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

def findWords(board, words):
    root = TrieNode()
    
    # Build trie
    for word in words:
        node = root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.word = word
    
    result = []
    rows, cols = len(board), len(board[0])
    
    def dfs(r, c, node):
        char = board[r][c]
        if char not in node.children:
            return
        
        child = node.children[char]
        if child.word:
            result.append(child.word)
            child.word = None  # Avoid duplicates
        
        board[r][c] = '#'
        for dr, dc in [(0,1), (0,-1), (1,0), (-1,0)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                dfs(nr, nc, child)
        board[r][c] = char
    
    for r in range(rows):
        for c in range(cols):
            dfs(r, c, root)
    
    return result
```
**Complexity:** Time O(m×n×4^L), Space O(total characters in words)

---

## 📚 Study Tips for Trie

1. **Know when to use:** Prefix operations
2. **Space trade-off:** Array vs dictionary for children
3. **Combine with DFS:** For grid/word search problems
4. **Optimization:** Prune empty branches

---

*[← Back to Pattern](./README.md) | [Next Pattern: Bit Manipulation →](../18-bit-manipulation/README.md)*
