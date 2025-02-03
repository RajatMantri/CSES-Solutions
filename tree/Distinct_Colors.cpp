#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
vector<int> ans;
 
set<int> dfs(int node,int par,vector<int> adj[],vector<int>& val){
    set<int> curr;
    curr.insert(val[node]);
 
    for(auto&nbr:adj[node]){
        if(par!=nbr){
            set<int> child=dfs(nbr,node,adj,val);
            if(child.size()>curr.size()) swap(child,curr);
            for(auto&j:child) curr.insert(j);
        }
    }
 
    ans[node]=curr.size();
 
    return curr;
}
 
void solve() {
    int n;
    cin >> n;
 
    ans.resize(n+1);
    
    vector<int> adj[n+1];
 
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
 
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
 
    dfs(1,0,adj,val);
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
