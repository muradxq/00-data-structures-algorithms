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

**Approach:**
- Capture all upward price movements
- Add profit whenever price increases

**Solution:**
```cpp
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
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

**Approach:**
- Track maximum reachable index
- If current index > max reachable, can't proceed

**Solution:**
```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
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

**Approach:**
- BFS-like: track current range end and farthest reachable
- Increment jumps when reaching current range end

**Solution:**
```cpp
int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    
    return jumps;
}
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

**Approach:**
- If total gas >= total cost, solution exists
- Start from station after where tank goes negative

**Solution:**
```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }
    if (totalGas < totalCost) return -1;
    
    int tank = 0;
    int start = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    
    return start;
}
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

**Approach:**
- Find last occurrence of each character
- Extend partition end to include all occurrences
- Split when current index reaches partition end

**Solution:**
```cpp
vector<int> partitionLabels(string s) {
    vector<int> last(26);
    for (int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;
    }
    
    vector<int> result;
    int start = 0, end = 0;
    
    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(26)

---

## 🔴 Hard Problems

### 6. Candy
**LeetCode #135**

Distribute minimum candies with constraints.
- Each child gets at least 1 candy
- Higher rating child gets more than neighbors

```
Input: ratings = [1,0,2]
Output: 5 (candies: [2,1,2])
```

**Approach:**
- Two passes: left-to-right, then right-to-left
- Each pass ensures one neighbor constraint

**Solution:**
```cpp
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    
    // Left to right: handle increasing ratings
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Right to left: handle decreasing ratings
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    
    return accumulate(candies.begin(), candies.end(), 0);
}
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
