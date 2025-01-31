#include<bits/stdc++.h>
using namespace std;
 
vector<int> d(2*1e5+1);
 
int dfs(int i,vector<int> adj[],vector<int>&vis){
    vis[i]=1;
    int c=0;
 
    for(auto&j:adj[i]){
        if(!vis[j]) c+=dfs(j,adj,vis);
    }
 
    d[i]=c;
 
    return c+1;
}
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
 
    vector<int> vis(n+1);
    dfs(1,adj,vis);
 
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}