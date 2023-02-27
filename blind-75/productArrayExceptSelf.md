Problem:

Given an integer array `nums`, return an integer array `answer` such that `answer[i]` is product of all elements in `nums` array except from `nums[i]`.

Using two for loops and no additional space apart from output array.
```
class Solution {
public:
    /*
    Time complexity: O(n) - two for loops
    Space complexity: O(n) - ans vector
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 1);
        for(int i = 1; i < n; ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suff = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] *= suff;
            suff *= nums[i];
        }
        return ans;
    }
};
```

Using only one for loop (little tricky) solution:
```
class Solution {
public:
    /*
    Time complexity: O(n) - one for loop
    Space complexity: O(n) - ans vector
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 1);
        int pref = 1, suff = 1;
        for(int i = 0; i < n; ++i)
        {
            ans[i] *= pref;
            pref *= nums[i];
            ans[n - i - 1] *= suff;
            suff *= nums[n - i - 1];
        }
        return ans;
    }
};
```