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
 
void solve(){
      int n,m;
      cin>>n>>m;
      vector<int>adj[n+1];
      for(int i=0;i<m;i++){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
      }
      vi color(n+1,0),h(n+1),d(n+1),mark(n+1,0);
      vi p(n+1);
      p[1]=0,h[0]=0,d[0]=0;
      function<void(int)>dfs=[&](int u){
          color[u]=1;
           for(int v:adj[u]){
               if(color[v]==0){
                    h[v]=1+h[u];
                    d[v]=h[v];
                    p[v]=u;
                    dfs(v);
                    d[u]=min(d[u],d[v]);
                    if(h[u]<=d[v] and (!p[u] or sz(adj[u])>0)){
                        mark[u]=1;
                    }
               }
               else if(v!=p[u]){
                   d[u]=min(d[u],h[v]);
               }
           }
           color[u]=2;
      };
      dfs(1);
      for(int i=1;i<=n;i++){
          if(mark[i])cout<<i<<" ";
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

