#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

// Algorithm: Segment Tree
// Problem: Range Sum Query - Mutable

/*
 * Problem Link: https://leetcode.com/problems/range-sum-query-mutable/ (LeetCode 307)
 *
 * Description: Implement a Segment Tree for efficient range queries and updates.
 *
 * Practice Questions:
 * 1. Range Minimum Query: https://cp-algorithms.com/data_structures/segment_tree.html#range-minimum-query
 * 2. Count of Range Sum: https://leetcode.com/problems/count-of-range-sum/
 * 3. Parsing A Boolean Expression (Harder application): https://leetcode.com/problems/parsing-a-boolean-expression/
 */

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

int st[4000001];
int arr[1000004];

int lazy[4000004];
int buildtree(int si ,int ss , int se){
    if(ss ==se){
        st[si]=arr[ss];
    }
    int mid = ss+(se-ss)/2;
    buildtree(2*si , ss ,mid);
    buildtree(2*si +1 , mid+1 , se);
    st[si]= st[2*si]+st[2*si+1];
}

//si = segment index , segment start ,segment end  
//qs = query start , query end
    // st[si]= min(st[2*si],st[2*si+1]);
int query1 (int si , int ss ,int se , int qs , int qe){
    if(qs>se || qe < ss){ // when query is completely outside of segment
        return INT_MAX;
    }

    if(qs>=ss && qe<= se){ //when query is completely inside
        return st[si];
    }

    int mid = ss+(se-ss)/2;
    int l = query(2*si , ss ,mid , qs , qe);
    int r = query(2*si+1 , mid ,se, qs , qe);
    
    return  min(l,r);
}
 
// lazy update or lazy propogate  (almost same code as queryupdate)

int query(int si , int ss , int se , int qs ,int qe){
    if(lazy[si]!=0){
        int dx = lazy[si];
        lazy[si]=0; 
        st[si]+=dx*(se-ss+1);
        if(ss!=se){
            lazy[ss*2+1]+=dx;
            lazy[2*ss]+=dx; 
        }

    }
    if(ss>qe || se <qs){
        return 0;
    }
    if(qs<=ss && se<=qe){
        return st[si];
    }
    int mid = (ss+se)/2;
    return query(2*si ,ss ,mid , qs , qe)+query(2*si+1 , mid+1 ,se , qs , qe);
}
//range sum lazzy prop update
void lazyupdate(int si  , int ss ,int se , int qs , int qe , int val){
    if(lazy[si]!=0){
        int dx = lazy[si];
        lazy[si]=0;
        st[si]+=dx*(ss-se+1);

        if(ss!=se){
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }
    if(qs>se || qe<ss)return ;
    if(qs <= ss && qe >= se){
        int dx=(se-ss+1)*val;
        st[si]+=dx;
        if(ss!=se){
            lazy[2*si]+=val;
            lazy[2*si+1]+=val;
        
        }
        return;

    }
    int mid = (ss+se)/2;
    lazyupdate(2*si , ss , mid , qs , qe , val );
    lazyupdate(2*si+1 , mid+1 , se , qs , qe , val);
    st[si] = st[2*si+1]+st[2*si];

}
int update(int si ,int ss , int se , int qi){
    if(ss==se){
        st[si]=arr[ss];
    }
    int mid = (ss+se)/2;
    if(qi<= mid)update(2*si , ss , mid , qi);
    else update(2*si+1 , mid +1 , se , qi);
    st[si]=min(st[2*si],st[2*si+1]);
}


 

void solve_case(){
    
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