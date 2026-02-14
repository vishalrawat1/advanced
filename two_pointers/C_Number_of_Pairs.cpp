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

void solve_case() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long count = 0;

    for (int i = 0; i < n; i++) {

        int left = -1;   
        int right = -1;  
        int low = l - arr[i];
        int high = r - arr[i];
        int start = i + 1;
        int end = n ;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= high) {
                left = mid;
                start = mid + 1;
            } else {
                end = mid ;
            }
        }
        start = i + 1;
        end = n ;

        while (start <end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= low) {
                right = mid;
                end = mid ;
            } else {
                start = mid+1 ;
            }
        }

        if (left != -1 && right != -1 && right <= left)
            count += (left - right + 1);   // FIXED
    }

    cout << count << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve_case();
    }
    return 0;
}