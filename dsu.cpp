#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Algorithm: Disjoint Set Union (DSU) / Union-Find
// Problem: Redundant Connection

/*
 * Problem Link: https://leetcode.com/problems/redundant-connection/
 *
 * Description: In this problem, a tree is an undirected graph that is connected and has no cycles.
 * You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
 * The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
 * Return an edge that can be removed so that the resulting graph is a tree of n nodes.
 *
 * Algorithm Steps:
 * 1. Initialize parent array where parent[i] = i for each node (each node is its own parent initially).
 * 2. Find function: returns the representative (root) of the set containing element x with path compression.
 * 3. Union function: merges the sets containing elements x and y with rank/size optimization.
 * 4. Iterate through edges:
 *    - If find(u) == find(v), adding edge (u, v) creates a cycle. This suggests it's the redundant edge.
 *    - Otherwise, union(u, v).
 *
 * Practice Questions:
 * 1. Number of Operations to Make Network Connected: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 * 2. Accounts Merge: https://leetcode.com/problems/accounts-merge/
 * 3. Most Stones Removed with Same Row or Column: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * 4. Checking Existence of Edge Length Limited Paths: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
 */

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by size
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (const auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    
    cout << "Input: edges = [[1,2],[1,3],[2,3]]" << endl;
    vector<int> result = sol.findRedundantConnection(edges);
    
    if (!result.empty()) {
        cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    // Expected Output: [2, 3]

    return 0;
}
