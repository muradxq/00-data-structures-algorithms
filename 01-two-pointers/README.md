# 👆👆 Two Pointers Pattern

## Overview

The **Two Pointers** technique uses two pointers to iterate through a data structure (usually an array or linked list) in a specific way to solve problems efficiently. Instead of using nested loops (O(n²)), two pointers often reduce complexity to O(n).

---

## 🧠 When to Use Two Pointers

Use this pattern when:
- The problem involves a **sorted array** or **linked list**
- You need to find **pairs** that satisfy a condition
- You need to **compare elements** from different positions
- You're looking for a **subarray** with certain properties
- The problem mentions finding "triplets", "pairs", or "subarrays"

---

## 🎯 Types of Two Pointer Approaches

### 1. Opposite Direction (Converging)
Pointers start at opposite ends and move toward each other.

```
Array: [1, 2, 3, 4, 5, 6, 7]
        ↑                 ↑
       left             right
       
Move: left++ or right-- based on condition
```

**Use cases:**
- Two Sum (sorted array)
- Container With Most Water
- Valid Palindrome
- 3Sum, 4Sum problems

### 2. Same Direction (Fast & Slow / Sliding)
Both pointers move in the same direction at different speeds.

```
Array: [1, 2, 2, 3, 3, 3, 4]
        ↑  ↑
       slow fast
       
Move: Both move forward, but at different rates
```

**Use cases:**
- Remove Duplicates from Sorted Array
- Remove Element
- Move Zeroes
- Linked List cycle detection

### 3. Two Arrays / Strings
One pointer for each data structure.

```
Array1: [1, 3, 5, 7]    Array2: [2, 4, 6, 8]
         ↑                       ↑
         i                       j
```

**Use cases:**
- Merge Sorted Arrays
- Intersection of Arrays
- Compare Strings

---

## 📐 General Template

### Opposite Direction Template
```cpp
vector<int> twoPointerOpposite(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        
        if (currentSum == target) {
            // Found answer
            return {left, right};
        } else if (currentSum < target) {
            left++;      // Need larger sum
        } else {
            right--;     // Need smaller sum
        }
    }
    
    return {};  // No solution
}
```

### Same Direction Template
```cpp
int twoPointerSameDirection(vector<int>& arr) {
    int slow = 0;
    
    for (int fast = 0; fast < arr.size(); fast++) {
        if (someCondition(arr[fast])) {
            arr[slow] = arr[fast];
            slow++;
        }
    }
    
    return slow;
}
```

---

## 🔍 Pattern Recognition

| Problem Statement Contains | Likely Pattern |
|---------------------------|----------------|
| "sorted array" + "find pair/sum" | Opposite Direction |
| "remove duplicates in-place" | Same Direction |
| "palindrome" | Opposite Direction |
| "merge two sorted" | Two Arrays |
| "triplet/quadruplet sum" | Opposite Direction + Loop |
| "move/partition elements" | Same Direction |

---

## 💡 Key Insights

1. **Sorting first** often enables two pointers (O(n log n) + O(n) is still better than O(n²))

2. **Why it works with sorted arrays:**
   - Moving left pointer increases the sum
   - Moving right pointer decreases the sum
   - This creates a "binary search" like behavior

3. **Space Optimization:** Two pointers often allow O(1) space solutions for problems that might otherwise need O(n) space

4. **Handling duplicates:** When the array has duplicates and you need unique solutions, skip duplicates:
   ```cpp
   while (left < right && arr[left] == arr[left + 1]) {
       left++;
   }
   ```

---

## 📊 Complexity Analysis

| Approach | Time | Space |
|----------|------|-------|
| Opposite Direction | O(n) | O(1) |
| Same Direction | O(n) | O(1) |
| With Sorting | O(n log n) | O(1) to O(n) |

---

## 🎓 Example Walkthrough: Two Sum II (Sorted Array)

**Problem:** Given a sorted array, find two numbers that add up to target.

```
Input: numbers = [2, 7, 11, 15], target = 9
```

**Step-by-step:**
```
Step 1: left=0, right=3
        sum = 2 + 15 = 17 > 9
        Move right pointer left
        
Step 2: left=0, right=2
        sum = 2 + 11 = 13 > 9
        Move right pointer left
        
Step 3: left=0, right=1
        sum = 2 + 7 = 9 == target ✓
        Return [1, 2] (1-indexed)
```

**Code:**
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int currentSum = numbers[left] + numbers[right];
        
        if (currentSum == target) {
            return {left + 1, right + 1};  // 1-indexed
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}
```

---

## 🔗 Related Patterns

- **Sliding Window:** A specialized form of two pointers
- **Fast & Slow Pointers:** Same direction with specific speed rules
- **Binary Search:** Similar divide-and-conquer intuition

---

*Next: [See Practice Questions →](./questions.md)*
