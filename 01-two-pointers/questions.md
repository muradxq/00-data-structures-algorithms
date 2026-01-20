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
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int curr_sum = numbers[left] + numbers[right];
        if (curr_sum == target) {
            return {left + 1, right + 1};
        } else if (curr_sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}
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
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
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
```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    
    return slow + 1;
}
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
```cpp
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}
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
```cpp
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1;
    
    while (left <= right) {
        int left_sq = nums[left] * nums[left];
        int right_sq = nums[right] * nums[right];
        
        if (left_sq > right_sq) {
            result[pos] = left_sq;
            left++;
        } else {
            result[pos] = right_sq;
            right--;
        }
        pos--;
    }
    
    return result;
}
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
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        // Skip duplicates for first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            
            if (total == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (total < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}
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
```cpp
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            
            if (abs(total - target) < abs(closest - target)) {
                closest = total;
            }
            
            if (total < target) {
                left++;
            } else if (total > target) {
                right--;
            } else {
                return target;
            }
        }
    }
    
    return closest;
}
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
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        max_area = max(max_area, width * h);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}
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
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {  // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Don't increment mid, need to check swapped value
        }
    }
}
```
**Complexity:** Time O(n), Space O(1)

---

### 10. 4Sum
**LeetCode #18**

Find all unique quadruplets that sum to target.

**Solution:**
```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            int left = j + 1, right = n - 1;
            
            while (left < right) {
                long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (total == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (total < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n³), Space O(1)

---

### 11. Remove Nth Node From End of List
**LeetCode #19**

Remove the nth node from the end of a linked list.

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Approach:**
- Use two pointers: fast and slow
- Move fast pointer n steps ahead
- Then move both pointers until fast reaches end
- Slow will be at (n+1)th node from end
- Remove the next node

**Solution:**
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Remove nth node from end
    slow->next = slow->next->next;
    
    return dummy->next;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 🔴 Hard Problems

### 12. Trapping Rain Water
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
```cpp
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    
    int left = 0, right = height.size() - 1;
    int left_max = height[left], right_max = height[right];
    int water = 0;
    
    while (left < right) {
        if (left_max < right_max) {
            left++;
            left_max = max(left_max, height[left]);
            water += left_max - height[left];
        } else {
            right--;
            right_max = max(right_max, height[right]);
            water += right_max - height[right];
        }
    }
    
    return water;
}
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
