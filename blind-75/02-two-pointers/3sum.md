Problem:

Find the triplets having sum = 0 in the given input array.

Solution found at [link](https://leetcode.com/problems/3sum/solutions/1462423/c-both-two-pointers-and-hashmap-approach-explained/?orderBy=most_votes)

Sorting + Two pointer Approach:

Fix any one number in the array and find the other two numbers in the rest of the array using two pointer approach.
```
class Solution 
{
public:
    /*
    Time complexity: O(n^2) 
    Space complexity: O(1) extra space apart from the output vector<vector<int>>
    */
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());         // T - O(nlogn) on avg, S - O(logn) on avg.
        vector<vector<int>> ans;
        if (n < 3)
            return ans;           // Base case 1
        if (nums[0] > 0)
            return ans;     // Base case 2
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                break;
            if ((i > 0) and (nums[i] == nums[i - 1])) 
                continue;
            int low = i + 1;
            int high = n - 1;
            int sum = 0;
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                if (sum < 0)
                    low++;      // remove one negative number
                else if (sum > 0)
                    high--;     // remove one positive number
                else
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int last_low_occur = nums[low];
                    int last_high_occur = nums[high];
                    while ((low < high) and (nums[low] == last_low_occur)) low++;
                    while ((low < high) and (nums[high] == last_high_occur)) high--;
                }
            }
        }
        return ans;
    }
};
```

TODO:
* There is one approach using a Hashmap, I should try to understand and code it.
* What is the maximum total possible triplets for any input array? - n? (I don't know).

Similar Question: [3Sum Closest](https://leetcode.com/problems/3sum-closest/description/)
Solution using the same logic: Sorting + Two pointer apporach
```
class Solution 
{
public:
    /*
    Time complexity: O(n^2)
    Space complexity: O(logn) for sorting the array.
    */
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int closest_dist_target = (int)1e5;
        int closest_val_target = 0;
        for (int i = 0; i < n; ++i)
        {
            int low = i + 1;
            int high = n - 1;
            int sum = 0;
            int curr_dist = 0;
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                if (sum > target)
                {
                    curr_dist = sum - target;
                    if (curr_dist < closest_dist_target)
                    {
                        closest_dist_target = curr_dist;
                        closest_val_target = sum;
                    }
                    high--;     // remove one positive number
                }
                else if (sum < target)
                {
                    curr_dist = target - sum;
                    if (curr_dist < closest_dist_target)
                    {
                        closest_dist_target = curr_dist;
                        closest_val_target = sum;
                    }
                    low++;      // remove one negative number
                }
                else
                {
                    closest_dist_target = 0;
                    closest_val_target = sum;
                    return closest_val_target;
                }
            }
        }
        return closest_val_target;
    }
};
```