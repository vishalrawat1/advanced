#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Algorithm: Kadane's Algorithm
// Problem: Maximum Subarray Sum

/*
 * Problem Link: https://leetcode.com/problems/maximum-subarray/ (LeetCode 53)
 *
 * Description: Given an integer array nums, find the subarray with the largest sum, and return its sum.
 *
 * Practice Questions:
 * 1. Maximum Sum Circular Subarray: https://leetcode.com/problems/maximum-sum-circular-subarray/
 * 2. Maximum Product Subarray: https://leetcode.com/problems/maximum-product-subarray/
 * 3. Longest Turbulance Subarray: https://leetcode.com/problems/longest-turbulent-subarray/
 */

int maxSubArray(vector<int>& nums) {
    int max_so_far = INT_MIN;
    int current_max = 0;

    for (int x : nums) {
        current_max += x;
        if (max_so_far < current_max) {
            max_so_far = current_max;
        }
        if (current_max < 0) {
            current_max = 0;
        }
    }
    return max_so_far;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum is: " << maxSubArray(nums) << endl;
    return 0;
}
