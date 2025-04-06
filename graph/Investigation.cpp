#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
void solve() {
    int n,m;
    cin >> n>>m;
    
    vector<pair<int,int>> adj[n+1];
    vector<pair<int,int>> rev[n+1];
 
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
 
    vector<int> d(n+1,1e15);
    d[1]=0;
 
    set<pair<int,int>> s;
    s.insert({0,1});
 
    vector<int> ways(n+1);
    vector<int> mini(n+1,1e9);
    vector<int> maxi(n+1);
    ways[1]=mini[1]=maxi[1]=1;
 
    while(!s.empty()){
        auto it=s.begin();
        int node=it->second;
        int dist=it->first;
        s.erase(it);
 
        for(auto&j:adj[node]){
            int nbr=j.first,wt=j.second;
            if(dist+wt<d[nbr]){
                if(s.count({d[nbr],nbr})) s.erase({d[nbr],nbr});
                d[nbr]=dist+wt;
                s.insert({d[nbr],nbr});
                ways[nbr]=ways[node];
                maxi[nbr]=maxi[node]+1;
                mini[nbr]=mini[node]+1;
            }
            else if(dist+wt==d[nbr]){
                ways[nbr]=(ways[nbr]+ways[node])%mod;
                maxi[nbr]=max(maxi[nbr],maxi[node]+1);
                mini[nbr]=min(mini[nbr],mini[node]+1);
            }
        }
    }
 
    cout<<d[n]<<" "<<ways[n]<<" "<<mini[n]-1<<" "<<maxi[n]-1<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}