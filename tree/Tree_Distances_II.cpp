#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N=2e5+1;
int dp[N];
int child[N];
int ans[N];
int total=0;
 
 
int f(int i,vector<int> adj[],int par){
    int c=1;
    int ans=0;
    for(auto&j:adj[i]){
        if(j!=par){
            ans+=f(j,adj,i)+child[j];
            c+=child[j];
        }
    }
    child[i]=c;
    dp[i]=ans;
    return ans;
}
 
void dfs(int n,vector<int> adj[],int par,int par_i){
    ans[n]=dp[n]+par_i+total-child[n];
 
    for(auto&j:adj[n]){
        if(j!=par){
            dfs(j,adj,n,ans[n]-dp[j]-child[j]);
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    total=n;
    
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    f(1,adj,-1);
    dfs(1,adj,0,0);
 
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}