#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Algorithm: Sliding Window with 3 Pointers (atMost(K) - atMost(K-1) technique)
// Problem: Subarrays with K Different Integers

/*
 * Problem Link: https://leetcode.com/problems/subarrays-with-k-different-integers/ (LeetCode 992)
 *
 * Description: Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * A good subarray is a subarray where the number of different integers in that subarray is exactly k.
 *
 * Concept: exactly(K) = atMost(K) - atMost(K-1)
 *
 * Practice Questions:
 * 1. Count Number of Nice Subarrays: https://leetcode.com/problems/count-number-of-nice-subarrays/
 * 2. Number of Substrings Containing All Three Characters: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * 3. Max Consecutive Ones III (related sliding window): https://leetcode.com/problems/max-consecutive-ones-iii/
 */

int atMostK(vector<int>& nums, int k) {
    int res = 0;
        int n = nums.size();
        map<int, int> mp;

        int r = 0;
        int nl = 0;
        int fl = 0;

        while (r < n) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[nl]]--;
                if (mp[nums[nl]] == 0) {
                    mp.erase(nums[nl]);
                }
                nl++;
                fl = nl;
            }
            // remove extra duplicates on the left
            while (mp[nums[nl]] > 1) {
                mp[nums[nl]]--;
                nl++;
            }
            // count subarrays
            if (mp.size() == k) {
                res += nl - fl + 1;
            }

            r++;
        }
    return res;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Input: nums = [1,2,1,2,3], k = " << k << endl;
    cout << "Output: " << subarraysWithKDistinct(nums, k) << endl; 
    // Expected: 7 ([1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2])
    
    return 0;
}
