#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Algorithm: Tarjan's Algorithm for Strongly Connected Components (SCC)
// Note: A similar logic using discovery times and low-link values is used for finding Articulation Points and Bridges.

/*
 * Problem Link (SCC): https://leetcode.com/problems/critical-connections-in-a-network/ (This is for Bridges, but uses Tarjan's concept)
 * Problem Link (SCC specific): https://practice.geeksforgeeks.org/problems/strongly-connected-components-measurable-nodes/1
 *
 * Practice Questions:
 * 1. Critical Connections in a Network (Bridges): https://leetcode.com/problems/critical-connections-in-a-network/
 * 2. Articulation Points (GFG): https://practice.geeksforgeeks.org/problems/articulation-point-1/1
 * 3. Course Schedule II (can be solved with topological sort/cycle detection, related to graph components): https://leetcode.com/problems/course-schedule-ii/
 */

class TarjanSCC {
    int n;
    vector<vector<int>> adj;
    vector<int> ids, low;
    vector<bool> onStack;
    stack<int> st;
    int idCounter, sccCount;

public:
    TarjanSCC(int n, vector<vector<int>>& adj) : n(n), adj(adj) {
        ids.assign(n, -1);
        low.assign(n, 0);
        onStack.assign(n, false);
        idCounter = 0;
        sccCount = 0;
    }

    void dfs(int at) {
        st.push(at);
        onStack[at] = true;
        ids[at] = low[at] = idCounter++;

        for (int to : adj[at]) {
            if (ids[to] == -1) {
                dfs(to);
                low[at] = min(low[at], low[to]);
            } else if (onStack[to]) {
                low[at] = min(low[at], ids[to]);
            }
        }

        // On recursive callback, if we're at the root of an SCC
        if (ids[at] == low[at]) {
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                onStack[node] = false;
                low[node] = ids[at];
                if (node == at) break;
            }
            sccCount++;
        }
    }

    int findSCCs() {
        for (int i = 0; i < n; i++) {
            if (ids[i] == -1) {
                dfs(i);
            }
        }
        return sccCount;
    }
};

int main() {
    int n = 8;
    vector<vector<int>> adj(n);
    // Example graph edges
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {4};
    adj[4] = {5, 7};
    adj[5] = {6};
    adj[6] = {4};
    adj[7] = {};

    TarjanSCC tarjan(n, adj);
    cout << "Number of Strongly Connected Components: " << tarjan.findSCCs() << endl;

    return 0;
}
