#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Algorithm: Expansion Around Center (or Manacher's Algorithm for O(N))
// Problem: Longest Palindromic Substring

/*
 * Problem Link: https://leetcode.com/problems/longest-palindromic-substring/ (LeetCode 5)
 *
 * Description: Given a string s, return the longest palindromic substring in s.
 *
 * Practice Questions:
 * 1. Palindromic Substrings: https://leetcode.com/problems/palindromic-substrings/
 * 2. Longest Palindromic Subsequence: https://leetcode.com/problems/longest-palindromic-subsequence/
 * 3. Shortest Palindrome: https://leetcode.com/problems/shortest-palindrome/
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                // Calculation to find start index based on center and length
                // If len is odd (len1), start = i - len/2
                // If len is even (len2), start = i - (len-1)/2
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // length is (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << "Input: " << s << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl; 
    // Expected: "bab" or "aba"
    
    return 0;
}