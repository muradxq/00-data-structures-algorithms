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

```
Operations:
- insert("apple")
- search("apple") -> true
- search("app") -> false
- startsWith("app") -> true
```

**Approach:**
- Each node has 26 children (for lowercase letters)
- Track end of word with boolean flag

**Solution:**
```cpp
class Trie {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = find(word);
        return node && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    
private:
    TrieNode* find(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return nullptr;
            node = node->children[idx];
        }
        return node;
    }
};
```
**Complexity:** All operations O(m), Space O(n×m)

---

### 2. Design Add and Search Words Data Structure
**LeetCode #211**

Support '.' wildcard in search.

```
Operations:
- addWord("bad")
- addWord("dad")
- search("pad") -> false
- search("bad") -> true
- search(".ad") -> true
- search("b..") -> true
```

**Approach:**
- Same as basic Trie for add
- For search with '.', try all children recursively

**Solution:**
```cpp
class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    
private:
    bool searchHelper(const string& word, int idx, TrieNode* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isEnd;
        
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return searchHelper(word, idx + 1, node->children[c - 'a']);
        }
    }
};
```
**Complexity:** Add O(m), Search O(26^m) worst case with all dots

---

### 4. Replace Words
**LeetCode #648**

Replace words in sentence with their root (shortest prefix in dictionary).

```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

**Approach:**
- Build Trie from dictionary
- For each word, find shortest prefix that exists in Trie

**Solution:**
```cpp
class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word;
    };
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        
        // Build Trie
        for (const string& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = word;
        }
        
        // Process sentence
        stringstream ss(sentence);
        string word, result;
        bool first = true;
        
        while (ss >> word) {
            if (!first) result += " ";
            first = false;
            
            TrieNode* node = root;
            string replacement = word;
            
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (!node->word.empty()) {
                    replacement = node->word;
                    break;
                }
            }
            
            result += replacement;
        }
        
        return result;
    }
};
```
**Complexity:** Time O(d×w + s×w), Space O(d×w) where d = dictionary size, w = word length, s = sentence words

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

**Approach:**
- Build Trie from words
- DFS from each cell, following Trie paths
- Mark found words to avoid duplicates

**Solution:**
```cpp
class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word;
    };
    
    int rows, cols;
    vector<string> result;
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        
        // Build Trie
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = word;
        }
        
        // Search
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;
        
        node = node->children[ch - 'a'];
        
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();  // Avoid duplicates
        }
        
        board[r][c] = '#';
        dfs(board, r + 1, c, node);
        dfs(board, r - 1, c, node);
        dfs(board, r, c + 1, node);
        dfs(board, r, c - 1, node);
        board[r][c] = ch;
    }
};
```
**Complexity:** Time O(m×n×4^L), Space O(total characters in words)

---

## 📚 Study Tips for Trie

1. **Know when to use:** Prefix operations, autocomplete, spell checking
2. **Space trade-off:** Array vs map for children
3. **Combine with DFS:** For grid/word search problems
4. **Optimization:** Prune empty branches, store word at end node

---

*[← Back to Pattern](./README.md) | [Next Pattern: Bit Manipulation →](../18-bit-manipulation/README.md)*
