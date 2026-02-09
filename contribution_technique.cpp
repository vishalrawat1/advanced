#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Algorithm: Contribution Technique / Monotonic Stack
// Problem: Sum of Subarray Minimums

/*
 * Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/ (LeetCode 907)
 * Additional Problem: https://codeforces.com/problemset/problem/817/D (Imbalanced Array)
 *
 * Description: Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 *
 * Concept: For each element arr[i], we find how many subarrays have arr[i] as the minimum.
 * We need the previous less element (PLE) and next less element (NLE).
 *
 * Practice Questions:
 * 1. Sum of Subarray Ranges: https://leetcode.com/problems/sum-of-subarray-ranges/
 * 2. Total Appeal of A String: https://leetcode.com/problems/total-appeal-of-a-string/
 * 3. Largest Rectangle in Histogram: https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    long long mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<pair<int, int>> s1, s2;
    
    // Previous Less Element
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!s1.empty() && s1.top().first > arr[i]) {
            count += s1.top().second;
            s1.pop();
        }
        s1.push({arr[i], count});
        left[i] = count;
    }
    
    // Next Less Element
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (!s2.empty() && s2.top().first >= arr[i]) {
            count += s2.top().second;
            s2.pop();
        }
        s2.push({arr[i], count});
        right[i] = count;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    cout << "Input: arr = [3, 1, 2, 4]" << endl;
    cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl; 
    // Expected: 17
    // Subarrays: [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4] 
    // Mins: 3, 1, 2, 4, 1, 1, 2, 1, 1, 1 -> Sum: 17
    
    return 0;
}
