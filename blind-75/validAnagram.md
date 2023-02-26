Problem:

Two strings `s` and `t` are given, return `true` if `s` is an anagram of `t`, and return `false` otherwise.

Sorting:
```
class Solution {
public:
    /*
    n - max(s.length(), t.length())
    Time complexity: Theta(nlogn)
    Space complexity: Theta(logn)
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;  // T - O(1), S - O(1)

        sort(s.begin(), s.end());       // STL sort function.
        sort(t.begin(), t.end());

        if(s == t) return true;         // T - O(n), S - O(1)
        return false;
    }
};
```

Unordered Map:
```
class Solution {
public:
    /*
    n - max(s.length(), t.length())
    Time complexity: O(n) - for find operation on unordered map.
    Space complexity: O(n) - to store all the characters in unordered map.
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;  // T - O(1), S - O(1)

        int n = (int)s.length();
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; ++i)
        {
            mp[s[i]] += 1;          // T - (Theta(1)) or (O(1) on average), S - O(1)
            mp[t[i]] -= 1;          // [] operator calls find function internally.
        }

        for(auto it: mp)            // T - O(n), S - O(1)
        {
            if(it.second != 0) return false;
        }
        return true;
    }
};
```

If the strings contain only lowercase English letters:
```
class Solution {
public:
    /*
    n - max(s.length(), t.length())
    Time complexity: O(n) - traversing entire strings atleast once.
    Space complexity: O(1) - only 26 characters.
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;  // T - O(1), S - O(1)

        int n = (int)s.length();
        vector<int> cnt(26, 0);     // An array to keep track of counts of letters.

        for(int i = 0; i < n; ++i)  // T - O(n), S - O(1)
        {
            cnt[s[i] - 'a'] += 1;
            cnt[t[i] - 'a'] -= 1;
        }

        for(int i = 0; i < 26; ++i)     // T - O(1), S - O(1)
        {
            if(cnt[i] != 0) return false;
        }
        return true;
    }
};
```