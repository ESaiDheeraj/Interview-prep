Problem:

Given a list of strings, group them in such a way that all strings in a group are anagrams of each other.

Ex: I/P - ["eat", "tea", "bat", "tab", "cat"\]
O/P - [["eat", "tea"], ["bat", "tab"], ["cat"]\]

Using Unordered map + STL sort function:
```
class Solution {
public:
    /*
    n - number of strings.
    m - length of the largest string.
    Time complexity: O(n + nmlogm) = O(nmlogm)
    Space complexity: O(n + nm) = O(nm)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int)strs.size();
        unordered_map<string, vector<string>> mp;   // S - O(n)
        for(int i = 0; i < n; ++i)
        {
            string t = strs[i];             // S - O(m) new string of same size is created.
            sort(t.begin(), t.end());       // T - O(mlogm), S - O(logm)
            mp[t].push_back(strs[i]);       // T - O(1), S - O(1)
        }
        
        vector<vector<string>> ans;         // S - O(n)
        for(auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
```

Using Unordered map + Counting sort:
```
class Solution {
public:
    /*
    n - number of strings.
    m - length of the largest string.
    Time complexity: O(n + nm) = O(nm)
    Space complexity: O(n + nm) = O(nm)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int)strs.size();
        unordered_map<string, vector<string>> mp;   // S - O(n)
        for(int i = 0; i < n; ++i)
        {
            string t = cntSort(strs[i]);       // T - O(m), S - O(m)
            mp[t].push_back(strs[i]);       // T - O(1), S - O(1)
        }
        
        vector<vector<string>> ans;         // S - O(n)
        for(auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }

    string cntSort(string s){
        // using counting sort because the characters are only lowercase english letters.
        vector<int> cnt(26, 0);
        for(auto c: s)
        {
            cnt[c - 'a'] += 1;
        }

        string t;
        for(int i = 0; i < 26; ++i)
        {
            t += string(cnt[i], 'a' + i);   // this is one type of std::string class constructor - string (size_t n, char c);
        }
        return t;
    }
};
```