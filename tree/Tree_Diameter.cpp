#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+1;
int dp[N][2];
int depth[N];
 
 
int f(int i,vector<int> adj[],int par){
    int ans=0;
    for(int&j:adj[i]){
        if(j!=par) ans=max(ans,f(j,adj,i));
    }
    depth[i]=ans;
    return ans+1;
}
 
void dfs(int i,vector<int> adj[],int par){
    int h=0,hs=0;
 
    for(int &j:adj[i]){
        if(j!=par){
            if(h<=depth[j]){
                hs=h;
                h=depth[j];
            }
            else if(hs<=depth[j]) hs=depth[j];
        }
    }
 
    // cout<<i<<" "<<h<<" "<<hs<<endl;
 
    int child=0;
 
    for(int &j:adj[i]){
        if(j!=par){
            child++;
            dfs(j,adj,i);
            dp[i][0]=max({dp[i][0],dp[j][0],dp[j][1]});
        }
    }
    
    if(child>=2) dp[i][1]=2+h+hs;
    else if(child==1) dp[i][1]=1+h;
    
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
 
    memset(dp,0,sizeof(dp));
 
    f(1,adj,-1);
 
    dfs(1,adj,-1);
    //for(int i=1;i<=n;i++) cout<<i<<" "<<depth[i]<<'\n';
    //for(int i=1;i<=n;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
 
    cout<<max(dp[1][0],dp[1][1]);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}