#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
//rbegin()
int main(){
    int n;cin>>n;
 
    vector<vector<char>> f(n,vector<char>(n));
    vector<vector<ll>> dp(n,vector<ll>(n));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>f[i][j];
        }
    }
 
    if(f[0][0]!='*') dp[0][0]=1;
    else{
        cout<<0;
        return 0;
    }
 
    for(int i=1;i<n;i++) if(f[i][0]!='*') dp[i][0]=dp[i-1][0];
    for(int i=1;i<n;i++) if(f[0][i]!='*') dp[0][i]=dp[0][i-1];
 
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(f[i][j]=='*') continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    
    cout<<dp[n-1][n-1];
}