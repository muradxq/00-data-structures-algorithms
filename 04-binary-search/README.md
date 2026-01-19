# 🔍 Binary Search Pattern

## Overview

**Binary Search** is a divide-and-conquer algorithm that finds elements in a **sorted** array by repeatedly halving the search space. It's one of the most important patterns because it reduces O(n) searches to O(log n).

---

## 🧠 When to Use Binary Search

Use this pattern when:
- The input is **sorted** (or can be sorted)
- You need to find an element or a **boundary**
- The search space can be **divided** into two parts
- Keywords: "sorted", "find minimum/maximum", "search", "kth element"
- The answer has a **monotonic property** (if X works, all values > X also work, or vice versa)

---

## 🎯 Types of Binary Search

### 1. Standard Binary Search
Find exact element in sorted array.

```
Array: [1, 3, 5, 7, 9, 11]
Target: 7

Step 1: mid = 5, 5 < 7, search right
Step 2: mid = 9, 9 > 7, search left
Step 3: mid = 7, found!
```

### 2. Finding Boundaries
Find first/last occurrence or insertion point.

```
Array: [1, 2, 2, 2, 3, 4]
Find first 2: index 1
Find last 2: index 3
Find insert position for 2.5: index 4
```

### 3. Binary Search on Answer Space
Search for optimal value in a range.

```
Problem: Find minimum capacity to ship packages in D days
Answer space: [max(weights), sum(weights)]
Binary search: Can we ship with capacity mid in D days?
```

---

## 📐 General Templates

### Template 1: Standard Binary Search
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}
```

### Template 2: Find Left Boundary (First Occurrence)
```cpp
int findLeftBoundary(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // Check if found
    if (left < nums.size() && nums[left] == target) {
        return left;
    }
    return -1;
}
```

### Template 3: Find Right Boundary (Last Occurrence)
```cpp
int findRightBoundary(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Check if found
    if (right >= 0 && nums[right] == target) {
        return right;
    }
    return -1;
}
```

### Template 4: Binary Search on Answer (Minimize)
```cpp
int binarySearchAnswer(int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (isValid(mid)) {  // Can achieve with mid
            high = mid;      // Try smaller
        } else {
            low = mid + 1;   // Need larger
        }
    }
    
    return low;  // Minimum valid answer
}
```

### Template 5: Binary Search on Answer (Maximize)
```cpp
int binarySearchAnswerMax(int low, int high) {
    while (low < high) {
        int mid = low + (high - low + 1) / 2;  // Round up!
        
        if (isValid(mid)) {  // Can achieve with mid
            low = mid;       // Try larger
        } else {
            high = mid - 1;  // Need smaller
        }
    }
    
    return low;  // Maximum valid answer
}
```

---

## 🔬 Understanding the Templates

### Why `left + (right - left) / 2`?
Prevents integer overflow in languages like Java/C++:
```
// Could overflow if left and right are large
mid = (left + right) / 2

// Safe calculation
mid = left + (right - left) / 2
```

### Why Round Up for Maximize?
```cpp
// If we use mid = (low + high) / 2 and isValid(mid) → low = mid
// With low=3, high=4: mid=3, if valid, low=3 → infinite loop!

// Solution: round up
mid = low + (high - low + 1) / 2;
// With low=3, high=4: mid=4, progresses correctly
```

### Loop Condition: `<=` vs `<`
- Use `<=` when searching for exact element
- Use `<` when searching for a condition/boundary

---

## 💡 Key Insights

### 1. Invariant Thinking
Define what `left` and `right` represent throughout the search:
- After loop ends with `left <= right`: `left` is insertion point
- With `left < right`: `left` points to the answer

### 2. Monotonicity is Key
Binary search works when the property you're checking is **monotonic**:
- If `f(x)` is true, then `f(x+1)` is also true (or vice versa)
- This creates a clear boundary between true/false regions

```
Index:    0  1  2  3  4  5  6  7
f(x):     F  F  F  T  T  T  T  T
          -------  -----------
          Search   Answer
          space    space
          
Binary search finds the boundary (index 3)
```

### 3. Common Variations

| Variant | Condition Update | Return |
|---------|-----------------|--------|
| Find exact | `nums[mid] == target` | mid |
| First >= target | `nums[mid] >= target → right = mid` | left |
| Last <= target | `nums[mid] <= target → left = mid` | left (rounded up) |
| First > target | `nums[mid] > target → right = mid` | left |

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Binary Search | O(log n) | O(1) |
| Search in Rotated | O(log n) | O(1) |
| Search Matrix | O(log(m×n)) | O(1) |
| Search Answer Space | O(log(range) × verify) | O(1) |

---

## 🎓 Example Walkthrough: Search in Rotated Sorted Array

**Problem:** Search target in a rotated sorted array (no duplicates).

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Original: [0,1,2,4,5,6,7], rotated at index 4
```

**Key Insight:** One half is always sorted!

```
[4, 5, 6, 7, 0, 1, 2]
       mid
Left half [4,5,6] is sorted
Right half [7,0,1,2] is not sorted

Check if target is in sorted half, otherwise search other half.
```

**Solution:**
```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

---

## 🔗 Related Patterns

- **Two Pointers:** Binary search is a specific two-pointer technique
- **Divide and Conquer:** Binary search exemplifies this strategy
- **Sorting:** Often a preprocessing step before binary search

---

## 🚨 Common Mistakes

1. **Off-by-one errors:** Know when to use `<=` vs `<`
2. **Infinite loops:** Ensure search space shrinks each iteration
3. **Overflow:** Use `left + (right - left) / 2`
4. **Wrong half:** Carefully determine which half to search
5. **Unsorted input:** Binary search requires sorted data!

---

*Next: [See Practice Questions →](./questions.md)*
