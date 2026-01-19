# 📝 Binary Search - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Binary Search | Easy | Standard | ⬜ |
| 2 | Search Insert Position | Easy | Boundary | ⬜ |
| 3 | First Bad Version | Easy | Boundary | ⬜ |
| 4 | Sqrt(x) | Easy | Answer Space | ⬜ |
| 5 | Search in Rotated Sorted Array | Medium | Modified | ⬜ |
| 6 | Find First and Last Position | Medium | Boundary | ⬜ |
| 7 | Find Peak Element | Medium | Modified | ⬜ |
| 8 | Search a 2D Matrix | Medium | Standard | ⬜ |
| 9 | Find Minimum in Rotated Sorted Array | Medium | Modified | ⬜ |
| 10 | Koko Eating Bananas | Medium | Answer Space | ⬜ |
| 11 | Capacity To Ship Packages | Medium | Answer Space | ⬜ |
| 12 | Median of Two Sorted Arrays | Hard | Advanced | ⬜ |
| 13 | Split Array Largest Sum | Hard | Answer Space | ⬜ |

---

## 🟢 Easy Problems

### 1. Binary Search
**LeetCode #704**

Standard binary search for target in sorted array.

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
```

**Solution:**
```python
def search(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1
```
**Complexity:** Time O(log n), Space O(1)

---

### 2. Search Insert Position
**LeetCode #35**

Find index where target should be inserted in sorted array.

```
Input: nums = [1,3,5,6], target = 5 → Output: 2
Input: nums = [1,3,5,6], target = 2 → Output: 1
```

**Solution:**
```python
def searchInsert(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return left  # Insert position
```
**Complexity:** Time O(log n), Space O(1)

---

### 3. First Bad Version
**LeetCode #278**

Find first bad version given `isBadVersion(n)` API.

```
Input: n = 5, bad = 4
Versions: [1, 2, 3, 4, 5]
          [G, G, G, B, B]
Output: 4
```

**Solution:**
```python
def firstBadVersion(n):
    left, right = 1, n
    
    while left < right:
        mid = left + (right - left) // 2
        
        if isBadVersion(mid):
            right = mid      # Could be first bad
        else:
            left = mid + 1   # First bad is after mid
    
    return left
```
**Complexity:** Time O(log n), Space O(1)

---

### 4. Sqrt(x)
**LeetCode #69**

Compute integer square root of x.

```
Input: x = 8
Output: 2 (sqrt(8) ≈ 2.83, truncate to 2)
```

**Solution:**
```python
def mySqrt(x):
    if x < 2:
        return x
    
    left, right = 1, x // 2
    
    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid
        
        if square == x:
            return mid
        elif square < x:
            left = mid + 1
        else:
            right = mid - 1
    
    return right  # Largest integer where square <= x
```
**Complexity:** Time O(log n), Space O(1)

---

## 🟡 Medium Problems

### 5. Search in Rotated Sorted Array
**LeetCode #33**

Search in array that was sorted then rotated.

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Key:** One half is always sorted.

**Solution:**
```python
def search(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        
        # Left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        # Right half is sorted
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1
```
**Complexity:** Time O(log n), Space O(1)

---

### 6. Find First and Last Position of Element in Sorted Array
**LeetCode #34**

Find starting and ending position of target.

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Solution:**
```python
def searchRange(nums, target):
    def find_left():
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
        return left
    
    def find_right():
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return right
    
    left_idx = find_left()
    right_idx = find_right()
    
    if left_idx <= right_idx and left_idx < len(nums) and nums[left_idx] == target:
        return [left_idx, right_idx]
    return [-1, -1]
```
**Complexity:** Time O(log n), Space O(1)

---

### 7. Find Peak Element
**LeetCode #162**

Find any peak element (greater than neighbors).

```
Input: nums = [1,2,3,1]
Output: 2 (index of peak element 3)
```

**Key:** Move toward the higher neighbor.

**Solution:**
```python
def findPeakElement(nums):
    left, right = 0, len(nums) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] < nums[mid + 1]:
            left = mid + 1   # Peak is on the right
        else:
            right = mid      # Peak is on the left (or mid)
    
    return left
```
**Complexity:** Time O(log n), Space O(1)

---

### 8. Search a 2D Matrix
**LeetCode #74**

Search in row-wise and column-wise sorted matrix.

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Key:** Treat as 1D sorted array.

**Solution:**
```python
def searchMatrix(matrix, target):
    if not matrix:
        return False
    
    m, n = len(matrix), len(matrix[0])
    left, right = 0, m * n - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        # Convert 1D index to 2D
        row, col = mid // n, mid % n
        
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return False
```
**Complexity:** Time O(log(m×n)), Space O(1)

---

### 9. Find Minimum in Rotated Sorted Array
**LeetCode #153**

Find minimum element in rotated sorted array.

```
Input: nums = [3,4,5,1,2]
Output: 1
```

**Solution:**
```python
def findMin(nums):
    left, right = 0, len(nums) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] > nums[right]:
            left = mid + 1   # Min is in right half
        else:
            right = mid      # Min is in left half (or mid)
    
    return nums[left]
```
**Complexity:** Time O(log n), Space O(1)

---

### 10. Koko Eating Bananas
**LeetCode #875**

Find minimum eating speed to finish all bananas in h hours.

```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

**Approach:** Binary search on answer space [1, max(piles)].

**Solution:**
```python
def minEatingSpeed(piles, h):
    def can_finish(speed):
        hours = 0
        for pile in piles:
            hours += (pile + speed - 1) // speed  # Ceiling division
        return hours <= h
    
    left, right = 1, max(piles)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if can_finish(mid):
            right = mid      # Try smaller speed
        else:
            left = mid + 1   # Need faster speed
    
    return left
```
**Complexity:** Time O(n log m), Space O(1)

---

### 11. Capacity To Ship Packages Within D Days
**LeetCode #1011**

Find minimum ship capacity to ship all packages in days days.

```
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
```

**Solution:**
```python
def shipWithinDays(weights, days):
    def can_ship(capacity):
        day_count = 1
        current_weight = 0
        
        for weight in weights:
            if current_weight + weight > capacity:
                day_count += 1
                current_weight = 0
            current_weight += weight
        
        return day_count <= days
    
    left = max(weights)      # Must fit largest package
    right = sum(weights)     # Ship everything in one day
    
    while left < right:
        mid = left + (right - left) // 2
        
        if can_ship(mid):
            right = mid
        else:
            left = mid + 1
    
    return left
```
**Complexity:** Time O(n log(sum)), Space O(1)

---

## 🔴 Hard Problems

### 12. Median of Two Sorted Arrays
**LeetCode #4**

Find median of two sorted arrays in O(log(m+n)).

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
```

**Key:** Binary search for correct partition.

**Solution:**
```python
def findMedianSortedArrays(nums1, nums2):
    # Ensure nums1 is shorter
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
    
    m, n = len(nums1), len(nums2)
    left, right = 0, m
    
    while left <= right:
        partition1 = (left + right) // 2
        partition2 = (m + n + 1) // 2 - partition1
        
        maxLeft1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
        minRight1 = float('inf') if partition1 == m else nums1[partition1]
        
        maxLeft2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
        minRight2 = float('inf') if partition2 == n else nums2[partition2]
        
        if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
            if (m + n) % 2 == 0:
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
            else:
                return max(maxLeft1, maxLeft2)
        elif maxLeft1 > minRight2:
            right = partition1 - 1
        else:
            left = partition1 + 1
    
    return 0.0
```
**Complexity:** Time O(log(min(m,n))), Space O(1)

---

### 13. Split Array Largest Sum
**LeetCode #410**

Split array into k subarrays to minimize largest sum.

```
Input: nums = [7,2,5,10,8], k = 2
Output: 18 (Split: [7,2,5] and [10,8])
```

**Solution:**
```python
def splitArray(nums, k):
    def can_split(max_sum):
        splits = 1
        current_sum = 0
        
        for num in nums:
            if current_sum + num > max_sum:
                splits += 1
                current_sum = num
            else:
                current_sum += num
        
        return splits <= k
    
    left = max(nums)
    right = sum(nums)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if can_split(mid):
            right = mid
        else:
            left = mid + 1
    
    return left
```
**Complexity:** Time O(n log(sum)), Space O(1)

---

## 📚 Study Tips for Binary Search

1. **Know your template:** Different problems need different templates
2. **Define invariants:** What do left and right represent?
3. **Check monotonicity:** Binary search needs a monotonic property
4. **Handle boundaries:** What's your search space?
5. **Test edge cases:** Empty array, single element, target not found

---

*[← Back to Pattern](./README.md) | [Next Pattern: Merge Intervals →](../05-merge-intervals/README.md)*
