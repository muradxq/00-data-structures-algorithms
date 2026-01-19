# 📝 Cyclic Sort - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Missing Number | Easy | Find Missing | ⬜ |
| 2 | Find All Numbers Disappeared in Array | Easy | Find All Missing | ⬜ |
| 3 | Find the Duplicate Number | Medium | Find Duplicate | ⬜ |
| 4 | Find All Duplicates in Array | Medium | Find All Duplicates | ⬜ |
| 5 | Set Mismatch | Easy | Missing + Duplicate | ⬜ |
| 6 | First Missing Positive | Hard | Find Missing | ⬜ |

---

## 🟢 Easy Problems

### 1. Missing Number
**LeetCode #268**

Find missing number in array of [0, n].

```
Input: nums = [3,0,1]
Output: 2
```

**Solution:**
```python
def missingNumber(nums):
    i = 0
    n = len(nums)
    
    while i < n:
        correct_idx = nums[i]
        if nums[i] < n and nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    
    for i in range(n):
        if nums[i] != i:
            return i
    return n
```

**Alternative (Math):**
```python
def missingNumber(nums):
    n = len(nums)
    expected_sum = n * (n + 1) // 2
    return expected_sum - sum(nums)
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Find All Numbers Disappeared in an Array
**LeetCode #448**

Find all missing numbers in range [1, n].

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Solution:**
```python
def findDisappearedNumbers(nums):
    i = 0
    while i < len(nums):
        correct_idx = nums[i] - 1
        if nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    
    missing = []
    for i in range(len(nums)):
        if nums[i] != i + 1:
            missing.append(i + 1)
    
    return missing
```
**Complexity:** Time O(n), Space O(1)

---

### 3. Set Mismatch
**LeetCode #645**

Find the duplicate and missing number.

```
Input: nums = [1,2,2,4]
Output: [2,3] (2 is duplicated, 3 is missing)
```

**Solution:**
```python
def findErrorNums(nums):
    i = 0
    while i < len(nums):
        correct_idx = nums[i] - 1
        if nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    
    for i in range(len(nums)):
        if nums[i] != i + 1:
            return [nums[i], i + 1]  # [duplicate, missing]
    
    return []
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 4. Find the Duplicate Number
**LeetCode #287**

Array of n+1 integers in [1, n]. Find the one duplicate.

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Cyclic Sort Approach:**
```python
def findDuplicate(nums):
    i = 0
    while i < len(nums):
        if nums[i] != i + 1:
            correct_idx = nums[i] - 1
            if nums[i] != nums[correct_idx]:
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
            else:
                return nums[i]  # Found duplicate!
        else:
            i += 1
    return -1
```

**Fast/Slow Pointer (no modification):**
```python
def findDuplicate(nums):
    slow = fast = nums[0]
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    return slow
```
**Complexity:** Time O(n), Space O(1)

---

### 5. Find All Duplicates in an Array
**LeetCode #442**

Find all elements appearing twice in array of [1, n].

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Solution:**
```python
def findDuplicates(nums):
    i = 0
    while i < len(nums):
        correct_idx = nums[i] - 1
        if nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    
    duplicates = []
    for i in range(len(nums)):
        if nums[i] != i + 1:
            duplicates.append(nums[i])
    
    return duplicates
```

**Alternative (Marking Approach):**
```python
def findDuplicates(nums):
    result = []
    for num in nums:
        idx = abs(num) - 1
        if nums[idx] < 0:
            result.append(abs(num))
        else:
            nums[idx] = -nums[idx]
    return result
```
**Complexity:** Time O(n), Space O(1)

---

## 🔴 Hard Problems

### 6. First Missing Positive
**LeetCode #41**

Find smallest missing positive integer.

```
Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [7,8,9,11,12]
Output: 1
```

**Key Insight:** Answer must be in range [1, n+1]. Place each positive number ≤ n at its correct index.

**Solution:**
```python
def firstMissingPositive(nums):
    n = len(nums)
    i = 0
    
    while i < n:
        # Number should be at index nums[i] - 1
        correct_idx = nums[i] - 1
        
        # Only swap if:
        # 1. Number is in valid range [1, n]
        # 2. Number is not at correct position
        # 3. Correct position has different number
        if 0 < nums[i] <= n and nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    
    # Find first position where nums[i] != i + 1
    for i in range(n):
        if nums[i] != i + 1:
            return i + 1
    
    return n + 1
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Cyclic Sort

1. **Recognize the pattern:** Numbers in range [1,n] or [0,n-1]
2. **Avoid infinite loops:** Check before swapping
3. **Handle edge cases:** Out of range numbers, duplicates
4. **Two-phase approach:** First sort, then scan for anomalies

---

*[← Back to Pattern](./README.md) | [Next Pattern: Tree BFS →](../07-tree-bfs/README.md)*
