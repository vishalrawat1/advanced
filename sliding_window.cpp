#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Algorithm: Sliding Window (Variable Size)
// Problem: Longest Substring Without Repeating Characters

/*
 * Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Description: Given a string s, find the length of the longest substring without repeating characters.
 *
 * Algorithm Steps:
 * 1. Initialize two pointers (left and right) to 0.
 * 2. Use a hash map or array to store the last index of each character.
 * 3. Expand the window by moving the right pointer.
 * 4. If the current character is already in the map and its index is >= left,
 *    shrink the window by moving left to the next position after the last occurrence.
 * 5. Update the max length and the character's index in the map.
 * 6. Repeat until the right pointer reaches the end.
 *
 * Practice Questions:
 * 1. Max Consecutive Ones III: https://leetcode.com/problems/max-consecutive-ones-iii/
 * 2. Longest Repearting Character Replacement: https://leetcode.com/problems/longest-repeating-character-replacement/
 * 3. Minimum Window Substring: https://leetcode.com/problems/minimum-window-substring/
 * 4. Fruit Into Baskets: https://leetcode.com/problems/fruit-into-baskets/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        long long sum = 0;

        for (int r = 0; r < n; r++) {
            sum += a[r];

            if (r - l + 1 > k) {
        sum -= a[l];
        l++;
    }

    if (r - l + 1 == k) {
        // process window
    }
}

    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "Input: " << s << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(s) << endl; 
    // Expected Output: 3 (abc)

    return 0;
}
