                                                                    /* @Triss */ 
#include "bits/stdc++.h"

using namespace std;

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
 
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vs = vector<string>;
using vc = vector<char>;

#ifdef DEBUG
#include "debug_template.h"
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
const int N=2e5+10;
vector<int>adj[N],rev_adj[N];
vector<bool>used(N);
vector<int>order,component;
vector<int>scc_adj[N];
vector<int>root(N);
vector<int>roots;
void dfs1(int u){
    used[u]=true;
    for(int v:adj[u]){
        if(!used[v])
            dfs1(v);
    }
    order.push_back(u);
}
void dfs2(int u){
    used[u]=true;
    component.push_back(u);
    for(int v:rev_adj[u]){
        if(!used[v])
            dfs2(v);
    }
}
void solve(){
       int n,m;
       cin>>n>>m;
       for(int i=0;i<m;i++){
           int u,v; // u -> v
           adj[u].pb(v);
           rev_adj[v].pb(u);
       }
       fill(all(used),false);
       for(int i=1;i<=n;i++){
           if(!used[i]){
               dfs1(i);
           }
       }
       fill(all(used),false);
       reverse(all(order));
       for(int u:order){
           if(!used[u]){
               dfs2(u);
               //process the component 
               int r=component.front();
               for(int v:component)root[v]=r;
               roots.push_back(r);
           }
           component.clear();
       }
       for(int i=1;i<=n;i++){
           for(int v:adj[i]){
               int r1=root[i];
               int r2=root[v];
               if(r1!=r2){
                   scc_adj[r1].push_back(r2);
               }
           }
       }
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

