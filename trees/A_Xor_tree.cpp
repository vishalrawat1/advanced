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
vector<int>vis,init,goal,res;
void dfs(vector<vector<int>>&adj , int start , int level , int even , int odd){
    vis[start]=1;
    int curr;
    if(level%2==0){
        curr = (init[start]+even)%2;
    }else{
        curr = (init[start]+odd)%2;
    }

    if(curr!=goal[start]){
        res.push_back(start);
        if(level%2==0)even++;
        else odd++;
        // cout<<start<<" "<<even<<" "<<odd<<"\n";
    }

    for(auto x : adj[start]){
        if(!vis[x]){
            dfs(adj , x , level+1 , even , odd);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vis.resize(n , 0);
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int x ,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init.resize(n,0),goal.resize(n ,0);
    for(int i=0;i<n;i++){
        cin>>init[i];
    }
    for(int i=0;i<n;i++){
        cin>>goal[i];
    }

    dfs(adj ,0 , 0 ,0 , 0);
    cout<<res.size()<<"\n";
    for(auto x : res){
        cout<<x+1<<"\n";
    }
    return 0;
}