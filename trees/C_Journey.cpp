#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e3 + 10;
const int INF = 1e9;

vector<pair<int,int>> g[N];
int par[N], sz[N];

// DSU make
void make(int v){
    par[v] = v;
    sz[v] = 1;
}

// DSU find with path compression
int find(int v){
    if(v == par[v]) return v;
    return par[v] = find(par[v]);
}

// Union by size
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

template<typename T>
inline bool chmin(T &a, const T &b){ if(b < a){ a = b; return true; } return false; }

template<typename T>
inline bool chmax(T &a, const T &b){ if(b > a){ a = b; return true; } return false; }

void solve_case(){
    
}
#include <bits/stdc++.h>
using namespace std;

vector<int>dp;
long double dfs(int node, int parent, vector<vector<int>>& adj, int &count) {
    long double sum=0;
    for(auto child : adj[node]){
        if(child!=parent){
            sum += 1 + dfs(child , node ,adj , count);
        }
    }
    return sum ? sum/(adj[node].size() - (parent!=-1)) : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;
    int n;
    cin >> n;
    dp.resize(n ,0);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long double x = dfs(0, -1, adj, count);
    cout<<fixed<<setprecision(15)<<x<<"\n";
    // cout << fixed << setprecision(15) << (double)n / count << "\n";
    return 0;
}
