#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
//rbegin()
int main(){
    int n,m;
    cin>>n>>m;
 
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
 
    ll ans=0;
 
    if(n==1){
        if(a[0]==0) cout<<m;
        else cout<<1;
        return 0;
    }
    
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    for(int i=0;i<n;i++){
        if(i==0){
            if(a[i]==0){
                for(int j=1;j<=m;j++) dp[i][j]=1;
            }
            else{
                dp[i][a[i]]=1;
            }
            continue;
        }
        if(a[i]!=0){
            dp[i][a[i]]=dp[i-1][a[i]];
            if(a[i]>1) dp[i][a[i]]+=dp[i-1][a[i]-1];
            if(a[i]<m) dp[i][a[i]]+=dp[i-1][a[i]+1];
            dp[i][a[i]]%=mod;
            if(i==n-1) ans=dp[i][a[i]];
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if(j>1) dp[i][j]+=dp[i-1][j-1];
                if(j<m) dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
                if(i==n-1) ans=(ans+dp[i][j])%mod;
            }
        }
    }
 
    cout<<ans;
}