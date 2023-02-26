Problem:

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

Note: There is exactly one soluction.

Brute-force Approach:
```
class Solution {
public:
    /*
    n - length of the array.
    Time complexity: O(n^2) - two for loops
    Space complexity: O(1)  - ans vector is of constant size only.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<int> ans;

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                long long sum = (long long)nums[i] + (long long)nums[j];
                if(sum == (long long)target)
                {
                    ans = vector<int>({i, j});
                    return ans;
                }
            }
        }
        return ans;
    }
};
```

Using Unordered map:
```
class Solution {
public:
    /*
    Time complexity: O(n) on average (i.e., Theta(n))
    Space complexity: O(n) - for storing the array elements in the unordered map.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<int> ans;

        unordered_map<long long, int> mp;

        for(int i = 0; i < n; ++i)      // T - O(n) on average, S - O(n)
        {
            long long numToFind = (long long)target - (long long)nums[i];
            if(mp.find(numToFind) != mp.end())      // T - O(1) on average (i.e., Theta(1)), S - O(1)
            {
                ans = vector<int>({mp[numToFind], i});
                return ans;
            }
            else
            {
                mp[(long long)nums[i]] = i;
            }
        }
        return ans;
    }
};
```