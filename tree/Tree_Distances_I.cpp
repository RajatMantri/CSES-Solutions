#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+1;
int dp[N];
int depth[N];
 
 
int f(int i,vector<int> adj[],int par){
    int ans=0;
    for(int&j:adj[i]){
        if(j!=par) ans=max(ans,f(j,adj,i));
    }
    depth[i]=ans;
    return ans+1;
}
 
void dfs(int n,vector<int> adj[],int par,int par_i){
    vector<int> prefix;
    vector<int> suffix;
 
    for(auto&j:adj[n]){
        if(j!=par){
            prefix.push_back(depth[j]);
            suffix.push_back(depth[j]);
        }
    }
 
    int len=prefix.size();
    for(int i=1;i<len;i++) prefix[i]=max(prefix[i],prefix[i-1]);
    for(int i=len-2;i>=0;i--) suffix[i]=max(suffix[i],suffix[i+1]);
 
    if(len!=0) dp[n]=1+prefix[len-1];
    dp[n]=max(1+par_i,dp[n]);
 
    int cnt=0;
    for(auto&j:adj[n]){
        if(par!=j){
            int p=-1,s=-1;
            if(cnt!=0) p=prefix[cnt-1]; 
            if(cnt!=len-1) s=suffix[cnt+1];
 
            int curr_par_i=1+max({p,s,par_i});
            dfs(j,adj,n,curr_par_i);
 
            cnt++;
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    f(1,adj,-1);
    dfs(1,adj,0,-1);
    //for(int i=1;i<=n;i++) cout<<depth[i]<<" ";
    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}