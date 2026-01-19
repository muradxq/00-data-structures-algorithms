# 📝 Greedy - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Best Time to Buy and Sell Stock II | Medium | Trading | ⬜ |
| 2 | Jump Game | Medium | Reachability | ⬜ |
| 3 | Jump Game II | Medium | Min Jumps | ⬜ |
| 4 | Gas Station | Medium | Circular | ⬜ |
| 5 | Partition Labels | Medium | Intervals | ⬜ |
| 6 | Candy | Hard | Constraints | ⬜ |

---

## 🟡 Medium Problems

### 1. Best Time to Buy and Sell Stock II
**LeetCode #122**

Multiple transactions allowed. Maximum profit?

```
Input: prices = [7,1,5,3,6,4]
Output: 7 (buy@1, sell@5, buy@3, sell@6)
```

**Solution:**
```python
def maxProfit(prices):
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i-1]:
            profit += prices[i] - prices[i-1]
    return profit
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Jump Game
**LeetCode #55**

Can you reach the last index?

```
Input: nums = [2,3,1,1,4]
Output: true
```

**Solution:**
```python
def canJump(nums):
    max_reach = 0
    for i, jump in enumerate(nums):
        if i > max_reach:
            return False
        max_reach = max(max_reach, i + jump)
    return True
```
**Complexity:** Time O(n), Space O(1)

---

### 3. Jump Game II
**LeetCode #45**

Minimum jumps to reach end.

```
Input: nums = [2,3,1,1,4]
Output: 2 (0→1→4)
```

**Solution:**
```python
def jump(nums):
    jumps = 0
    current_end = 0
    farthest = 0
    
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])
        
        if i == current_end:
            jumps += 1
            current_end = farthest
    
    return jumps
```
**Complexity:** Time O(n), Space O(1)

---

### 4. Gas Station
**LeetCode #134**

Find starting gas station to complete circuit.

```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
```

**Solution:**
```python
def canCompleteCircuit(gas, cost):
    if sum(gas) < sum(cost):
        return -1
    
    tank = 0
    start = 0
    
    for i in range(len(gas)):
        tank += gas[i] - cost[i]
        if tank < 0:
            tank = 0
            start = i + 1
    
    return start
```
**Complexity:** Time O(n), Space O(1)

---

### 5. Partition Labels
**LeetCode #763**

Partition string so each letter appears in at most one part.

```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
```

**Solution:**
```python
def partitionLabels(s):
    last = {c: i for i, c in enumerate(s)}
    result = []
    start = end = 0
    
    for i, c in enumerate(s):
        end = max(end, last[c])
        if i == end:
            result.append(end - start + 1)
            start = i + 1
    
    return result
```
**Complexity:** Time O(n), Space O(26)

---

## 🔴 Hard Problems

### 6. Candy
**LeetCode #135**

Distribute minimum candies with constraints.

```
Input: ratings = [1,0,2]
Output: 5 (candies: [2,1,2])
```

**Solution:**
```python
def candy(ratings):
    n = len(ratings)
    candies = [1] * n
    
    # Left to right
    for i in range(1, n):
        if ratings[i] > ratings[i-1]:
            candies[i] = candies[i-1] + 1
    
    # Right to left
    for i in range(n-2, -1, -1):
        if ratings[i] > ratings[i+1]:
            candies[i] = max(candies[i], candies[i+1] + 1)
    
    return sum(candies)
```
**Complexity:** Time O(n), Space O(n)

---

## 📚 Study Tips for Greedy

1. **Prove it works:** Exchange argument or "greedy stays ahead"
2. **Sort first:** Many greedy problems require sorting
3. **Think local:** What's the best immediate choice?
4. **Watch for counterexamples:** Test edge cases

---

*[← Back to Pattern](./README.md) | [Next Pattern: Design →](../20-design/README.md)*
