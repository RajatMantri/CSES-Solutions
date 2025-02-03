#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
const int N=1e5+2;
 
class sgTree{
    vector<int> segment;
    public:
        sgTree(int n){
            segment.resize(4*n+1);
        }
 
        void build(int idx,int low,int high,vector<int> &a){
            if(low==high){
                segment[idx]=a[low];
                return;
            }
 
            int mid=(low+high)>>1;
            build(2*idx+1,low,mid,a);
            build(2*idx+2,mid+1,high,a);
 
            segment[idx]=(segment[2*idx+1]+segment[2*idx+2]);
        }
 
        int query(int idx,int low,int high,int l,int r){
            //l r low high   low high  l r
            if(low>r||high<l) return 0;
            //l low high r
            else if(l<=low&&high<=r) return segment[idx];
 
            int mid=(low+high)>>1;
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);
 
            return (left+right);
        }
 
        void update(int idx,int low,int high,int i,int val){
            if(low==high){
                segment[idx]=val;
                return;
            }
 
            int mid=(low+high)>>1;
            if(i<=mid) update(2*idx+1,low,mid,i,val);
            else update(2*idx+2,mid+1,high,i,val);
 
            segment[idx]=(segment[2*idx+1]+segment[2*idx+2]);
        }
 
};
 
vector<pair<int,int>> start_end;
int timer=0;
vector<int> value;
 
void dfs(int node,int par,vector<int> adj[],vector<int>&val){
    start_end[node].first=timer++;
    value.push_back(val[node]);
 
    for(auto&nbr:adj[node]){
        if(nbr!=par) dfs(nbr,node,adj,val);
    }
 
    value.push_back(val[node]);
    start_end[node].second=timer++;
}
 
void solve() {
    int n,q;
    cin >> n>>q;
 
    start_end.resize(n+1);
    
    vector<int> adj[n+1];
 
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
 
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
 
    dfs(1,0,adj,val);
    sgTree s(2*n);
    s.build(0,0,2*n-1,value);
 
    while(q--){
        int t;cin>>t;
        if(t==1){
            int node,val;cin>>node>>val;
            s.update(0,0,2*n-1,start_end[node].first,val);
            s.update(0,0,2*n-1,start_end[node].second,val);
        }
        else{
            int node;cin>>node;
            cout<<s.query(0,0,2*n-1,start_end[node].first,start_end[node].second)/2<<endl;
        }
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}