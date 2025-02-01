#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
const int N= 2e5+10;
 
int par[N][21];
int depth[N];
 
void sparse(int node,int parent,vector<int> adj[]){
    par[node][0]=parent;
    depth[node]=depth[parent]+1;
 
    for(int i=1;i<=20;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
 
    for(auto&i:adj[node]){
        if(i!=parent) sparse(i,node,adj);
    }
}
 
int lca(int u,int v){
    if(u==v) return u;
 
    if(depth[u]>depth[v]) swap(u,v);
 
    int jump=depth[v]-depth[u];
 
    for(int i=20;i>=0;i--){
        if(jump==0) break;
 
        if(jump>=(1<<i)){
            v=par[v][i];
            jump-=(1<<i);
        }
    }
 
    if(u==v) return u;
 
    for(int i=20;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
 
    return par[u][0];
}
 
int dfs(int i,int p,vector<int> adj[],vector<int>& ans){
    int res=ans[i];
 
    for(auto&j:adj[i]){
        if(j!=p) res+=dfs(j,i,adj,ans);
    }
 
    return ans[i]=res;
}
 
void solve() {
    int n,m;
    cin >> n>>m;
    
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    sparse(1,0,adj);
    vector<int> ans(n+1);
    
    while(m--){
        int u,v;cin>>u>>v;
        int l=lca(u,v);
 
        if(u==v){
            ans[u]++;
        }
        else if(u==l||v==l){
            if(u==l) ans[v]++;
            else ans[u]++;
        }
        else{
            ans[u]++;
            ans[v]++;
            ans[l]--;
        }
 
        ans[par[l][0]]--;
    }
 
    dfs(1,0,adj,ans);
 
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}