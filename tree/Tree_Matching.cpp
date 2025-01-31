#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+1;
vector<int> p(N);
int dp[N][2];
 
int dfs(int i,bool chose,vector<int> adj[],int par){
    int ans=0;
    int sum=0;
 
    if(dp[i][chose]!=-1) return dp[i][chose];
 
    for(auto&j:adj[i]){
        if(j!=par){
            if(chose){
                p[j]=max(dfs(j,1,adj,i),dfs(j,0,adj,i));
                sum+=p[j];
            }
            else{
                ans+=max(dfs(j,0,adj,i),dfs(j,1,adj,i));
            }
        }
    }
 
    if(chose){
        for(auto&j:adj[i]){
            if(j!=par){
                ans=max(ans,1+sum-p[j]+dfs(j,0,adj,i));
            }
        }
    }
 
    return dp[i][chose]=ans;
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
 
    memset(dp,-1,sizeof(dp));
 
    cout<<max(dfs(1,0,adj,-1),dfs(1,1,adj,-1));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}