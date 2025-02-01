#include<bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int depth[N];
int par[N][21];
 
void sparseTable(vector<int> adj[],int node,int parent){
    par[node][0]=parent;
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
        int u;
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
 
    sparseTable(adj,1,0);
    while(q--){
        int u,k;cin>>u>>k;
 
        for(int i=20;i>=0;i--){
            if(k==0) break;
 
            if(k>=(1<<i)){
                k-=1<<i;
                u=par[u][i];
            }
        }
        if(u==0) u=-1;
        cout<<u<<endl;
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