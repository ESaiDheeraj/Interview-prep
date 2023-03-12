Problem:

Given a phrase, check if it is a palindrome or not. Because it is a phrase, you should first romove all non-alphanumeric characters, convert all uppercase to lowercase letters and then you will end up with a string. Once you have a string, check if it is a palindrome in usual way.

Two pointer approach to check if a string is a palindrome:
```
class Solution {
public:
    /*
    Time complexity: O(n) - 2 for loops
    Space complexity: O(n) - new string of length atmost the length of input string.
    */
    bool isPalindrome(string s) {
        string new_string = "";
        for (char c : s)
        {
            if ((c >= 'A') and (c <= 'Z'))
            {
                new_string += char(c - 'A' + 'a');
            }
            else if ((c >= 'a') and (c <= 'z'))
            {
                new_string += c;
            }
            else if ((c >= '0') and (c <= '9'))
            {
                new_string += c;
            }
        }
        int l = (int)new_string.length();
        for (int i = 0; i < l/2; ++i)
        {
            if (new_string[i] != new_string[l - i - 1]) return false;
        }
        return true;
    }
};
```