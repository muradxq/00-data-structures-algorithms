# 🔙 Backtracking Pattern

## Overview

**Backtracking** is a systematic way to explore all potential solutions by building candidates incrementally and abandoning ("backtracking") as soon as it's determined that the candidate cannot lead to a valid solution.

Think of it as exploring a maze: you try a path, and if you hit a dead end, you go back and try another path.

---

## 🧠 When to Use Backtracking

Use backtracking when:
- Need to find **all** solutions (not just one)
- Problem involves making a series of **choices**
- Choices have **constraints** that must be satisfied
- Keywords: "all combinations", "all permutations", "generate all", "find all valid"
- Can be modeled as a **decision tree**

---

## 🎯 Core Concept

### Decision Tree
```
N-Queens (N=4): Place queens so none attack each other

                    Start
                 /   |   \   \
               Q1   Q1   Q1   Q1    (Row 0: col 0,1,2,3)
              /|\   /|\  
            ...     Q2 at different cols (Row 1)
                   /|\ 
                  ...   (Keep going or backtrack if invalid)
```

### Three Key Components
1. **Choice:** What options do we have at each step?
2. **Constraint:** Which choices are valid?
3. **Goal:** When have we found a complete solution?

---

## 📐 General Template

```cpp
void backtrack(State& state, vector<Choice>& choices, vector<Result>& result) {
    // Base case: found valid solution
    if (isGoal(state)) {
        result.push_back(state);
        return;
    }
    
    for (auto& choice : choices) {
        // Constraint: skip invalid choices
        if (!isValid(choice, state)) continue;
        
        // Make choice
        makeChoice(state, choice);
        
        // Recurse
        backtrack(state, remainingChoices, result);
        
        // Undo choice (backtrack)
        undoChoice(state, choice);
    }
}
```

### Specific Templates

#### For Combinations/Subsets
```cpp
void backtrack(vector<int>& nums, int start, vector<int>& current, 
               vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}
```

#### For Permutations
```cpp
void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used,
               vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}
```

#### For Grid/Board Problems
```cpp
bool backtrack(vector<vector<char>>& board, int row, int col) {
    if (row == n) {  // Filled all rows
        return true;
    }
    
    int nextRow = (col == n-1) ? row + 1 : row;
    int nextCol = (col + 1) % n;
    
    for (char choice : choices) {
        if (isValid(board, row, col, choice)) {
            board[row][col] = choice;
            if (backtrack(board, nextRow, nextCol)) {
                return true;
            }
            board[row][col] = '.';  // empty
        }
    }
    
    return false;
}
```

---

## 💡 Key Insights

### 1. Backtracking vs DP vs Greedy
| Approach | When to Use | Explores |
|----------|-------------|----------|
| Backtracking | All solutions, constraints | All paths |
| DP | Optimal solution, overlapping subproblems | Unique states |
| Greedy | Local optimal = global optimal | One path |

### 2. Pruning
Cut branches early to improve performance:
```cpp
// Example: N-Queens pruning
if (cols.count(col) || diag1.count(row-col) || diag2.count(row+col)) {
    continue;  // Prune this branch
}
```

### 3. State Management
Two approaches:
```cpp
// Approach 1: Modify and restore
state.insert(choice);
backtrack(...);
state.erase(choice);

// Approach 2: Pass new state (more memory)
backtrack(newState, ...);
```

---

## 📊 Complexity Analysis

Backtracking typically has exponential complexity:
- **Subsets:** O(2^n)
- **Permutations:** O(n!)
- **N-Queens:** O(n!)

Pruning can significantly reduce actual runtime but doesn't change worst-case complexity.

---

## 🎓 Example Walkthrough: N-Queens

**Problem:** Place N queens on N×N board so no two attack each other.

```
N = 4, One solution:
. Q . .
. . . Q
Q . . .
. . Q .
```

**Solution:**
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;      // Columns with queens
        unordered_set<int> diag1;     // Row - Col diagonals
        unordered_set<int> diag2;     // Row + Col diagonals
        
        backtrack(n, 0, board, cols, diag1, diag2, result);
        return result;
    }
    
    void backtrack(int n, int row, vector<string>& board,
                   unordered_set<int>& cols, unordered_set<int>& diag1,
                   unordered_set<int>& diag2, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            // Check constraints
            if (cols.count(col) || diag1.count(row-col) || diag2.count(row+col)) {
                continue;
            }
            
            // Make choice
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            // Recurse
            backtrack(n, row + 1, board, cols, diag1, diag2, result);
            
            // Undo choice
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};
```

---

## 🔗 Related Patterns

- **DFS:** Backtracking is DFS with pruning
- **Subsets:** Special case of backtracking
- **Recursion:** Foundation of backtracking

---

## 🚨 Common Mistakes

1. **Forgetting to backtrack:** Always undo the choice
2. **Wrong base case:** Know when solution is complete
3. **Missing pruning:** Can cause timeout on large inputs
4. **Not copying state:** Make sure to copy when storing result

---

*Next: [See Practice Questions →](./questions.md)*
