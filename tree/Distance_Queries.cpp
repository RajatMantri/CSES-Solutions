#include<bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int depth[N];
int par[N][21];
 
void sparseTable(vector<int> adj[],int node,int parent){
    par[node][0]=parent;
    depth[node]=depth[parent]+1;
    for(int i=1;i<21;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
    for(auto&j:adj[node]){
        if(j!=parent) sparseTable(adj,j,node);
    }
}
 
void solve() {
    int n,q;
    cin >> n>>q;
 
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    sparseTable(adj,1,0);
    while(q--){
        int u,v;cin>>u>>v;
        int x=u,y=v;
 
        if(depth[u]>depth[v]) swap(u,v);
        int jump=depth[v]-depth[u];
 
        for(int i=20;i>=0;i--){
            if(jump==0) break;
 
            if(jump>=(1<<i)){
                jump-=1<<i;
                v=par[v][i];
            }
        }
 
        if(u==v){
            cout<<depth[x]+depth[y]-2*depth[u]<<endl;
            continue;
        }
 
        for(int i=20;i>=0;i--){
            if(par[u][i]!=par[v][i]){
                u=par[u][i];
                v=par[v][i];
            }
        }
        u=par[u][0];
        cout<<depth[x]+depth[y]-2*depth[u]<<endl;
    }
}
 
//rbegin() rend()
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    clock_t z = clock();
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
    return 0;
}