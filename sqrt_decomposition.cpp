#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// Algorithm: Sqrt Decomposition
// Problem: Range Sum Query - Mutable

/*
 * Problem Link: https://leetcode.com/problems/range-sum-query-mutable/ (LeetCode 307)
 *
 * Description: Given an integer array nums, handle multiple queries of the following types:
 * 1. Update: Update the value of an element in nums.
 * 2. Sum Range: Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 *
 * Concept: Divide the array into blocks of size sqrt(n). Maintain sum of each block.
 * Update takes O(1), Query takes O(sqrt(n)).
 *
 * Practice Questions:
 * 1. MO's Algorithm (Generalized version of sqrt decomp for offline queries): https://codeforces.com/problemset/problem/86/D
 * 2. Interesting Queries (Codeforces): https://codeforces.com/problemset/problem/398/D
 */

class NumArray {
    vector<int> b;
    vector<int> nums;
    int len;

public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        this->nums = nums;
        double l = sqrt(nums.size());
        len = ceil(nums.size() / l);
        b.resize(len);
        for (int i = 0; i < nums.size(); i++)
            b[i / len] += nums[i];
    }

    void update(int i, int val) {
        int b_l = i / len;
        b[b_l] = b[b_l] - nums[i] + val;
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        int startBlock = i / len;
        int endBlock = j / len;
        
        if (startBlock == endBlock) {
            for (int k = i; k <= j; k++)
                sum += nums[k];
        } else {
            // Partial start block
            for (int k = i; k <= (startBlock + 1) * len - 1; k++)
                sum += nums[k];
            // Full middle blocks
            for (int k = startBlock + 1; k <= endBlock - 1; k++)
                sum += b[k];
            // Partial end block
            for (int k = endBlock * len; k <= j; k++)
                sum += nums[k];
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray obj(nums);
    cout << "Initial Sum (0, 2): " << obj.sumRange(0, 2) << endl; // 9
    obj.update(1, 2);
    cout << "Updated Sum (0, 2): " << obj.sumRange(0, 2) << endl; // 8
    
    return 0;
}
