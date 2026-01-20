# 📝 Fast & Slow Pointers - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Variant | Status |
|---|---------|------------|---------|--------|
| 1 | Linked List Cycle | Easy | Cycle Detection | ⬜ |
| 2 | Middle of the Linked List | Easy | Find Middle | ⬜ |
| 3 | Happy Number | Easy | Cycle in Numbers | ⬜ |
| 4 | Linked List Cycle II | Medium | Find Cycle Start | ⬜ |
| 5 | Palindrome Linked List | Medium | Middle + Reverse | ⬜ |
| 6 | Reorder List | Medium | Middle + Reverse | ⬜ |
| 7 | Find the Duplicate Number | Medium | Cycle Detection | ⬜ |
| 8 | Circular Array Loop | Medium | Cycle Detection | ⬜ |

---

## 🟢 Easy Problems

### 1. Linked List Cycle
**LeetCode #141**

Determine if linked list has a cycle.

```
Input: 3 → 2 → 0 → -4 → (back to 2)
Output: true
```

**Approach:**
- Fast pointer moves 2 steps, slow moves 1 step
- If they meet, there's a cycle

**Solution:**
```cpp
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) return true;
    }
    
    return false;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Middle of the Linked List
**LeetCode #876**

Return the middle node (second middle if two middles).

```
Input: 1 → 2 → 3 → 4 → 5
Output: Node 3

Input: 1 → 2 → 3 → 4 → 5 → 6
Output: Node 4 (second middle)
```

**Approach:**
- When fast reaches end, slow is at middle

**Solution:**
```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 3. Happy Number
**LeetCode #202**

Check if a number is happy (sum of squares of digits eventually reaches 1).

```
Input: n = 19
Output: true
(19 → 82 → 68 → 100 → 1)
```

**Approach:**
- Treat digit sum sequence as linked list
- Use cycle detection - either reaches 1 or cycles

**Solution:**
```cpp
int getNext(int n) {
    int total = 0;
    while (n > 0) {
        int digit = n % 10;
        total += digit * digit;
        n /= 10;
    }
    return total;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    return fast == 1;
}
```
**Complexity:** Time O(log n), Space O(1)

---

## 🟡 Medium Problems

### 4. Linked List Cycle II
**LeetCode #142**

Return the node where cycle begins (null if no cycle).

```
Input: 3 → 2 → 0 → -4 → (back to 2)
Output: Node 2
```

**Approach:**
1. Detect cycle using fast/slow
2. Reset slow to head, keep fast at meeting point
3. Move both at same speed - they'll meet at cycle start

**Solution:**
```cpp
ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Phase 1: Find meeting point
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Phase 2: Find cycle start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return nullptr;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 5. Palindrome Linked List
**LeetCode #234**

Check if linked list is a palindrome.

```
Input: 1 → 2 → 2 → 1
Output: true
```

**Approach:**
1. Find middle using fast/slow
2. Reverse second half
3. Compare first half with reversed second half

**Solution:**
```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    // Compare halves
    ListNode* first = head;
    ListNode* second = prev;
    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }
    
    return true;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 6. Reorder List
**LeetCode #143**

Reorder list: L0 → L1 → ... → Ln-1 → Ln 
becomes: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

```
Input: 1 → 2 → 3 → 4
Output: 1 → 4 → 2 → 3
```

**Approach:**
1. Find middle
2. Reverse second half
3. Merge two halves alternately

**Solution:**
```cpp
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Merge two halves
    ListNode* first = head;
    ListNode* second = prev;
    while (second->next) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
```
**Complexity:** Time O(n), Space O(1)

---

### 7. Find the Duplicate Number
**LeetCode #287**

Array of n+1 integers where each integer is in [1, n]. Find the duplicate.

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Approach:**
- Treat array as linked list where value points to next index
- nums[i] = j means node i points to node j
- Duplicate creates a cycle!

**Solution:**
```cpp
int findDuplicate(vector<int>& nums) {
    // Phase 1: Find intersection point
    int slow = nums[0];
    int fast = nums[0];
    
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Phase 2: Find cycle entrance (duplicate)
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

### 8. Circular Array Loop
**LeetCode #457**

Determine if array has a cycle of length > 1 in same direction.

```
Input: nums = [2,-1,1,2,2]
Output: true (indices 0 → 2 → 3 → 0)
```

**Approach:**
- For each starting index, use fast/slow pointers
- Check direction consistency throughout cycle

**Solution:**
```cpp
bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    
    auto getNext = [&](int i) {
        return ((i + nums[i]) % n + n) % n;
    };
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;
        
        int slow = i, fast = i;
        
        // Check direction consistency
        while (nums[slow] * nums[getNext(slow)] > 0 &&
               nums[slow] * nums[getNext(getNext(slow))] > 0) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            
            if (slow == fast) {
                // Check cycle length > 1
                if (slow == getNext(slow)) break;
                return true;
            }
        }
        
        // Mark visited nodes as 0
        int j = i;
        int val = nums[i];
        while (nums[j] * val > 0) {
            int next = getNext(j);
            nums[j] = 0;
            j = next;
        }
    }
    
    return false;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Fast & Slow Pointers

1. **Draw it out:** Visualize pointer movements step by step
2. **Know the math:** Understand why cycle detection and cycle start work
3. **Check boundaries:** Always verify `fast` and `fast->next` exist
4. **Combine patterns:** Often used with reversal for palindrome checks

---

*[← Back to Pattern](./README.md) | [Next Pattern: Binary Search →](../04-binary-search/README.md)*
