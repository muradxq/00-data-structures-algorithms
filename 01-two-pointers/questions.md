# 📝 Two Pointers - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Pattern Type | Status |
|---|---------|------------|--------------|--------|
| 1 | Two Sum II | Easy | Opposite | ⬜ |
| 2 | Valid Palindrome | Easy | Opposite | ⬜ |
| 3 | Remove Duplicates from Sorted Array | Easy | Same Direction | ⬜ |
| 4 | Move Zeroes | Easy | Same Direction | ⬜ |
| 5 | Squares of a Sorted Array | Easy | Opposite | ⬜ |
| 6 | 3Sum | Medium | Opposite + Loop | ⬜ |
| 7 | 3Sum Closest | Medium | Opposite + Loop | ⬜ |
| 8 | Container With Most Water | Medium | Opposite | ⬜ |
| 9 | Sort Colors | Medium | Three Pointers | ⬜ |
| 10 | 4Sum | Medium | Opposite + 2 Loops | ⬜ |
| 11 | Remove Nth Node From End | Medium | Two Arrays | ⬜ |
| 12 | Trapping Rain Water | Hard | Opposite | ⬜ |

---

## 🟢 Easy Problems

### 1. Two Sum II - Input Array Is Sorted
**LeetCode #167**

Given a 1-indexed sorted array, find two numbers that add up to target.

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
```

**Approach:**
- Use opposite direction pointers
- If sum < target, move left pointer
- If sum > target, move right pointer

**Solution:**
```python
def twoSum(numbers, target):
    left, right = 0, len(numbers) - 1
    
    while left < right:
        curr_sum = numbers[left] + numbers[right]
        if curr_sum == target:
            return [left + 1, right + 1]
        elif curr_sum < target:
            left += 1
        else:
            right -= 1
    return []
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Valid Palindrome
**LeetCode #125**

Check if a string is a palindrome, considering only alphanumeric characters.

```
Input: "A man, a plan, a canal: Panama"
Output: true
```

**Approach:**
- Two pointers from ends
- Skip non-alphanumeric characters
- Compare lowercase versions

**Solution:**
```python
def isPalindrome(s):
    left, right = 0, len(s) - 1
    
    while left < right:
        # Skip non-alphanumeric
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True
```
**Complexity:** Time O(n), Space O(1)

---

### 3. Remove Duplicates from Sorted Array
**LeetCode #26**

Remove duplicates in-place from sorted array. Return new length.

```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
```

**Approach:**
- Slow pointer tracks position of unique elements
- Fast pointer scans array
- When fast finds new element, copy to slow position

**Solution:**
```python
def removeDuplicates(nums):
    if not nums:
        return 0
    
    slow = 0
    for fast in range(1, len(nums)):
        if nums[fast] != nums[slow]:
            slow += 1
            nums[slow] = nums[fast]
    
    return slow + 1
```
**Complexity:** Time O(n), Space O(1)

---

### 4. Move Zeroes
**LeetCode #283**

Move all zeroes to the end while maintaining relative order of non-zero elements.

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Approach:**
- Slow pointer marks position for next non-zero
- Fast pointer finds non-zero elements
- Swap when fast finds non-zero

**Solution:**
```python
def moveZeroes(nums):
    slow = 0
    for fast in range(len(nums)):
        if nums[fast] != 0:
            nums[slow], nums[fast] = nums[fast], nums[slow]
            slow += 1
```
**Complexity:** Time O(n), Space O(1)

---

### 5. Squares of a Sorted Array
**LeetCode #977**

Given sorted array (may have negatives), return sorted array of squares.

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```

**Approach:**
- Two pointers at ends (largest squares are at ends due to negatives)
- Compare absolute values
- Fill result array from end to start

**Solution:**
```python
def sortedSquares(nums):
    n = len(nums)
    result = [0] * n
    left, right = 0, n - 1
    pos = n - 1
    
    while left <= right:
        left_sq = nums[left] ** 2
        right_sq = nums[right] ** 2
        
        if left_sq > right_sq:
            result[pos] = left_sq
            left += 1
        else:
            result[pos] = right_sq
            right -= 1
        pos -= 1
    
    return result
```
**Complexity:** Time O(n), Space O(n)

---

## 🟡 Medium Problems

### 6. 3Sum
**LeetCode #15**

Find all unique triplets that sum to zero.

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

**Approach:**
- Sort array first
- Fix one element, use two pointers for remaining two
- Skip duplicates to avoid duplicate triplets

**Solution:**
```python
def threeSum(nums):
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        # Skip duplicates for first element
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                # Skip duplicates
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    
    return result
```
**Complexity:** Time O(n²), Space O(1) excluding output

---

### 7. 3Sum Closest
**LeetCode #16**

Find triplet with sum closest to target.

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2 (because -1 + 2 + 1 = 2)
```

**Solution:**
```python
def threeSumClosest(nums, target):
    nums.sort()
    closest = float('inf')
    
    for i in range(len(nums) - 2):
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            
            if abs(total - target) < abs(closest - target):
                closest = total
            
            if total < target:
                left += 1
            elif total > target:
                right -= 1
            else:
                return target
    
    return closest
```
**Complexity:** Time O(n²), Space O(1)

---

### 8. Container With Most Water
**LeetCode #11**

Find two lines that together with x-axis forms a container with most water.

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

**Approach:**
- Start with widest container (pointers at ends)
- Move the shorter line inward (only way to potentially find larger area)

**Solution:**
```python
def maxArea(height):
    left, right = 0, len(height) - 1
    max_area = 0
    
    while left < right:
        width = right - left
        h = min(height[left], height[right])
        max_area = max(max_area, width * h)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_area
```
**Complexity:** Time O(n), Space O(1)

---

### 9. Sort Colors (Dutch National Flag)
**LeetCode #75**

Sort array with only 0, 1, 2 in-place (one-pass).

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Approach:**
- Three pointers: low (0s), mid (current), high (2s)
- 0 goes to low region, 2 goes to high region

**Solution:**
```python
def sortColors(nums):
    low, mid, high = 0, 0, len(nums) - 1
    
    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1
            # Don't increment mid, need to check swapped value
```
**Complexity:** Time O(n), Space O(1)

---

### 10. 4Sum
**LeetCode #18**

Find all unique quadruplets that sum to target.

**Solution:**
```python
def fourSum(nums, target):
    nums.sort()
    result = []
    n = len(nums)
    
    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        for j in range(i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue
            
            left, right = j + 1, n - 1
            
            while left < right:
                total = nums[i] + nums[j] + nums[left] + nums[right]
                
                if total == target:
                    result.append([nums[i], nums[j], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif total < target:
                    left += 1
                else:
                    right -= 1
    
    return result
```
**Complexity:** Time O(n³), Space O(1)

---

## 🔴 Hard Problems

### 11. Trapping Rain Water
**LeetCode #42**

Calculate how much water can be trapped after rain.

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

**Approach:**
- Water at position depends on min(max_left, max_right) - height
- Use two pointers to track max heights from both sides

**Solution:**
```python
def trap(height):
    if not height:
        return 0
    
    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]
    water = 0
    
    while left < right:
        if left_max < right_max:
            left += 1
            left_max = max(left_max, height[left])
            water += left_max - height[left]
        else:
            right -= 1
            right_max = max(right_max, height[right])
            water += right_max - height[right]
    
    return water
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Two Pointers

1. **Always ask:** Is the array sorted? If not, would sorting help?
2. **Visualize:** Draw the array and pointer positions
3. **Track invariants:** What does each pointer represent?
4. **Handle edge cases:** Empty array, single element, all same elements

---

*[← Back to Pattern](./README.md) | [Next Pattern: Sliding Window →](../02-sliding-window/README.md)*
