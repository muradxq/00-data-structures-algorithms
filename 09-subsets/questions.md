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

**Iterative Solution:**
```python
def subsets(nums):
    result = [[]]
    for num in nums:
        result += [subset + [num] for subset in result]
    return result
```

**Backtracking Solution:**
```python
def subsets(nums):
    result = []
    
    def backtrack(start, current):
        result.append(list(current))
        for i in range(start, len(nums)):
            current.append(nums[i])
            backtrack(i + 1, current)
            current.pop()
    
    backtrack(0, [])
    return result
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

**Solution:**
```python
def subsetsWithDup(nums):
    nums.sort()  # Sort to group duplicates
    result = []
    
    def backtrack(start, current):
        result.append(list(current))
        
        for i in range(start, len(nums)):
            # Skip duplicates
            if i > start and nums[i] == nums[i-1]:
                continue
            current.append(nums[i])
            backtrack(i + 1, current)
            current.pop()
    
    backtrack(0, [])
    return result
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

**Solution:**
```python
def permute(nums):
    result = []
    
    def backtrack(current, remaining):
        if not remaining:
            result.append(list(current))
            return
        
        for i in range(len(remaining)):
            current.append(remaining[i])
            backtrack(current, remaining[:i] + remaining[i+1:])
            current.pop()
    
    backtrack([], nums)
    return result
```

**Alternative (In-place Swap):**
```python
def permute(nums):
    result = []
    
    def backtrack(first):
        if first == len(nums):
            result.append(nums[:])
            return
        
        for i in range(first, len(nums)):
            nums[first], nums[i] = nums[i], nums[first]
            backtrack(first + 1)
            nums[first], nums[i] = nums[i], nums[first]
    
    backtrack(0)
    return result
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

**Solution:**
```python
def permuteUnique(nums):
    nums.sort()
    result = []
    used = [False] * len(nums)
    
    def backtrack(current):
        if len(current) == len(nums):
            result.append(list(current))
            return
        
        for i in range(len(nums)):
            if used[i]:
                continue
            # Skip duplicates: only use if previous duplicate was used
            if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                continue
            
            used[i] = True
            current.append(nums[i])
            backtrack(current)
            current.pop()
            used[i] = False
    
    backtrack([])
    return result
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

**Solution:**
```python
def combine(n, k):
    result = []
    
    def backtrack(start, current):
        if len(current) == k:
            result.append(list(current))
            return
        
        # Optimization: need at least k - len(current) more elements
        for i in range(start, n - (k - len(current)) + 2):
            current.append(i)
            backtrack(i + 1, current)
            current.pop()
    
    backtrack(1, [])
    return result
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

**Solution:**
```python
def combinationSum(candidates, target):
    result = []
    
    def backtrack(start, current, remaining):
        if remaining == 0:
            result.append(list(current))
            return
        if remaining < 0:
            return
        
        for i in range(start, len(candidates)):
            current.append(candidates[i])
            # Can reuse same element, so pass i (not i+1)
            backtrack(i, current, remaining - candidates[i])
            current.pop()
    
    backtrack(0, [], target)
    return result
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

**Solution:**
```python
def combinationSum2(candidates, target):
    candidates.sort()
    result = []
    
    def backtrack(start, current, remaining):
        if remaining == 0:
            result.append(list(current))
            return
        
        for i in range(start, len(candidates)):
            if candidates[i] > remaining:
                break  # Pruning
            if i > start and candidates[i] == candidates[i-1]:
                continue  # Skip duplicates
            
            current.append(candidates[i])
            backtrack(i + 1, current, remaining - candidates[i])
            current.pop()
    
    backtrack(0, [], target)
    return result
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

**Solution:**
```python
def letterCombinations(digits):
    if not digits:
        return []
    
    phone = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    }
    
    result = []
    
    def backtrack(index, current):
        if index == len(digits):
            result.append(current)
            return
        
        for letter in phone[digits[index]]:
            backtrack(index + 1, current + letter)
    
    backtrack(0, "")
    return result
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

**Solution:**
```python
def generateParenthesis(n):
    result = []
    
    def backtrack(current, open_count, close_count):
        if len(current) == 2 * n:
            result.append(current)
            return
        
        if open_count < n:
            backtrack(current + '(', open_count + 1, close_count)
        if close_count < open_count:
            backtrack(current + ')', open_count, close_count + 1)
    
    backtrack("", 0, 0)
    return result
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
