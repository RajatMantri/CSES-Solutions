#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
int n,m;
int dp[(1<<10)][1001];
 
void gen(int mask,int i,vector<int>&next_mask,int curr_mask){
    if(i==n){
        next_mask.push_back(curr_mask);
        return;
    }
 
 
    if(!(mask&(1<<i))) gen(mask,i+1,next_mask,curr_mask|(1<<i));
    else gen(mask,i+1,next_mask,curr_mask);
    
    if(i<=n-2){
        if(!(mask&(1<<i))&&!(mask&(1<<(i+1)))){
            gen(mask,i+2,next_mask,curr_mask);
        }
    }
}
 
int f(int i,int mask){
    if(i==m){
        if(mask==0) return 1;
        else return 0;
    }
 
    if(dp[mask][i]!=-1) return dp[mask][i];
    
    int ans=0;
    vector<int> next_mask;
    gen(mask,0,next_mask,0);
 
    for(auto&j:next_mask){
        ans+=f(i+1,j)%mod;
    }
 
    return dp[mask][i]=ans%mod;
}
 
void solve() {
    cin >> n>>m; 
    memset(dp,-1,sizeof(dp));
    cout<<f(0,0)%mod;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}