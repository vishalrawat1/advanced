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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum = accumulate(arr.begin() , arr.end() , 0);
    if(sum%3!=0)cout<<0<<endl;
    else{
        // checking till n-1 , and sum will 3 * sum we;; see how many time 2* sum
        int countsumby3=0;
        int count2sumby3=0;
        int s1=0;
        for(int i=0;i<n-1;i++){
            s1+=arr[i];
            
            if(s1==2*sum/3){
                count2sumby3+=countsumby3;
            }
            if(s1==sum/3){
                countsumby3++;
                
            }
        }
        cout<<count2sumby3<<endl;
    }   
    return 0;
}