#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
//rbegin()
int main(){
    int n,x;cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    sort(c.begin(),c.end());
 
    vector<ll> dp(x+1,0);
    dp[0]=1;
 
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i<c[j]) break;
            dp[i]+=dp[i-c[j]];
        }
        dp[i]%=mod;
    }
 
    cout<<dp[x];
}