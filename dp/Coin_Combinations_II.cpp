#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
 
//rbegin()
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    vector<int> dp(x+1);
    for(int i=0;i<n;i++) cin>>c[i];
 
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        for(int val=c[i];val<=x;val++){
            dp[val]=(dp[val]+dp[val-c[i]])%mod;
        }
    }
 
    cout<<dp[x];
}