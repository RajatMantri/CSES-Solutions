#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
void solve() {
    int n,q;
    cin >> n>>q;
 
    int child[n+1][30];
 
    for(int i=1;i<=n;i++){
        cin>>child[i][0];
    }
 
    for(int lev=1;lev<30;lev++){
        for(int i=1;i<=n;i++){
            child[i][lev]=child[child[i][lev-1]][lev-1];
        }
    }
 
   
    while(q--){
        int node,k;cin>>node>>k;
        for(int i=29;i>=0;i--){
            if(k==0) break;
 
            if((1<<i)<=k){
                k-=(1<<i);
                node=child[node][i];
            }
        }
 
        cout<<node<<"\n";
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