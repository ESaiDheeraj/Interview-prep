Problem:
Return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

Brute Force solution:
```
class Solution {
public:
    /*
    n - length of the array.
    Time complexity: O(n^2) - two for loops
    Space complexity: O(1)  - no extra space is being used.
    */
    bool containsDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
```

Sorting:
```
class Solution {
public:
    /*
    n - length of the array.
    Theta() is tight bound.
    Time complexity: Theta(nlogn) - stl sort function for vectors.
    Space complexity: Theta(logn)  - extra space used by stl sort function on vectors.
    */
    bool containsDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i)
        {
            if(nums[i - 1] == nums[i]) return true;
        }
        return false;
    }
};
```

Using STL set:
```
class Solution {
public:
    /*
    n - length of the array.
    Time complexity: O(nlogn) - Insertion of n elements into stl set.
    Space complexity: O(n)  - Space taken by n elements in the set.
    */
    bool containsDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        set<int> st;
        for(int i = 0; i < n; ++i)
        {
            st.insert(nums[i]);     // T - O(logn), S - O(1)
        }
        if((int)st.size() == n) return false;   // T - O(1), S - O(1)
        return true;
    }
};
```

Using STL unordered set:
```
class Solution {
public:
    /*
    n - length of the array.
    Time complexity: Theta(n) - Insertion of n elements into stl unordered_set.
    Space complexity: O(n)  - Space taken by n elements in the unordered_set.
    */
    bool containsDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; ++i)
        {
            st.insert(nums[i]);     // T - Theta(1), S - O(1)
        }
        if((int)st.size() == n) return false;   // T - O(1), S - O(1)
        return true;
    }
};
```