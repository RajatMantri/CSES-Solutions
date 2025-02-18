#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
int n;
vector<int> sz;
 
int dfs(int node,int par,vector<int> adj[]){
    int cnt=1;
 
    for(auto&nbr:adj[node]){
        if(par!=nbr){
            cnt+=dfs(nbr,node,adj);
        }
    }
 
    return sz[node]=cnt;
}
 
int f(int node,int par,vector<int> adj[]){
    for(auto&nbr:adj[node]){
        if(par!=nbr){
            if(sz[nbr]>n/2){
                return f(nbr,node,adj);
            }
        }
    }
    return node;
}
 
void solve() {
    cin >> n;
    sz.resize(n+1);
    
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1,0,adj);
 
    cout<<f(1,0,adj);
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}