#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Algorithm: Binary Search on Answer
// Problem: Sell Diminishing-Valued Colored Balls

/*
 * Problem Link: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/ (LeetCode 1648)
 *
 * Description: You have an inventory of balls with different values. You want to sell `orders` balls to maximize value.
 *
 * Concept: Binary search for the cutoff value `k`. We sell all balls with value > k.
 * For value == k, we sell remaining required balls.
 *
 * Practice Questions:
 * 1. Maximum Running Time of N Computers: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 * 2. Minimum Time to Complete Trips: https://leetcode.com/problems/minimum-time-to-complete-trips/
 * 3. Koko Eating Bananas: https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long long l = 0, r = *max_element(inventory.begin(), inventory.end());
        long long ans = -1;
        
        // Binary search for the minimum value of a ball we will sell
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long count = 0;
            for (int x : inventory) {
                if (x > mid) {
                    count += (x - mid);
                }
            }
            if (count >= orders) {
                ans = mid;
                l = mid + 1; // Try to find a higher cutoff
            } else {
                r = mid - 1;
            }
        }
        
        // ans is the largest cutoff such that we can sell >= orders balls strictly greater than ans
        // Actually we want the cutoff where we have exactly or more orders.
        // Let's refine: We sell everything > ans.
        // We might need to sell some equal to ans.
        
        // Actually, let's use the `ans` as the threshold value.
        // If we choose cutoff `T`, we sell all balls with value > T. 
        // If count > orders, we need a higher T.
        // The binary search above finds the largest `T` such that count(> T) >= orders? No.
        // If count(x > mid) >= orders, it means even with a higher threshold we might satisfy orders.
        // Wait, if we set threshold lower, count increases. 
        // We want the largest T such that count(x >= T) >= orders.
        
        // Let's re-implement carefully.
        // We want to find largest T such that sum(max(0, x - T)) >= orders is NOT correct directly for exact sum.
        // We find T such that we sell all > T, and some = T.
        
        l = 0; r = *max_element(inventory.begin(), inventory.end());
        long long T = 0;
        
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long count = 0;
            for (int x : inventory) {
                if (x >= mid) count += (x - mid + 1);
            }
            if (count >= orders) {
                T = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        // T is the value such that taking all balls >= T gives >= orders.
        // Taking all balls >= T+1 gives < orders.
        // So we take all balls > T, and some balls = T.
        
        long long totalValue = 0;
        long long mod = 1e9 + 7;
        long long count = 0;
        
        for (int x : inventory) {
            if (x > T) {
                long long terms = x - T;
                long long sum = (x + T + 1) * terms / 2;
                totalValue = (totalValue + sum) % mod;
                count += terms;
            }
        }
        
        long long remaining = orders - count;
        totalValue = (totalValue + remaining * T) % mod;
        
        return totalValue;
    }
};

int main() {
    Solution sol;
    vector<int> inventory = {2, 5};
    int orders = 4;
    cout << "Inventory: [2, 5], Orders: 4" << endl;
    cout << "Max Profit: " << sol.maxProfit(inventory, orders) << endl; 
    // Expected: 14 (5 + 4 + 3 + 2 = 14)
    
    return 0;
}
