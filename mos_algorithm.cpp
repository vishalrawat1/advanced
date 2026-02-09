#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Algorithm: Mo's Algorithm (Square Root Decomposition for Offline Queries)
// Problem: Powerful Array (Codeforces 86D)

/*
 * Problem Link: https://codeforces.com/problemset/problem/86/D
 *
 * Description: Given an array a of n integers, and t queries of the form (l, r).
 * For each query, calculate the sum of Ks * s * s for all distinct integers s in the subarray a[l...r], 
 * where Ks is the number of occurrences of s in the subarray.
 *
 * Concept: Reorder queries to minimize movement of L and R pointers.
 * Sort queries based on block of L, then by R.
 *
 * Practice Questions:
 * 1. Little Elephant and Array: https://codeforces.com/problemset/problem/220/B
 * 2. Distinct Elements in Subarray: https://www.spoj.com/problems/DQUERY/
 */

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return (l / block_size % 2 == 0) ? (r < other.r) : (r > other.r); // Optimization
    }
};

const int MAXN = 200005;
const int MAXVAL = 1000005;
long long current_answer = 0;
int cnt[MAXVAL];
int a[MAXN];
long long answers[MAXN];

void add(int pos) {
    int x = a[pos];
    current_answer -= (long long)cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += (long long)cnt[x] * cnt[x] * x;
}

void remove(int pos) {
    int x = a[pos];
    current_answer -= (long long)cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += (long long)cnt[x] * cnt[x] * x;
}

int main() {
    // Example setup for local testing (normally user input)
    int n = 3;
    int t = 2;
    a[0] = 1; a[1] = 2; a[2] = 1; // 1-based indexing adjusted
    
    // 0-indexed for implementation simplicity here, problem usually 1-indexed
    vector<Query> queries = {
        {0, 2, 0}, 
        {1, 2, 1}
    };

    block_size = max(1, (int)(n / sqrt(t)));
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;

    for (const auto& q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = current_answer;
    }

    cout << "Query Results:" << endl;
    for (int i = 0; i < t; i++) {
        cout << "Query " << i << ": " << answers[i] << endl;
    }
    // Expected for [1,2,1]:
    // Q(0,2): 1*1*1 + 2*2*1 + 1 (cnt=2, val=1 -> 2*2*1=4; cnt=1, val=2 -> 1*1*2=2) => 4+2 = 6? 
    // Wait, formula is Ks * Ks * s.
    // [1, 2, 1]: 1 appears twice -> 2*2*1 = 4. 2 appears once -> 1*1*2 = 2. Sum = 6. Correct.
    // [2, 1]: 2 appears once -> 2. 1 appears once -> 1. Sum = 3.

    return 0;
}
