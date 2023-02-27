Problem:

Given an integer array, return the `k` most frequent elements in the array.

Note:
* `k` is in the range of [1, no. of unique elements in the array]

### TODO: 
This question can be done using a modified version of selection sort called k-selection sort. - [source](https://leetcode.com/problems/top-k-frequent-elements/solutions/81631/3-ways-to-solve-this-problem/?orderBy=most_votes)

Using Map and Sorting of vector of pairs:
```
class Solution {
public:
    /*
    Time complexity: O(nlogn) - Both map and sorting.
    Space complexity: O(n) - To store map, vec and ans.
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = (int)nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; ++i)  // T - O(nlogn), S - O(n)
        {
            mp[nums[i]] += 1;       // T - O(logn), S - O(1)
        }
        vector<pair<int, int>> vec;
        for(auto pr: mp)
        {
            vec.push_back({pr.second, pr.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());       // T - O(nlogn), S - O(n)
        vector<int> ans(k, 0);
        for(int i = 0; i < k; ++i)
        {
            ans[i] = vec[i].second;
        }
        return ans;
    }
};
```

Using Unordered map and priority queue
```
class Solution {
public:
    /*
    Time complexity: O(nlogn) - push() and pop() in priority queue.
    Space complexity: O(n) - unordered map
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i)  // T - O(n) on average, S - O(n)
        {
            mp[nums[i]] += 1;       // T - O(1) on average, S - O(1)
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});     // push() and pop() are O(logn) in priority queue.
            if((int)pq.size() > k) pq.pop();
        }
        vector<int> ans(k, 0);
        // we can actually write a for loop here, because we are sure that there should be only k elements in minHeap.
        for(int i = k - 1; i >= 0; --i)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
```

Using Unordered map and Bucket sort:
* Bucket sort can be used here because the frequency of any element in the array can be at max equal to `n` only. So, we defined a 2D vector (called `buckets`) of row size `n + 1` to do the bucket sort.
* We have also taken advantage of 'You may return the answer in any order.'
```
class Solution {
public:
    /*
    Time complexity: O(n) - unordered map and filling buckets.
    Space complexity: O(n) - unordered map
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i)  // T - O(n) on average, S - O(n)
        {
            mp[nums[i]] += 1;       // T - O(1) on average, S - O(1)
        }
        // These pairs in unordered map
        vector<vector<int>> buckets(n + 1);
        for(auto it: mp)        // T - O(n), S - O(n)
        {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;        // T - O(k), S - O(k)
        for(int i = n; i > 0; --i)
        {
            // taking advantage of 'you may return the answer in any order'.
            for(int j = 0; j < (int)buckets[i].size(); ++j)
            {
                ans.push_back(buckets[i][j]);
                if((int)ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
```

## Similar Questions:
1. [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)

Solution using Unordered map and Bucket Sort.
Note: 
* If there are multiple answers, return any of them.

**Q:** How can there be multiple answers?
**A:** when input is "acacac", then both "aaaccc" and "cccaaa" are correct answers.
```
class Solution {
public:
    /*
    Time complexity: O(n)
    Space complexity: O(n)
    */
    string frequencySort(string s) {
        int n = (int)s.length();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; ++i)  // T - O(n) on average, S - O(n)
        {
            mp[s[i]] += 1;
        }
        
        vector<vector<char>> buckets(n + 1);    // T - O(n), S - O(n)
        for(auto it: mp)
        {
            buckets[it.second].push_back(it.first);
        }

        string ans = "";
        // Two for loops combined will run atmost 'n' times only.
        for(int i = n; i > 0; --i)
        {
            for(int j = 0; j < (int)buckets[i].size(); ++j)
            {
                ans += string(i, buckets[i][j]);
            }
        }
        return ans;
    }
};
```

2. [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/description/)

3. [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)