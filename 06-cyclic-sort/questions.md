# 📝 Cyclic Sort - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Missing Number | Easy | Find Missing | ⬜ |
| 2 | Find All Numbers Disappeared in Array | Easy | Find All Missing | ⬜ |
| 3 | Set Mismatch | Easy | Missing + Duplicate | ⬜ |
| 4 | Find the Duplicate Number | Medium | Find Duplicate | ⬜ |
| 5 | Find All Duplicates in Array | Medium | Find All Duplicates | ⬜ |
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

**Approach:**
- Place each number at its correct index (nums[i] should be at index nums[i])
- After sorting, find where nums[i] != i

**Solution (Cyclic Sort):**
```cpp
int missingNumber(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    
    while (i < n) {
        int correctIdx = nums[i];
        if (nums[i] < n && nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != i) return i;
    }
    return n;
}
```

**Alternative (Math):**
```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(nums.begin(), nums.end(), 0);
    return expectedSum - actualSum;
}
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

**Approach:**
- Place each number at index (nums[i] - 1)
- Numbers at wrong positions indicate missing numbers

**Solution:**
```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctIdx = nums[i] - 1;
        if (nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    vector<int> missing;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            missing.push_back(i + 1);
        }
    }
    
    return missing;
}
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

**Approach:**
- Cyclic sort to place numbers at correct positions
- Find position where nums[i] != i+1 - that gives both duplicate and missing

**Solution:**
```cpp
vector<int> findErrorNums(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctIdx = nums[i] - 1;
        if (nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            return {nums[i], i + 1};  // {duplicate, missing}
        }
    }
    
    return {};
}
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

**Approach (Cyclic Sort):**
- Try to place each number at its correct index
- If the position is already occupied by the same number, we found the duplicate

```cpp
int findDuplicate(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] != i + 1) {
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                return nums[i];  // Found duplicate!
            }
        } else {
            i++;
        }
    }
    return -1;
}
```

**Alternative (Floyd's Cycle Detection - no array modification):**
```cpp
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    
    // Find intersection
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Find cycle start
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
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

**Approach (Cyclic Sort):**
- Sort using cyclic sort
- Numbers at wrong positions are duplicates

```cpp
vector<int> findDuplicates(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctIdx = nums[i] - 1;
        if (nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    vector<int> duplicates;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            duplicates.push_back(nums[i]);
        }
    }
    
    return duplicates;
}
```

**Alternative (Marking Approach):**
```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] < 0) {
            result.push_back(abs(num));
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return result;
}
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

**Approach:**
- Answer must be in range [1, n+1]
- Place each positive number ≤ n at its correct index
- First position without correct number is the answer

**Solution:**
```cpp
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    
    while (i < n) {
        // Number should be at index nums[i] - 1
        int correctIdx = nums[i] - 1;
        
        // Only swap if:
        // 1. Number is in valid range [1, n]
        // 2. Number is not at correct position
        // 3. Correct position has different number
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    
    // Find first position where nums[i] != i + 1
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}
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
