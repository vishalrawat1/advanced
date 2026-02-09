#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Algorithm: Two Pointers (Sorted Array / Palindrome Check)
// Problem: Two Sum II - Input Array Is Sorted

/*
 * Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Description: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
 * find two numbers such that they add up to a specific target number.
 *
 * Algorithm Steps:
 * 1. Initialize two pointers: left at the start (0) and right at the end (n-1).
 * 2. Calculate the sum of elements at left and right pointers.
 * 3. If sum == target, return indices (1-based).
 * 4. If sum < target, increment left pointer (need a larger sum).
 * 5. If sum > target, decrement right pointer (need a smaller sum).
 * 6. Repeat until the pointers meet.
 *
 * Practice Questions:
 * 1. 3Sum: https://leetcode.com/problems/3sum/
 * 2. Container With Most Water: https://leetcode.com/problems/container-with-most-water/
 * 3. Valid Palindrome: https://leetcode.com/problems/valid-palindrome/
 * 4. Remove Duplicates from Sorted Array: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = n - 1;

        while (l < r) {
            if (condition) {
                // do something
                l++;
                r--;
            } else if (need_more) {
                l++;
            } else {
                r--;
            }
        }
 // Should not reach here as per problem statement
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    
    cout << "Input: numbers = [2,7,11,15], target = " << target << endl;
    vector<int> result = sol.twoSum(numbers, target);
    
    if (!result.empty()) {
        cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
    // Expected Output: [1, 2]

    return 0;
}
