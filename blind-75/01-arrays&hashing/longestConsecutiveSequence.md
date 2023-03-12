Problem:

Given an unsorted array of numbers, return the length of the longest consecutive elements sequence.


Optimized approach using Unordered set:
```
class Solution {
public:
    /*
    Time complexity: O(n)
    Space complexity: O(n) - unordered set.
    */
    int longestConsecutive(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_set<int> st;
        for(int num: nums) st.insert(num);
        int max_len = 0;
        for(int num: st)        // T - O(n)
        {
            if(st.find(num - 1) == st.end())    // This if will make sure the T is O(n)
            {
                int curr_num = num;
                int curr_len = 1;
                while(st.find(curr_num + 1) != st.end())
                {
                    curr_num += 1;
                    curr_len += 1;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};
```

Using Disjoint Set Union Datastructure:
```
class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int N)
    {
        parent.resize(N);
        size.resize(N);
        for (int i = 0; i < N; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;   
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    /*
    Time complexity: O(n)
    Space complexity: O(n) 
    */
    int longestConsecutive(vector<int>& nums) {
        int n = (int)nums.size();
        // Beware of repeating numbers. Use set instead of vector at the start.
        unordered_map<int, int> mp;
        DSU dsu(n);
        for(int i = 0; i < n; ++i)
        {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n; ++i)
        {
            // if(mp.find(nums[i]) != mp.end()) 
            //     continue;
            if(mp.find(nums[i] + 1) != mp.end())
            {
                dsu.union_sets(mp[nums[i]], mp[nums[i] + 1]);   // here I am writing mp[nums[i]] instead i directly to account for repeated elements in the input array.
            }
            if(mp.find(nums[i] - 1) != mp.end())
            {
                dsu.union_sets(mp[nums[i]], mp[nums[i] - 1]);
            }
            // mp[nums[i]] = i;
        }
        int max_size = 0;
        for(int i = 0; i < n; ++i)
        {
            max_size = max(max_size, dsu.size[i]);
        }
        return max_size;
    }
};
```