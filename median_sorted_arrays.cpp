#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Algorithm: Binary Search on Partition
// Problem: Median of Two Sorted Arrays

/*
 * Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/ (LeetCode 4)
 *
 * Description: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 * Concept: Partition both arrays such that the left half contains (m+n+1)/2 elements.
 * Binary search on the smaller array to find the correct partition.
 *
 * Practice Questions:
 * 1. K-th Element of Two Sorted Arrays: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
 * 2. Search a 2D Matrix II: https://leetcode.com/problems/search-a-2d-matrix-ii/
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;
    
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return (double)max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Array 1: [1, 3], Array 2: [2]" << endl;
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl; 
    // Expected: 2.0
    
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Array 1: [1, 2], Array 2: [3, 4]" << endl;
    cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl; 
    // Expected: 2.5
    
    return 0;
}
