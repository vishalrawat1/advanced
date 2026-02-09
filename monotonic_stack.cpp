#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Algorithm: Monotonic Stack (Next Greater Element)
// Problem: Next Greater Element I

/*
 * Problem Link: https://leetcode.com/problems/next-greater-element-i/
 *
 * Description: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
 * Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 *
 * Algorithm Steps:
 * 1. Initialize an empty stack and a hash map.
 * 2. Iterate through the array (nums2) from left to right - OR - iterate from right to left (common for Next Greater Element).
 * 3. While the stack is not empty and the current element is greater than the element at the top,
 *    it means we found the next greater element for the top element. Pop from stack and store in map.
 * 4. Push the current element onto the stack.
 * 5. After the loop, elements remaining in the stack do not have a next greater element.
 *
 * Practice Questions:
 * 1. Daily Temperatures: https://leetcode.com/problems/daily-temperatures/
 * 2. Next Greater Element II: https://leetcode.com/problems/next-greater-element-ii/
 * 3. Largest Rectangle in Histogram: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 4. 132 Pattern: https://leetcode.com/problems/132-pattern/
 * 5. Sum of Subarray Minimums: https://leetcode.com/problems/sum-of-subarray-minimums/
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> next_greater;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> res;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                res.push_back(next_greater[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    cout << "nums1 = [4,1,2], nums2 = [1,3,4,2]" << endl;

    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected Output: [-1, 3, -1]

    return 0;
}
