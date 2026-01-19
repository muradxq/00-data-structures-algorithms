# 🧮 Dynamic Programming Pattern

## Overview

**Dynamic Programming (DP)** is an optimization technique that solves complex problems by breaking them into simpler subproblems and storing their solutions. If you find yourself solving the same subproblem multiple times, DP can help.

---

## 🧠 When to Use Dynamic Programming

Use DP when:
- Problem has **optimal substructure** (optimal solution uses optimal solutions of subproblems)
- Problem has **overlapping subproblems** (same subproblems solved multiple times)
- Keywords: "minimum", "maximum", "count ways", "longest", "shortest", "is it possible"
- Can be framed as: "What is the best way to..." or "How many ways to..."

---

## 🎯 DP Categories

### 1. Linear DP (1D)
Single sequence or number.
- Climbing Stairs
- House Robber
- Fibonacci

### 2. Grid/Matrix DP (2D)
Two sequences or 2D grid.
- Unique Paths
- Edit Distance
- Longest Common Subsequence

### 3. Knapsack Problems
Selection with constraints.
- 0/1 Knapsack
- Coin Change
- Subset Sum

### 4. String DP
Pattern matching, palindromes.
- Longest Palindromic Substring
- Regular Expression Matching

### 5. Interval DP
Subproblems defined by intervals.
- Matrix Chain Multiplication
- Burst Balloons

---

## 📐 General Framework

### Step 1: Define State
What information do we need to represent a subproblem?
```
dp[i] = answer for first i elements
dp[i][j] = answer for elements i to j
dp[i][j] = answer using first i items with capacity j
```

### Step 2: Define Recurrence
How does current state relate to previous states?
```cpp
dp[i] = dp[i-1] + dp[i-2];  // Fibonacci
dp[i] = max(dp[i-1], dp[i-2] + nums[i]);  // House Robber
dp[i][j] = dp[i-1][j-1] + 1 if match else max(dp[i-1][j], dp[i][j-1]);  // LCS
```

### Step 3: Define Base Cases
What are the trivial subproblems?
```cpp
dp[0] = 1;  // One way to do nothing
dp[0][0] = 0;  // Zero cost for empty
```

### Step 4: Define Answer
Where is the final answer?
```cpp
return dp[n];  // Usually the last state
return dp[n][m];  // Or last cell in 2D
return *max_element(dp.begin(), dp.end());  // Sometimes need to find max
```

---

## 📐 Common Templates

### Template 1: 1D DP
```cpp
int dp1D(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = baseCase;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = recurrence(dp[i-1], dp[i-2]);
    }
    
    return dp[n];
}
```

### Template 2: 2D DP
```cpp
int dp2D(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = base;
    for (int j = 0; j <= n; j++) dp[0][j] = base;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = recurrence(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    
    return dp[m][n];
}
```

### Template 3: Top-Down with Memoization
```cpp
class Solution {
    unordered_map<int, int> memo;
public:
    int solve(int i) {
        if (memo.count(i)) return memo[i];
        
        if (baseCase) return baseValue;
        
        int result = recurrence(solve(i-1), solve(i-2));
        memo[i] = result;
        return result;
    }
    
    int dpMemo(int n) {
        return solve(n);
    }
};
```

---

## 💡 Key Insights

### 1. Top-Down vs Bottom-Up
| Top-Down (Memoization) | Bottom-Up (Tabulation) |
|------------------------|------------------------|
| Recursive + cache | Iterative + table |
| Only solves needed subproblems | Solves all subproblems |
| May have stack overflow | No recursion issues |
| Sometimes easier to think about | Usually faster |

### 2. Space Optimization
Many 2D problems only need previous row:
```cpp
// Instead of dp[m][n], use:
vector<int> prev(n + 1, 0);
vector<int> curr(n + 1, 0);

for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        curr[j] = recurrence(prev[j], curr[j-1], prev[j-1]);
    }
    swap(prev, curr);
}
```

### 3. Debugging DP
- Print the DP table
- Verify base cases
- Trace through small examples
- Check index bounds

---

## 📊 Complexity Analysis

| Type | Time | Space | Optimized Space |
|------|------|-------|-----------------|
| 1D | O(n) | O(n) | O(1) |
| 2D | O(m×n) | O(m×n) | O(n) |
| Knapsack | O(n×W) | O(n×W) | O(W) |

---

## 🎓 Example Walkthrough: Coin Change

**Problem:** Minimum coins to make amount.

```
Input: coins = [1, 2, 5], amount = 11
Output: 3 (5 + 5 + 1)
```

**State:** `dp[i]` = minimum coins to make amount i

**Recurrence:** `dp[i] = min(dp[i - coin] + 1)` for each coin

**Solution:**
```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] != INT_MAX ? dp[amount] : -1;
}
```

**DP Table for amount=11:**
```
i:     0  1  2  3  4  5  6  7  8  9  10  11
dp[i]: 0  1  1  2  2  1  2  2  3  3   2   3
```

---

## 🔗 Related Patterns

- **Recursion:** DP often starts as recursive solution
- **Greedy:** Sometimes optimal, but DP guarantees it
- **Divide & Conquer:** Similar decomposition, but subproblems don't overlap

---

## 🚨 Common Mistakes

1. **Wrong base case:** Carefully define what dp[0] means
2. **Off-by-one:** Check array bounds and loop ranges
3. **Wrong state definition:** Think carefully about what information you need
4. **Missing subproblems:** Make sure recurrence covers all cases
5. **Not recognizing DP:** Practice pattern recognition

---

*Next: [See Practice Questions →](./questions.md)*
