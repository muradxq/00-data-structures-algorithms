# 📝 Backtracking - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | N-Queens | Hard | Board | ⬜ |
| 2 | N-Queens II | Hard | Count | ⬜ |
| 3 | Sudoku Solver | Hard | Board | ⬜ |
| 4 | Word Search | Medium | Grid | ⬜ |
| 5 | Palindrome Partitioning | Medium | String | ⬜ |
| 6 | Restore IP Addresses | Medium | String | ⬜ |
| 7 | Combination Sum III | Medium | Numbers | ⬜ |

---

## 🟡 Medium Problems

### 4. Word Search
**LeetCode #79**

Find if word exists in grid (adjacent cells horizontally/vertically).

```
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], 
       word = "ABCCED"
Output: true
```

**Approach:**
- DFS from each cell that matches first character
- Mark visited cells, explore 4 directions
- Backtrack by restoring cell value

**Solution:**
```cpp
bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size(), cols = board[0].size();
    
    function<bool(int, int, int)> backtrack = [&](int r, int c, int idx) -> bool {
        if (idx == word.size()) return true;
        
        if (r < 0 || r >= rows || c < 0 || c >= cols || 
            board[r][c] != word[idx]) {
            return false;
        }
        
        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';
        
        // Explore all directions
        bool found = backtrack(r + 1, c, idx + 1) ||
                     backtrack(r - 1, c, idx + 1) ||
                     backtrack(r, c + 1, idx + 1) ||
                     backtrack(r, c - 1, idx + 1);
        
        // Restore
        board[r][c] = temp;
        return found;
    };
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (backtrack(r, c, 0)) return true;
        }
    }
    return false;
}
```
**Complexity:** Time O(m×n×4^L), Space O(L) where L = word length

---

### 5. Palindrome Partitioning
**LeetCode #131**

Partition string so every substring is a palindrome.

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Approach:**
- Try all possible prefixes at each step
- If prefix is palindrome, recursively partition rest

**Solution:**
```cpp
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    
    auto isPalindrome = [](const string& str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    };
    
    function<void(int)> backtrack = [&](int start) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start + 1; end <= s.size(); end++) {
            string substring = s.substr(start, end - start);
            if (isPalindrome(substring)) {
                current.push_back(substring);
                backtrack(end);
                current.pop_back();
            }
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(n × 2^n), Space O(n)

---

### 6. Restore IP Addresses
**LeetCode #93**

Return all valid IP addresses from digit string.

```
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Approach:**
- IP has exactly 4 parts, each 0-255
- Try lengths 1-3 for each part
- Leading zeros only allowed for "0"

**Solution:**
```cpp
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> parts;
    
    auto isValid = [](const string& segment) {
        if (segment.size() > 1 && segment[0] == '0') return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    };
    
    function<void(int)> backtrack = [&](int start) {
        if (parts.size() == 4) {
            if (start == s.size()) {
                string ip = parts[0];
                for (int i = 1; i < 4; i++) {
                    ip += "." + parts[i];
                }
                result.push_back(ip);
            }
            return;
        }
        
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) break;
            
            string segment = s.substr(start, len);
            if (isValid(segment)) {
                parts.push_back(segment);
                backtrack(start + len);
                parts.pop_back();
            }
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(1) since IP has limited combinations, Space O(1)

---

### 7. Combination Sum III
**LeetCode #216**

Find combinations of k numbers (1-9) that sum to n. Each number used once.

```
Input: k = 3, n = 7
Output: [[1,2,4]]
```

**Approach:**
- Standard backtracking with two constraints: size k and sum n
- Prune when current number exceeds remaining sum

**Solution:**
```cpp
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (current.size() == k) {
            if (remaining == 0) {
                result.push_back(current);
            }
            return;
        }
        
        for (int num = start; num <= 9; num++) {
            if (num > remaining) break;  // Pruning
            
            current.push_back(num);
            backtrack(num + 1, remaining - num);
            current.pop_back();
        }
    };
    
    backtrack(1, n);
    return result;
}
```
**Complexity:** Time O(C(9,k)), Space O(k)

---

## 🔴 Hard Problems

### 1. N-Queens
**LeetCode #51**

Place N queens on N×N board so none attack each other.

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
```

**Approach:**
- Place queen row by row
- Track columns and diagonals where queens attack
- Diagonal formula: row-col (main), row+col (anti)

**Solution:**
```cpp
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    unordered_set<int> cols, diag1, diag2;
    
    function<void(int)> backtrack = [&](int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }
            
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            backtrack(row + 1);
            
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(n!), Space O(n)

---

### 2. N-Queens II
**LeetCode #52**

Count distinct N-Queens solutions.

**Solution:**
```cpp
int totalNQueens(int n) {
    int count = 0;
    unordered_set<int> cols, diag1, diag2;
    
    function<void(int)> backtrack = [&](int row) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }
            
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            backtrack(row + 1);
            
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    };
    
    backtrack(0);
    return count;
}
```
**Complexity:** Time O(n!), Space O(n)

---

### 3. Sudoku Solver
**LeetCode #37**

Solve a Sudoku puzzle.

```
Input: 9x9 board with '.' for empty cells
Output: Filled board
```

**Approach:**
- Find empty cell, try digits 1-9
- Check validity in row, column, and 3x3 box
- Backtrack if no valid digit works

**Solution:**
```cpp
void solveSudoku(vector<vector<char>>& board) {
    auto isValid = [&](int row, int col, char num) {
        // Check row
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == num) return false;
        }
        
        // Check column
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == num) return false;
        }
        
        // Check 3x3 box
        int boxRow = 3 * (row / 3), boxCol = 3 * (col / 3);
        for (int r = boxRow; r < boxRow + 3; r++) {
            for (int c = boxCol; c < boxCol + 3; c++) {
                if (board[r][c] == num) return false;
            }
        }
        
        return true;
    };
    
    function<bool()> backtrack = [&]() -> bool {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(r, c, num)) {
                            board[r][c] = num;
                            if (backtrack()) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    };
    
    backtrack();
}
```
**Complexity:** Time O(9^(empty cells)), Space O(1)

---

## 📚 Study Tips for Backtracking

1. **Identify the decision tree:** What choices at each step?
2. **Define constraints clearly:** What makes a choice invalid?
3. **Always backtrack:** Undo choices after exploring
4. **Add pruning:** Cut branches early when possible

---

*[← Back to Pattern](./README.md) | [Next Pattern: Graph Traversal →](../12-graph-traversal/README.md)*
