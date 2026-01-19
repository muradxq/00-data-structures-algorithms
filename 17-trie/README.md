# 🌲 Trie Pattern (Prefix Tree)

## Overview

A **Trie** (pronounced "try") is a tree-like data structure for storing strings where each node represents a character. Tries excel at prefix-based operations and are used in autocomplete, spell checkers, and IP routing.

---

## 🧠 When to Use Trie

Use this pattern when:
- Need efficient **prefix matching**
- Implement **autocomplete** functionality
- Perform **word validation** in dictionary
- Problems with **word search** in matrix
- Keywords: "prefix", "dictionary", "word search", "autocomplete"

---

## 📐 Trie Implementation

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
    
private:
    TrieNode* findNode(string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
};
```

---

## 💡 Key Insights

### 1. Time Complexity
| Operation | Time |
|-----------|------|
| Insert | O(m) |
| Search | O(m) |
| Prefix Search | O(m) |

Where m = length of word/prefix.

### 2. Space Optimization
For lowercase letters only, use array instead of map:
```cpp
class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};
```

### 3. Trie vs HashSet
| Use Trie | Use HashSet |
|----------|-------------|
| Prefix operations | Exact word lookup |
| Autocomplete | Simple dictionary |
| Wildcard search | No prefix needed |

---

## 🎓 Example: Word Search II

**Problem:** Find all words from dictionary that exist in a grid.

```cpp
class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };
    
    TrieNode* root;
    
    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            insert(word);
        }
        
        set<string> result;
        int rows = board.size(), cols = board[0].size();
        
        function<void(int, int, TrieNode*, string)> dfs = 
            [&](int r, int c, TrieNode* node, string path) {
            
            if (node->isEnd) {
                result.insert(path);
            }
            
            if (r < 0 || r >= rows || c < 0 || c >= cols) return;
            
            char ch = board[r][c];
            if (ch == '#' || !node->children.count(ch)) return;
            
            board[r][c] = '#';  // Mark visited
            TrieNode* child = node->children[ch];
            
            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                dfs(r + dr[i], c + dc[i], child, path + ch);
            }
            
            board[r][c] = ch;  // Restore
        };
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, root, "");
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
};
```

---

*Next: [See Practice Questions →](./questions.md)*
