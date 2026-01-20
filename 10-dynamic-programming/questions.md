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

**Approach:**
- dp[i] = dp[i-1] + dp[i-2] (Fibonacci pattern)
- Can reach step i from i-1 or i-2

**Solution:**
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 4. Min Cost Climbing Stairs
**LeetCode #746**

Each step has a cost. Find minimum cost to reach top.

```
Input: cost = [10,15,20]
Output: 15 (Start at index 1, pay 15, jump to top)
```

**Approach:**
- dp[i] = cost[i] + min(dp[i-1], dp[i-2])
- Can start from index 0 or 1

**Solution:**
```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev2 = cost[0], prev1 = cost[1];
    
    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return min(prev1, prev2);
}
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 2. House Robber
**LeetCode #198**

Can't rob adjacent houses. Maximize money.

```
Input: nums = [2,7,9,3,1]
Output: 12 (2 + 9 + 1)
```

**Approach:**
- dp[i] = max(dp[i-1], dp[i-2] + nums[i])
- Either skip current house or rob it

**Solution:**
```cpp
int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    
    for (int i = 2; i < nums.size(); i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 3. House Robber II
**LeetCode #213**

Houses in a circle (first and last are adjacent).

```
Input: nums = [2,3,2]
Output: 3
```

**Approach:**
- Either skip first house or skip last house
- Take max of both cases

**Solution:**
```cpp
int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    auto robLinear = [](vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    };
    
    return max(robLinear(nums, 0, nums.size() - 2),
               robLinear(nums, 1, nums.size() - 1));
}
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

**Approach:**
- dp[i] = min coins to make amount i
- For each coin, dp[i] = min(dp[i], dp[i-coin] + 1)

**Solution:**
```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
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

**Approach:**
- Iterate coins first to avoid counting permutations as different
- dp[i] = number of ways to make amount i

**Solution:**
```cpp
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {  // Iterate coins first
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}
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
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
```

**O(n log n) Solution (Binary Search):**
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return tails.size();
}
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

**Approach:**
- 2D DP: dp[i][j] = LCS of text1[0..i-1] and text2[0..j-1]
- If chars match, dp[i][j] = dp[i-1][j-1] + 1

**Solution:**
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
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

**Approach:**
- dp[j] = paths to reach column j in current row
- Update: dp[j] += dp[j-1]

**Solution:**
```cpp
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
        }
    }
    
    return dp[n-1];
}
```
**Complexity:** Time O(m×n), Space O(n)

---

### 10. Unique Paths II
**LeetCode #63**

Same as Unique Paths but with obstacles.

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
```

**Solution:**
```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) return 0;
    
    vector<long> dp(n, 0);
    dp[0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] += dp[j-1];
            }
        }
    }
    
    return dp[n-1];
}
```
**Complexity:** Time O(m×n), Space O(n)

---

### 11. Minimum Path Sum
**LeetCode #64**

Find path with minimum sum in grid.

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7 (1→3→1→1→1)
```

**Approach:**
- dp[i][j] = minimum sum to reach (i,j)
- dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

**Solution:**
```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) grid[i][j] += grid[i][j-1];
            else if (j == 0) grid[i][j] += grid[i-1][j];
            else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    
    return grid[m-1][n-1];
}
```
**Complexity:** Time O(m×n), Space O(1)

---

### 12. Word Break
**LeetCode #139**

Check if string can be segmented into dictionary words.

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
```

**Approach:**
- dp[i] = true if s[0..i-1] can be segmented
- For each position, check all possible words ending there

**Solution:**
```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}
```
**Complexity:** Time O(n² × m), Space O(n)

---

### 13. Palindromic Substrings
**LeetCode #647**

Count palindromic substrings.

```
Input: s = "abc"
Output: 3 ("a", "b", "c")
```

**Approach:**
- Expand around center for each position
- Count both odd and even length palindromes

**Solution:**
```cpp
int countSubstrings(string s) {
    int count = 0;
    int n = s.size();
    
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        expandAroundCenter(i, i);      // Odd length
        expandAroundCenter(i, i + 1);  // Even length
    }
    
    return count;
}
```
**Complexity:** Time O(n²), Space O(1)

---

### 14. Longest Palindromic Substring
**LeetCode #5**

Find longest palindromic substring.

```
Input: s = "babad"
Output: "bab" or "aba"
```

**Solution:**
```cpp
string longestPalindrome(string s) {
    int start = 0, maxLen = 0;
    int n = s.size();
    
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        expandAroundCenter(i, i);      // Odd
        expandAroundCenter(i, i + 1);  // Even
    }
    
    return s.substr(start, maxLen);
}
```
**Complexity:** Time O(n²), Space O(1)

---

### 15. Edit Distance
**LeetCode #72**

Minimum operations (insert, delete, replace) to convert word1 to word2.

```
Input: word1 = "horse", word2 = "ros"
Output: 3
```

**Approach:**
- dp[i][j] = min ops to convert word1[0..i-1] to word2[0..j-1]
- If chars match: dp[i][j] = dp[i-1][j-1]
- Else: 1 + min(delete, insert, replace)

**Solution:**
```cpp
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j],     // Delete
                                   dp[i][j-1],     // Insert
                                   dp[i-1][j-1]}); // Replace
            }
        }
    }
    
    return dp[m][n];
}
```
**Complexity:** Time O(m×n), Space O(m×n)

---

### 16. Partition Equal Subset Sum
**LeetCode #416**

Can array be partitioned into two subsets with equal sum?

```
Input: nums = [1,5,11,5]
Output: true ([1,5,5] and [11])
```

**Approach:**
- 0/1 Knapsack: can we make sum/2?
- dp[j] = true if we can make sum j

**Solution:**
```cpp
bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;
    
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int num : nums) {
        for (int j = target; j >= num; j--) {  // Reverse to avoid reuse
            dp[j] = dp[j] || dp[j - num];
        }
    }
    
    return dp[target];
}
```
**Complexity:** Time O(n × sum), Space O(sum)

---

### 17. Target Sum
**LeetCode #494**

Count ways to assign +/- to each number to reach target.

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
```

**Approach:**
- If sum of + is P and - is N: P - N = target, P + N = sum
- So P = (target + sum) / 2
- Reduce to subset sum count

**Solution:**
```cpp
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || abs(target) > sum) return 0;
    
    int newTarget = (sum + target) / 2;
    vector<int> dp(newTarget + 1, 0);
    dp[0] = 1;
    
    for (int num : nums) {
        for (int j = newTarget; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    
    return dp[newTarget];
}
```
**Complexity:** Time O(n × target), Space O(target)

---

### 18. Decode Ways
**LeetCode #91**

Count ways to decode digit string (A=1, B=2, ..., Z=26).

```
Input: s = "226"
Output: 3 ("BZ", "VF", "BBF")
```

**Solution:**
```cpp
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    
    int n = s.size();
    int prev2 = 1, prev1 = 1;
    
    for (int i = 1; i < n; i++) {
        int curr = 0;
        if (s[i] != '0') {
            curr = prev1;
        }
        int twoDigit = stoi(s.substr(i - 1, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            curr += prev2;
        }
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 19. Maximal Square
**LeetCode #221**

Find largest square containing only 1s.

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]]
Output: 4
```

**Approach:**
- dp[i][j] = side length of largest square ending at (i,j)
- If '1': dp[i][j] = min(left, top, diagonal) + 1

**Solution:**
```cpp
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxSide = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i-1][j-1] == '1') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    
    return maxSide * maxSide;
}
```
**Complexity:** Time O(m×n), Space O(m×n)

---

## 🔴 Hard Problems

### 20. Burst Balloons
**LeetCode #312**

Burst balloons to maximize coins. Bursting i gives nums[left] * nums[i] * nums[right].

```
Input: nums = [3,1,5,8]
Output: 167
```

**Approach:**
- Interval DP: dp[i][j] = max coins for bursting balloons in (i,j)
- Try each k as last balloon to burst in interval

**Solution:**
```cpp
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
    for (int len = 1; len <= n; len++) {
        for (int left = 1; left <= n - len + 1; left++) {
            int right = left + len - 1;
            for (int k = left; k <= right; k++) {
                dp[left][right] = max(dp[left][right],
                    dp[left][k-1] + nums[left-1] * nums[k] * nums[right+1] + dp[k+1][right]);
            }
        }
    }
    
    return dp[1][n];
}
```
**Complexity:** Time O(n³), Space O(n²)

---

## 📚 Study Tips for Dynamic Programming

1. **Start with recursion:** Write recursive solution first, then optimize
2. **Identify state:** What information defines a subproblem?
3. **Draw the table:** Visualize DP table to understand transitions
4. **Look for patterns:** Many problems follow similar templates
5. **Practice regularly:** DP improves with practice

---

*[← Back to Pattern](./README.md) | [Next Pattern: Backtracking →](../11-backtracking/README.md)*
