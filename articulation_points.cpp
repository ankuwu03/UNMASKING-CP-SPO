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
      //tin - time of discovery of node during dfs
      //low - storing minimum discovery among all of one's adjacents but not including parent and already visited nodes (note in bridges we didnt consider only parent)
      vector<int>tin(n+1),low(n+1),vis(n+1,0);
      vector<int>mark(n+1,0);
      int timer=0;
      function<void(int,int)>dfs=[&](int u,int p){
              vis[u]=1;
              low[u]=tin[u]=timer++;
              int child=0;
              for(int v:adj[u]){
                  if(v==p)continue;
                  child++;
                  if(!vis[v]){
                      dfs(v,u);
                      low[u]=min(low[v],low[u]);
                      if(low[v]>=low[u] && !p){
                          mark[u]=1;
                      }
                  }
                  else{
                      low[u]=min(low[u],tin[v]);
                  }
              }
           if(child>0 && !p){
               mark[u]=1;
           }
      };
      for(int i=1;i<=n;i++){
          if(!vis[i]){
              dfs(i,0);
          }
      }
      for(int i=1;i<=n;i++){
          if(mark[i]){
              cout<<i<<" ";
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

