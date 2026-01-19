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

### 1. Word Search
**LeetCode #79**

Find if word exists in grid (adjacent cells horizontally/vertically).

```
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], 
       word = "ABCCED"
Output: true
```

**Solution:**
```python
def exist(board, word):
    rows, cols = len(board), len(board[0])
    
    def backtrack(r, c, idx):
        if idx == len(word):
            return True
        
        if (r < 0 or r >= rows or c < 0 or c >= cols or
            board[r][c] != word[idx]):
            return False
        
        # Mark as visited
        temp = board[r][c]
        board[r][c] = '#'
        
        # Explore all directions
        found = (backtrack(r+1, c, idx+1) or
                 backtrack(r-1, c, idx+1) or
                 backtrack(r, c+1, idx+1) or
                 backtrack(r, c-1, idx+1))
        
        # Restore
        board[r][c] = temp
        return found
    
    for r in range(rows):
        for c in range(cols):
            if backtrack(r, c, 0):
                return True
    return False
```
**Complexity:** Time O(m×n×4^L), Space O(L) where L = word length

---

### 2. Palindrome Partitioning
**LeetCode #131**

Partition string so every substring is a palindrome.

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Solution:**
```python
def partition(s):
    result = []
    
    def is_palindrome(sub):
        return sub == sub[::-1]
    
    def backtrack(start, current):
        if start == len(s):
            result.append(list(current))
            return
        
        for end in range(start + 1, len(s) + 1):
            substring = s[start:end]
            if is_palindrome(substring):
                current.append(substring)
                backtrack(end, current)
                current.pop()
    
    backtrack(0, [])
    return result
```
**Complexity:** Time O(n × 2^n), Space O(n)

---

### 3. Restore IP Addresses
**LeetCode #93**

Return all valid IP addresses from digit string.

```
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Solution:**
```python
def restoreIpAddresses(s):
    result = []
    
    def is_valid(segment):
        if len(segment) > 1 and segment[0] == '0':
            return False
        return 0 <= int(segment) <= 255
    
    def backtrack(start, parts):
        if len(parts) == 4:
            if start == len(s):
                result.append('.'.join(parts))
            return
        
        for length in range(1, 4):
            if start + length > len(s):
                break
            
            segment = s[start:start + length]
            if is_valid(segment):
                parts.append(segment)
                backtrack(start + length, parts)
                parts.pop()
    
    backtrack(0, [])
    return result
```
**Complexity:** Time O(1) since IP has limited combinations, Space O(1)

---

### 4. Combination Sum III
**LeetCode #216**

Find combinations of k numbers (1-9) that sum to n. Each number used once.

```
Input: k = 3, n = 7
Output: [[1,2,4]]
```

**Solution:**
```python
def combinationSum3(k, n):
    result = []
    
    def backtrack(start, current, remaining):
        if len(current) == k:
            if remaining == 0:
                result.append(list(current))
            return
        
        for num in range(start, 10):
            if num > remaining:
                break
            
            current.append(num)
            backtrack(num + 1, current, remaining - num)
            current.pop()
    
    backtrack(1, [], n)
    return result
```
**Complexity:** Time O(C(9,k)), Space O(k)

---

## 🔴 Hard Problems

### 5. N-Queens
**LeetCode #51**

Place N queens on N×N board so none attack each other.

**Solution:**
```python
def solveNQueens(n):
    result = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    cols = set()
    diag1 = set()  # row - col
    diag2 = set()  # row + col
    
    def backtrack(row):
        if row == n:
            result.append([''.join(r) for r in board])
            return
        
        for col in range(n):
            if col in cols or (row-col) in diag1 or (row+col) in diag2:
                continue
            
            board[row][col] = 'Q'
            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)
            
            backtrack(row + 1)
            
            board[row][col] = '.'
            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)
    
    backtrack(0)
    return result
```
**Complexity:** Time O(n!), Space O(n)

---

### 6. Sudoku Solver
**LeetCode #37**

Solve a Sudoku puzzle.

**Solution:**
```python
def solveSudoku(board):
    def is_valid(row, col, num):
        # Check row
        if num in board[row]:
            return False
        
        # Check column
        for r in range(9):
            if board[r][col] == num:
                return False
        
        # Check 3x3 box
        box_row, box_col = 3 * (row // 3), 3 * (col // 3)
        for r in range(box_row, box_row + 3):
            for c in range(box_col, box_col + 3):
                if board[r][c] == num:
                    return False
        
        return True
    
    def backtrack():
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    for num in '123456789':
                        if is_valid(r, c, num):
                            board[r][c] = num
                            if backtrack():
                                return True
                            board[r][c] = '.'
                    return False
        return True
    
    backtrack()
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
