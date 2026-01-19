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

**Solution:**
```python
def hasCycle(head):
    if not head or not head.next:
        return False
    
    slow = fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False
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

**Solution:**
```python
def middleNode(head):
    slow = fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow
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

**Solution:**
```python
def isHappy(n):
    def get_next(num):
        total = 0
        while num > 0:
            digit = num % 10
            total += digit * digit
            num //= 10
        return total
    
    slow = n
    fast = get_next(n)
    
    while fast != 1 and slow != fast:
        slow = get_next(slow)
        fast = get_next(get_next(fast))
    
    return fast == 1
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
```python
def detectCycle(head):
    if not head or not head.next:
        return None
    
    slow = fast = head
    
    # Phase 1: Find meeting point
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            # Phase 2: Find cycle start
            slow = head
            while slow != fast:
                slow = slow.next
                fast = fast.next
            return slow
    
    return None
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
```python
def isPalindrome(head):
    if not head or not head.next:
        return True
    
    # Find middle
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    # Reverse second half
    prev = None
    while slow:
        next_node = slow.next
        slow.next = prev
        prev = slow
        slow = next_node
    
    # Compare halves
    first, second = head, prev
    while second:  # Second half is shorter or equal
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    
    return True
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
```python
def reorderList(head):
    if not head or not head.next:
        return
    
    # Find middle
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    # Reverse second half
    prev = None
    curr = slow
    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    
    # Merge two halves
    first, second = head, prev
    while second.next:
        tmp1, tmp2 = first.next, second.next
        first.next = second
        second.next = tmp1
        first, second = tmp1, tmp2
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

**Key Insight:**
- Treat array as linked list where value points to next index
- nums[i] = j means node i points to node j
- Duplicate creates a cycle!

**Solution:**
```python
def findDuplicate(nums):
    # Phase 1: Find intersection point
    slow = fast = nums[0]
    
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    
    # Phase 2: Find cycle entrance (duplicate)
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    
    return slow
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

**Solution:**
```python
def circularArrayLoop(nums):
    n = len(nums)
    
    def get_next(i):
        return (i + nums[i]) % n
    
    for i in range(n):
        if nums[i] == 0:
            continue
        
        slow = fast = i
        # Check direction consistency
        while nums[slow] * nums[get_next(slow)] > 0 and \
              nums[slow] * nums[get_next(get_next(slow))] > 0:
            slow = get_next(slow)
            fast = get_next(get_next(fast))
            
            if slow == fast:
                # Check cycle length > 1
                if slow == get_next(slow):
                    break
                return True
        
        # Mark visited nodes as 0 (no valid cycle from here)
        slow = i
        val = nums[i]
        while nums[slow] * val > 0:
            next_idx = get_next(slow)
            nums[slow] = 0
            slow = next_idx
    
    return False
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Fast & Slow Pointers

1. **Draw it out:** Visualize pointer movements step by step
2. **Know the math:** Understand why cycle detection and cycle start work
3. **Check boundaries:** Always verify `fast` and `fast.next` exist
4. **Combine patterns:** Often used with reversal for palindrome checks

---

*[← Back to Pattern](./README.md) | [Next Pattern: Binary Search →](../04-binary-search/README.md)*
