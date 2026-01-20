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

**Approach:**
- Compare middle element with target
- Narrow search space by half each iteration

**Solution:**
```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
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

**Approach:**
- Standard binary search, return left pointer if not found

**Solution:**
```cpp
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;  // Insert position
}
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

**Approach:**
- Binary search for leftmost bad version
- Use `left < right` template

**Solution:**
```cpp
int firstBadVersion(int n) {
    int left = 1, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (isBadVersion(mid)) {
            right = mid;      // Could be first bad
        } else {
            left = mid + 1;   // First bad is after mid
        }
    }
    
    return left;
}
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

**Approach:**
- Binary search for largest integer whose square ≤ x

**Solution:**
```cpp
int mySqrt(int x) {
    if (x < 2) return x;
    
    int left = 1, right = x / 2;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;
        
        if (square == x) {
            return mid;
        } else if (square < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return right;  // Largest integer where square <= x
}
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

**Approach:**
- One half is always sorted
- Check which half is sorted and if target is in that range

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
**Complexity:** Time O(log n), Space O(1)

---

### 6. Find First and Last Position of Element in Sorted Array
**LeetCode #34**

Find starting and ending position of target.

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Approach:**
- Two binary searches: one for leftmost, one for rightmost

**Solution:**
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    auto findLeft = [&]() {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    
    auto findRight = [&]() {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    };
    
    int leftIdx = findLeft();
    int rightIdx = findRight();
    
    if (leftIdx <= rightIdx && leftIdx < nums.size() && nums[leftIdx] == target) {
        return {leftIdx, rightIdx};
    }
    return {-1, -1};
}
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

**Approach:**
- Move toward the higher neighbor
- A peak must exist (boundary conditions guarantee this)

**Solution:**
```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;   // Peak is on the right
        } else {
            right = mid;      // Peak is on the left (or mid)
        }
    }
    
    return left;
}
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

**Approach:**
- Treat as 1D sorted array, convert index

**Solution:**
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n, col = mid % n;
        
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}
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

**Approach:**
- Compare mid with right to determine which half contains minimum

**Solution:**
```cpp
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;   // Min is in right half
        } else {
            right = mid;      // Min is in left half (or mid)
        }
    }
    
    return nums[left];
}
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

**Approach:**
- Binary search on answer space [1, max(piles)]
- For each speed, check if all piles can be finished in h hours

**Solution:**
```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    auto canFinish = [&](int speed) {
        long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;  // Ceiling division
        }
        return hours <= h;
    };
    
    int left = 1, right = *max_element(piles.begin(), piles.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canFinish(mid)) {
            right = mid;      // Try smaller speed
        } else {
            left = mid + 1;   // Need faster speed
        }
    }
    
    return left;
}
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

**Approach:**
- Binary search on capacity [max(weights), sum(weights)]
- Check if given capacity can ship in required days

**Solution:**
```cpp
int shipWithinDays(vector<int>& weights, int days) {
    auto canShip = [&](int capacity) {
        int dayCount = 1;
        int currentWeight = 0;
        
        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                dayCount++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }
        
        return dayCount <= days;
    };
    
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canShip(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
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

**Approach:**
- Binary search for correct partition point
- Partition both arrays so left halves have all smaller elements

**Solution:**
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is shorter
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }
    
    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;
    
    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }
    
    return 0.0;
}
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

**Approach:**
- Binary search on answer space [max(nums), sum(nums)]
- Check if we can split into k or fewer subarrays with given max sum

**Solution:**
```cpp
int splitArray(vector<int>& nums, int k) {
    auto canSplit = [&](int maxSum) {
        int splits = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                splits++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        
        return splits <= k;
    };
    
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canSplit(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
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
