# 📝 Subsets - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Subsets | Medium | Power Set | ⬜ |
| 2 | Subsets II | Medium | With Duplicates | ⬜ |
| 3 | Permutations | Medium | All Arrangements | ⬜ |
| 4 | Permutations II | Medium | With Duplicates | ⬜ |
| 5 | Combinations | Medium | Choose k | ⬜ |
| 6 | Combination Sum | Medium | Unlimited Use | ⬜ |
| 7 | Combination Sum II | Medium | Limited Use | ⬜ |
| 8 | Letter Combinations of Phone | Medium | Cartesian Product | ⬜ |
| 9 | Generate Parentheses | Medium | Valid Sequences | ⬜ |

---

## 🟡 Medium Problems

### 1. Subsets
**LeetCode #78**

Generate all subsets of distinct integers.

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Approach:**
- For each element, we can either include or exclude it
- Use backtracking to explore all possibilities

**Iterative Solution:**
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    
    for (int num : nums) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            vector<int> subset = result[i];
            subset.push_back(num);
            result.push_back(subset);
        }
    }
    
    return result;
}
```

**Backtracking Solution:**
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int)> backtrack = [&](int start) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1);
            current.pop_back();
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(n × 2^n), Space O(n)

---

### 2. Subsets II (With Duplicates)
**LeetCode #90**

Generate subsets when input may have duplicates.

```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Approach:**
- Sort to group duplicates
- Skip duplicates at same level of recursion

**Solution:**
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int)> backtrack = [&](int start) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            backtrack(i + 1);
            current.pop_back();
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(n × 2^n), Space O(n)

---

### 3. Permutations
**LeetCode #46**

Generate all permutations of distinct integers.

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Approach:**
- At each position, try all remaining numbers
- Use swap-based approach to generate in-place

**Solution:**
```cpp
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    
    function<void(int)> backtrack = [&](int first) {
        if (first == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = first; i < nums.size(); i++) {
            swap(nums[first], nums[i]);
            backtrack(first + 1);
            swap(nums[first], nums[i]);
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(n × n!), Space O(n)

---

### 4. Permutations II (With Duplicates)
**LeetCode #47**

Generate unique permutations when input has duplicates.

```
Input: nums = [1,1,2]
Output: [[1,1,2],[1,2,1],[2,1,1]]
```

**Approach:**
- Sort to group duplicates
- Use used array to track which elements are used
- Skip if previous duplicate wasn't used (ensures same-level uniqueness)

**Solution:**
```cpp
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    
    function<void()> backtrack = [&]() {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            // Skip duplicates: only use if previous duplicate was used
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            used[i] = true;
            current.push_back(nums[i]);
            backtrack();
            current.pop_back();
            used[i] = false;
        }
    };
    
    backtrack();
    return result;
}
```
**Complexity:** Time O(n × n!), Space O(n)

---

### 5. Combinations
**LeetCode #77**

Find all combinations of k numbers from [1, n].

```
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
```

**Approach:**
- Standard backtracking with size constraint
- Pruning: stop early if not enough numbers left

**Solution:**
```cpp
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int)> backtrack = [&](int start) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Optimization: need at least k - current.size() more elements
        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            current.push_back(i);
            backtrack(i + 1);
            current.pop_back();
        }
    };
    
    backtrack(1);
    return result;
}
```
**Complexity:** Time O(k × C(n,k)), Space O(k)

---

### 6. Combination Sum
**LeetCode #39**

Find combinations that sum to target. Numbers can be used unlimited times.

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
```

**Approach:**
- Use same index (not i+1) to allow reuse of elements
- Stop when remaining < 0

**Solution:**
```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (remaining < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            // Can reuse same element, so pass i (not i+1)
            backtrack(i, remaining - candidates[i]);
            current.pop_back();
        }
    };
    
    backtrack(0, target);
    return result;
}
```
**Complexity:** Time O(n^(target/min)), Space O(target/min)

---

### 7. Combination Sum II
**LeetCode #40**

Find combinations that sum to target. Each number used at most once.

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
```

**Approach:**
- Sort to group duplicates
- Skip duplicates at same level
- Use i+1 to prevent reuse

**Solution:**
```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) break;  // Pruning
            if (i > start && candidates[i] == candidates[i-1]) continue;  // Skip duplicates
            
            current.push_back(candidates[i]);
            backtrack(i + 1, remaining - candidates[i]);
            current.pop_back();
        }
    };
    
    backtrack(0, target);
    return result;
}
```
**Complexity:** Time O(2^n), Space O(n)

---

### 8. Letter Combinations of a Phone Number
**LeetCode #17**

Generate all letter combinations for phone digits.

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Approach:**
- Map digits to letters
- Backtrack through each digit, trying all possible letters

**Solution:**
```cpp
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string> result;
    string current;
    
    function<void(int)> backtrack = [&](int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        for (char letter : phone[digits[index]]) {
            current.push_back(letter);
            backtrack(index + 1);
            current.pop_back();
        }
    };
    
    backtrack(0);
    return result;
}
```
**Complexity:** Time O(4^n × n), Space O(n)

---

### 9. Generate Parentheses
**LeetCode #22**

Generate all valid combinations of n pairs of parentheses.

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Approach:**
- Track open and close count
- Add '(' if open < n
- Add ')' if close < open (ensures validity)

**Solution:**
```cpp
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    
    function<void(int, int)> backtrack = [&](int openCount, int closeCount) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (openCount < n) {
            current.push_back('(');
            backtrack(openCount + 1, closeCount);
            current.pop_back();
        }
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(openCount, closeCount + 1);
            current.pop_back();
        }
    };
    
    backtrack(0, 0);
    return result;
}
```
**Complexity:** Time O(4^n / √n), Space O(n)

---

## 📚 Study Tips for Subsets Pattern

1. **Know your type:** Subsets vs Permutations vs Combinations
2. **Handle duplicates:** Sort first, then skip
3. **Choose start index:** `i+1` for subsets, `i` for reuse, `0` with used array for permutations
4. **Pruning:** Cut branches early when possible

---

*[← Back to Pattern](./README.md) | [Next Pattern: Dynamic Programming →](../10-dynamic-programming/README.md)*
