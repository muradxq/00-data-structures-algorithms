# 📝 Merge Intervals - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Meeting Rooms | Easy | Overlap Check | ⬜ |
| 2 | Merge Intervals | Medium | Merge | ⬜ |
| 3 | Insert Interval | Medium | Insert | ⬜ |
| 4 | Non-overlapping Intervals | Medium | Remove | ⬜ |
| 5 | Meeting Rooms II | Medium | Count Rooms | ⬜ |
| 6 | Interval List Intersections | Medium | Intersection | ⬜ |
| 7 | Minimum Number of Arrows | Medium | Greedy | ⬜ |
| 8 | Employee Free Time | Hard | Merge | ⬜ |

---

## 🟢 Easy Problems

### 1. Meeting Rooms
**LeetCode #252** (Premium)

Determine if a person could attend all meetings.

```
Input: [[0,30],[5,10],[15,20]]
Output: false (meetings overlap)

Input: [[7,10],[2,4]]
Output: true
```

**Approach:**
- Sort by start time
- Check if any meeting starts before previous ends

**Solution:**
```cpp
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i-1][1]) {
            return false;
        }
    }
    
    return true;
}
```
**Complexity:** Time O(n log n), Space O(1)

---

## 🟡 Medium Problems

### 2. Merge Intervals
**LeetCode #56**

Merge all overlapping intervals.

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
```

**Approach:**
- Sort by start time
- Merge if current overlaps with last merged interval

**Solution:**
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    
    return merged;
}
```
**Complexity:** Time O(n log n), Space O(n)

---

### 3. Insert Interval
**LeetCode #57**

Insert new interval into sorted non-overlapping intervals, merging if needed.

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Approach:**
- Add all intervals before newInterval
- Merge overlapping intervals with newInterval
- Add remaining intervals

**Solution:**
```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    
    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 4. Non-overlapping Intervals
**LeetCode #435**

Find minimum number of intervals to remove to make rest non-overlapping.

```
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1 (Remove [1,3])
```

**Approach:**
- Greedy: sort by end time
- Always keep interval that ends earliest to leave more room

**Solution:**
```cpp
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Sort by end time
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    
    int count = 0;
    int prevEnd = INT_MIN;
    
    for (auto& interval : intervals) {
        if (interval[0] >= prevEnd) {
            prevEnd = interval[1];  // Keep this interval
        } else {
            count++;  // Remove this interval
        }
    }
    
    return count;
}
```
**Complexity:** Time O(n log n), Space O(1)

---

### 5. Meeting Rooms II
**LeetCode #253** (Premium)

Find minimum number of conference rooms required.

```
Input: [[0,30],[5,10],[15,20]]
Output: 2
```

**Approach 1: Two Pointers**
- Separate start and end times
- Count concurrent meetings

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    vector<int> starts, ends;
    for (auto& i : intervals) {
        starts.push_back(i[0]);
        ends.push_back(i[1]);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int rooms = 0;
    int endPtr = 0;
    
    for (int start : starts) {
        if (start < ends[endPtr]) {
            rooms++;
        } else {
            endPtr++;
        }
    }
    
    return rooms;
}
```

**Approach 2: Min Heap**
- Track end times in heap

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> heap;  // Min heap of end times
    
    for (auto& interval : intervals) {
        if (!heap.empty() && heap.top() <= interval[0]) {
            heap.pop();  // Room freed
        }
        heap.push(interval[1]);
    }
    
    return heap.size();
}
```
**Complexity:** Time O(n log n), Space O(n)

---

### 6. Interval List Intersections
**LeetCode #986**

Find intersection of two lists of closed intervals.

```
Input: firstList = [[0,2],[5,10],[13,23],[24,25]]
       secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

**Approach:**
- Two pointers, find intersection of current pair
- Move pointer with smaller end time

**Solution:**
```cpp
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                          vector<vector<int>>& secondList) {
    vector<vector<int>> result;
    int i = 0, j = 0;
    
    while (i < firstList.size() && j < secondList.size()) {
        // Find intersection
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);
        
        if (start <= end) {
            result.push_back({start, end});
        }
        
        // Move pointer with smaller end
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}
```
**Complexity:** Time O(m + n), Space O(1)

---

### 7. Minimum Number of Arrows to Burst Balloons
**LeetCode #452**

Balloons as horizontal intervals. Find minimum arrows (vertical lines) to burst all.

```
Input: [[10,16],[2,8],[1,6],[7,12]]
Output: 2
```

**Approach:**
- Greedy: sort by end position
- Shoot at end of first balloon, skip all overlapping

**Solution:**
```cpp
int findMinArrowPoints(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    
    // Sort by end position
    sort(points.begin(), points.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    
    int arrows = 1;
    int arrowPos = points[0][1];
    
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > arrowPos) {  // Need new arrow
            arrows++;
            arrowPos = points[i][1];
        }
    }
    
    return arrows;
}
```
**Complexity:** Time O(n log n), Space O(1)

---

## 🔴 Hard Problems

### 8. Employee Free Time
**LeetCode #759** (Premium)

Find common free time across all employees.

```
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
```

**Approach:**
- Flatten all intervals
- Sort and merge to find busy times
- Gaps between merged intervals are free time

**Solution:**
```cpp
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    // Flatten all intervals
    vector<vector<int>> intervals;
    for (auto& employee : schedule) {
        for (auto& interval : employee) {
            intervals.push_back(interval);
        }
    }
    
    // Sort by start time
    sort(intervals.begin(), intervals.end());
    
    // Merge to find busy times
    vector<vector<int>> merged = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    
    // Find gaps (free time)
    vector<vector<int>> result;
    for (int i = 1; i < merged.size(); i++) {
        result.push_back({merged[i-1][1], merged[i][0]});
    }
    
    return result;
}
```
**Complexity:** Time O(n log n), Space O(n)

---

## 📚 Study Tips for Intervals

1. **Sort first:** Almost always sort by start time (or end time for greedy)
2. **Draw it out:** Visualize intervals on a number line
3. **Track the right thing:** Sometimes track end times, sometimes count rooms
4. **Consider events:** Start/end as +1/-1 events can simplify counting

---

*[← Back to Pattern](./README.md) | [Next Pattern: Cyclic Sort →](../06-cyclic-sort/README.md)*
