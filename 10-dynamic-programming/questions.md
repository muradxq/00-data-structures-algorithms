# 📝 Dynamic Programming - Practice Questions

## Question Checklist

### Beginner DP
| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Climbing Stairs | Easy | 1D | ⬜ |
| 2 | House Robber | Medium | 1D | ⬜ |
| 3 | House Robber II | Medium | 1D Circular | ⬜ |
| 4 | Min Cost Climbing Stairs | Easy | 1D | ⬜ |

### Classic DP
| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 5 | Coin Change | Medium | Unbounded Knapsack | ⬜ |
| 6 | Coin Change II | Medium | Count Ways | ⬜ |
| 7 | Longest Increasing Subsequence | Medium | 1D | ⬜ |
| 8 | Longest Common Subsequence | Medium | 2D | ⬜ |

### Grid DP
| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 9 | Unique Paths | Medium | Grid | ⬜ |
| 10 | Unique Paths II | Medium | Grid with Obstacles | ⬜ |
| 11 | Minimum Path Sum | Medium | Grid | ⬜ |

### String DP
| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 12 | Word Break | Medium | String | ⬜ |
| 13 | Palindromic Substrings | Medium | String | ⬜ |
| 14 | Longest Palindromic Substring | Medium | String | ⬜ |
| 15 | Edit Distance | Medium | 2D String | ⬜ |

### Advanced DP
| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 16 | Partition Equal Subset Sum | Medium | 0/1 Knapsack | ⬜ |
| 17 | Target Sum | Medium | Knapsack Variant | ⬜ |
| 18 | Decode Ways | Medium | 1D | ⬜ |
| 19 | Maximal Square | Medium | Grid | ⬜ |
| 20 | Burst Balloons | Hard | Interval | ⬜ |

---

## 🟢 Easy Problems

### 1. Climbing Stairs
**LeetCode #70**

n steps to top. Can climb 1 or 2 steps. How many ways?

```
Input: n = 3
Output: 3 (1+1+1, 1+2, 2+1)
```

**Solution:**
```python
def climbStairs(n):
    if n <= 2:
        return n
    
    prev2, prev1 = 1, 2
    for i in range(3, n + 1):
        curr = prev1 + prev2
        prev2, prev1 = prev1, curr
    
    return prev1
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Min Cost Climbing Stairs
**LeetCode #746**

Each step has a cost. Find minimum cost to reach top.

```
Input: cost = [10,15,20]
Output: 15 (Start at index 1, pay 15, jump to top)
```

**Solution:**
```python
def minCostClimbingStairs(cost):
    n = len(cost)
    prev2, prev1 = cost[0], cost[1]
    
    for i in range(2, n):
        curr = cost[i] + min(prev1, prev2)
        prev2, prev1 = prev1, curr
    
    return min(prev1, prev2)
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 3. House Robber
**LeetCode #198**

Can't rob adjacent houses. Maximize money.

```
Input: nums = [2,7,9,3,1]
Output: 12 (2 + 9 + 1)
```

**Solution:**
```python
def rob(nums):
    if len(nums) == 1:
        return nums[0]
    
    prev2, prev1 = nums[0], max(nums[0], nums[1])
    
    for i in range(2, len(nums)):
        curr = max(prev1, prev2 + nums[i])
        prev2, prev1 = prev1, curr
    
    return prev1
```
**Complexity:** Time O(n), Space O(1)

---

### 4. House Robber II
**LeetCode #213**

Houses in a circle (first and last are adjacent).

**Solution:**
```python
def rob(nums):
    if len(nums) == 1:
        return nums[0]
    
    def rob_linear(houses):
        prev2, prev1 = 0, 0
        for money in houses:
            curr = max(prev1, prev2 + money)
            prev2, prev1 = prev1, curr
        return prev1
    
    # Either skip first house or skip last house
    return max(rob_linear(nums[1:]), rob_linear(nums[:-1]))
```
**Complexity:** Time O(n), Space O(1)

---

### 5. Coin Change
**LeetCode #322**

Minimum coins to make amount.

```
Input: coins = [1,2,5], amount = 11
Output: 3 (5+5+1)
```

**Solution:**
```python
def coinChange(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1
```
**Complexity:** Time O(amount × coins), Space O(amount)

---

### 6. Coin Change II
**LeetCode #518**

Count number of ways to make amount.

```
Input: amount = 5, coins = [1,2,5]
Output: 4 (5, 2+2+1, 2+1+1+1, 1+1+1+1+1)
```

**Solution:**
```python
def change(amount, coins):
    dp = [0] * (amount + 1)
    dp[0] = 1
    
    for coin in coins:  # Iterate coins first to avoid counting permutations
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    
    return dp[amount]
```
**Complexity:** Time O(amount × coins), Space O(amount)

---

### 7. Longest Increasing Subsequence
**LeetCode #300**

Find length of longest strictly increasing subsequence.

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4 ([2,3,7,101])
```

**O(n²) Solution:**
```python
def lengthOfLIS(nums):
    n = len(nums)
    dp = [1] * n
    
    for i in range(1, n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    return max(dp)
```

**O(n log n) Solution (Binary Search):**
```python
from bisect import bisect_left

def lengthOfLIS(nums):
    tails = []
    
    for num in nums:
        pos = bisect_left(tails, num)
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    
    return len(tails)
```
**Complexity:** Time O(n log n), Space O(n)

---

### 8. Longest Common Subsequence
**LeetCode #1143**

Find length of longest common subsequence.

```
Input: text1 = "abcde", text2 = "ace"
Output: 3 ("ace")
```

**Solution:**
```python
def longestCommonSubsequence(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]
```
**Complexity:** Time O(m×n), Space O(m×n) or O(n) optimized

---

### 9. Unique Paths
**LeetCode #62**

Count paths from top-left to bottom-right (can only move right or down).

```
Input: m = 3, n = 7
Output: 28
```

**Solution:**
```python
def uniquePaths(m, n):
    dp = [1] * n
    
    for i in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j-1]
    
    return dp[n-1]
```
**Complexity:** Time O(m×n), Space O(n)

---

### 10. Minimum Path Sum
**LeetCode #64**

Find path with minimum sum in grid.

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7 (1→3→1→1→1)
```

**Solution:**
```python
def minPathSum(grid):
    m, n = len(grid), len(grid[0])
    
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                continue
            elif i == 0:
                grid[i][j] += grid[i][j-1]
            elif j == 0:
                grid[i][j] += grid[i-1][j]
            else:
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])
    
    return grid[m-1][n-1]
```
**Complexity:** Time O(m×n), Space O(1)

---

### 11. Word Break
**LeetCode #139**

Check if string can be segmented into dictionary words.

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
```

**Solution:**
```python
def wordBreak(s, wordDict):
    word_set = set(wordDict)
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    
    return dp[n]
```
**Complexity:** Time O(n² × m), Space O(n)

---

### 12. Edit Distance
**LeetCode #72**

Minimum operations (insert, delete, replace) to convert word1 to word2.

```
Input: word1 = "horse", word2 = "ros"
Output: 3
```

**Solution:**
```python
def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Base cases
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i-1] == word2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(
                    dp[i-1][j],    # Delete
                    dp[i][j-1],    # Insert
                    dp[i-1][j-1]   # Replace
                )
    
    return dp[m][n]
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 13. Partition Equal Subset Sum
**LeetCode #416**

Can array be partitioned into two subsets with equal sum?

```
Input: nums = [1,5,11,5]
Output: true ([1,5,5] and [11])
```

**Solution:**
```python
def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    
    for num in nums:
        for j in range(target, num - 1, -1):  # Reverse to avoid reuse
            dp[j] = dp[j] or dp[j - num]
    
    return dp[target]
```
**Complexity:** Time O(n × sum), Space O(sum)

---

## 📚 Study Tips for Dynamic Programming

1. **Start with recursion:** Write recursive solution first, then optimize
2. **Identify state:** What information defines a subproblem?
3. **Draw the table:** Visualize DP table to understand transitions
4. **Look for patterns:** Many problems follow similar templates
5. **Practice regularly:** DP improves with practice

---

*[← Back to Pattern](./README.md) | [Next Pattern: Backtracking →](../11-backtracking/README.md)*
