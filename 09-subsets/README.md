# 🎲 Subsets Pattern (Combinations & Permutations)

## Overview

The **Subsets** pattern deals with finding all combinations, permutations, or subsets of a given set. These problems typically require exploring all possible solutions using a systematic approach based on recursion and backtracking.

---

## 🧠 When to Use This Pattern

Use this pattern when:
- Need to find all **subsets** of a set
- Need to find all **permutations** or **combinations**
- Need to generate all possible **arrangements**
- Keywords: "all combinations", "all subsets", "all permutations", "power set"

---

## 🎯 Three Core Problem Types

### 1. Subsets (Power Set)
Select any elements (order doesn't matter, no repetition).
```
Input: [1, 2, 3]
Output: [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
Count: 2^n = 8
```

### 2. Permutations
Arrange all elements (order matters).
```
Input: [1, 2, 3]
Output: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
Count: n! = 6
```

### 3. Combinations
Select k elements (order doesn't matter).
```
Input: n=4, k=2 (choose 2 from [1,2,3,4])
Output: [1,2], [1,3], [1,4], [2,3], [2,4], [3,4]
Count: C(n,k) = 6
```

---

## 📐 General Templates

### Subsets Template (Iterative)
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

### Subsets Template (Backtracking)
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();  // Backtrack
        }
    }
};
```

### Permutations Template
```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, current, used, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& current, 
                   vector<bool>& used, vector<vector<int>>& result) {
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
};
```

### Combinations Template
```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
    
    void backtrack(int n, int k, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(n, k, i + 1, current, result);
            current.pop_back();
        }
    }
};
```

---

## 💡 Key Insights

### 1. Handling Duplicates
When input has duplicates, sort first and skip consecutive duplicates:
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

void backtrack(vector<int>& nums, int start, vector<int>& current,
               vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i-1]) continue;
        
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}
```

### 2. Decision Tree Visualization
```
Subsets of [1, 2, 3]:
                  []
         /        |        \
       [1]       [2]       [3]
      /   \       |
   [1,2] [1,3]  [2,3]
     |
  [1,2,3]
```

### 3. Time Complexity Patterns
| Problem | Count | Complexity |
|---------|-------|------------|
| Subsets | 2^n | O(n × 2^n) |
| Permutations | n! | O(n × n!) |
| Combinations C(n,k) | n!/(k!(n-k)!) | O(k × C(n,k)) |

---

## 📊 Comparison of Approaches

| Aspect | Iterative | Backtracking |
|--------|-----------|--------------|
| Intuition | Build incrementally | Explore all paths |
| Space | Uses extra lists | Modifies in-place |
| Flexibility | Limited | Handles constraints well |

---

## 🎓 Example Walkthrough: Subsets

**Problem:** Generate all subsets of [1, 2, 3]

**Iterative approach:**
```
Start: [[]]

Add 1: [[], [1]]

Add 2: [[], [1], [2], [1,2]]

Add 3: [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]
```

**Backtracking approach:**
```
backtrack(0, [])
  → result = [[]]
  → i=0: [1]
      backtrack(1, [1])
        → result = [[], [1]]
        → i=1: [1,2]
            backtrack(2, [1,2])
              → result = [..., [1,2]]
              → i=2: [1,2,3]
                  backtrack(3, [1,2,3])
                    → result = [..., [1,2,3]]
                  pop → [1,2]
              pop → [1]
        → i=2: [1,3]
            backtrack(3, [1,3])
              → result = [..., [1,3]]
            pop → [1]
      pop → []
  → i=1: [2]
      ...
```

---

## 🔗 Related Patterns

- **Backtracking:** Foundation for this pattern
- **Dynamic Programming:** Some subset problems can use DP
- **Bit Manipulation:** Alternative approach for subsets

---

## 🚨 Common Mistakes

1. **Not copying:** Use `vector<int>(current)` or `result.push_back(current)` makes a copy
2. **Wrong start index:** For subsets/combinations, start from `i+1`; for permutations, use remaining elements
3. **Forgetting to backtrack:** Always pop after recursive call
4. **Missing duplicates handling:** Sort and skip when duplicates exist

---

*Next: [See Practice Questions →](./questions.md)*
