#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
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


pair<ll ,ll> getfar(vvll &adj , int node){
    
    vll vis(adj.size() , 0) , dist(adj.size() , -1);
    queue<ll>q;
    q.push(node);
    dist[node]=0;
    pair<ll , ll>distfarnode = {node , 0};
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        for(auto x : adj[a]){
            if(dist[x]==-1){
                dist[x]=dist[a]+1;
                q.push(x);
                if(distfarnode.second < dist[x]){
                    distfarnode.first = x;
                    distfarnode.second = dist[x];
                }
            }
        }
    }
    return distfarnode;
}

ll finddiameter(vvll &adj , int start){
    //got to farthes point then from that fartheset go to farthest that will be diamtere
    auto a = getfar(adj , start);
    //a.first = node  a.second = dist;
    auto b = getfar(adj , a.first);

    return b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n1;
    cin>>n1;
    vvll adj1(n1);
    for(ll i=0;i<n1-1;i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        adj1[x].push_back(y);
        adj1[y].push_back(x);

    }
    ll n2;
    cin>>n2;
    vvll adj2(n2);
    for(ll i=0;i<n2-1;i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        adj2[x].push_back(y);
        adj2[y].push_back(x);

    }
    //find max di in t1 and t2 
    //half them and adde with ceil value 
    ll h1 = finddiameter(adj1 , 0);
    ll h2 = finddiameter(adj2 , 0);
\
     ll x=ceil((h1+1)/2)+ceil((h2+1)/2)+1;
     cout<<max(max(h1 , h2),x)<<"\n";

    return 0;
}