# 🔄 Cyclic Sort Pattern

## Overview

The **Cyclic Sort** pattern is used to solve problems involving arrays containing numbers in a given range. The key insight is that when numbers are from 1 to n (or 0 to n-1), each number should be at its "correct" index. We iterate and place each number at its correct position.

---

## 🧠 When to Use Cyclic Sort

Use this pattern when:
- Array contains numbers in range **[1, n]** or **[0, n-1]**
- Problem asks to find **missing**, **duplicate**, or **corrupt** numbers
- Keywords: "numbers in range 1 to n", "find missing", "find duplicate"
- Need to solve in **O(n)** time and **O(1)** space

---

## 🎯 Core Concept

```
Array: [3, 1, 5, 4, 2]
Range: 1 to 5

Each number n should be at index n-1:
  1 → index 0
  2 → index 1
  3 → index 2
  4 → index 3
  5 → index 4

After sorting: [1, 2, 3, 4, 5]
```

---

## 📐 General Template

### Basic Cyclic Sort
```cpp
void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        // Correct index for nums[i]
        int correctIdx = nums[i] - 1;  // For range [1, n]
        // int correctIdx = nums[i];   // For range [0, n-1]
        
        if (nums[i] != nums[correctIdx]) {
            // Swap to correct position
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
}
```

### Find Missing Number
```cpp
int findMissing(vector<int>& nums) {
    // Place each number at correct index
    int i = 0;
    while (i < nums.size()) {
        int correctIdx = nums[i];
        if (nums[i] < nums.size() && nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    // Find where index != value
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    
    return nums.size();
}
```

---

## 💡 Key Insights

### 1. When to Swap vs Move Forward
```cpp
// Swap when number is not at correct position AND
// the correct position has a different number
if (nums[i] != nums[correctIdx]) {
    swap(nums[i], nums[correctIdx]);
}
// Move forward when:
// - Number is at correct position, OR
// - Swapping would cause infinite loop (duplicate)
else {
    i++;
}
```

### 2. Handling Range Variations
```cpp
// Range [1, n]: correctIdx = nums[i] - 1
// Range [0, n-1]: correctIdx = nums[i]
// Range [0, n] (missing one): handle out of range separately
```

### 3. Finding Anomalies After Sorting
After cyclic sort, scan array:
- If `nums[i] != i + 1`: position i is the anomaly
- Missing number: `i + 1` is missing
- Duplicate: `nums[i]` is the duplicate

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Cyclic Sort | O(n) | O(1) |
| Find Missing | O(n) | O(1) |
| Find Duplicate | O(n) | O(1) |

Note: Although there's a while loop with swaps, each number is swapped at most once to its correct position, so total swaps ≤ n.

---

## 🎓 Example Walkthrough: Find Missing Number

**Problem:** Array of n numbers from 0 to n with one missing.

```
Input: [3, 0, 1]
Range: 0 to 3, missing one number
```

**Step-by-step:**
```
i=0: nums=[3,0,1], nums[0]=3, correctIdx=3 (out of range), skip, i=1
i=1: nums=[3,0,1], nums[1]=0, correctIdx=0
     nums[0]=3 ≠ 0, swap!
     nums=[0,3,1]
i=1: nums=[0,3,1], nums[1]=3, correctIdx=3 (out of range), skip, i=2
i=2: nums=[0,3,1], nums[2]=1, correctIdx=1
     nums[1]=3 ≠ 1, swap!
     nums=[0,1,3]
i=2: nums[2]=3, correctIdx=3 (out of range), skip, i=3

Final: [0, 1, 3]

Scan for anomaly:
  nums[0]=0 ✓
  nums[1]=1 ✓
  nums[2]=3 ≠ 2 → Missing: 2
```

---

## 🔗 Related Patterns

- **Array Manipulation:** In-place modification
- **Hash Set:** Alternative approach (but uses O(n) space)

---

## 🚨 Common Mistakes

1. **Out of bounds:** Check if `correctIdx` is within array bounds
2. **Infinite loop:** Don't swap when `nums[i] == nums[correctIdx]`
3. **Wrong index formula:** Remember to adjust for 0-indexed vs 1-indexed
4. **Duplicates:** Handle duplicate numbers to avoid infinite loops

---

*Next: [See Practice Questions →](./questions.md)*
