#include<iostream>                                      /*Krish Sharma*/
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<cstring>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>                   
// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define pyes cout << "Yes" << "\n";
#define pno cout << "No" << "\n";
#define br cout << "\n";
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define sz(x) ((long long)(x).size())
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define mod 1000000007
#define modd 998244353
#define inf 9223372036854775807
#define all(x) (x).begin(),(x).end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vs = vector<string>;
using vc = vector<char>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
struct item{
    int m,c;
};
struct segtree{
    int size;
    vector<item>values;
     item neutral={INT_MAX,0};
     item merge(item a,item b){
         if(a.m<b.m)return a;
         if(a.m>b.m)return b;
         return {a.m,a.c+b.c};
     }

     void init(int n){
         size=1;
         while(size < n)size*=2;
         values.resize(2*size);
     }
     
     void build(vector<int> &a,int x,int lx,int rx){
         if(lx==rx){
             if(lx<(int)a.size())
                 values[x]={a[lx],1};
            return;
         }
         int mx=(lx+rx)/2;
         build(a,2*x,lx,mx);
         build(a,2*x+1,mx+1,rx);
         values[x]=merge(values[2*x],values[2*x+1]);
     }
     void build(vector<int>&a){
         int n=sz(a);
         build(a,1,0,n-1);
     }
     void set(int i,int v,int x,int lx,int rx){
         if(lx==rx){
             values[x]={v,1};
             return;
         }
         int mx=(lx+rx)/2;
         if(i<=mx)set(i,v,2*x,lx,mx);
         else set(i,v,2*x+1,mx+1,rx);
         values[x]=merge(values[2*x],values[2*x+1]);
     }
     void set(int i,int v,int n){
         set(i,v,1,0,n-1);
     }
     item calc(int l,int r,int x,int lx,int rx){
         if(lx>r || l>rx)return neutral; 
         if(lx>=l && rx<=r)return values[x];
         int mx=(lx+rx)/2;
         item s1=calc(l,r,2*x,lx,mx);
         item s2=calc(l,r,2*x+1,mx+1,rx);
         return merge(s1,s2);
     }
     item calc(int l,int r,int n){
         return calc(l,r,1,0,n-1);
     }
};
void solve(){
      
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t; 
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}

