#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
void solve() {
    int n;
    cin >> n;
    
    int dp[n+1];
    if(n<10) cout<<1<<endl;
    else{
        dp[0]=0;
        for(int i=1;i<=9;i++) dp[i]=1;
 
        for(int i=10;i<=n;i++){
            int x=i;
            dp[i]=1e9;
 
            while(x){
                int d=x%10;
                dp[i]=min(dp[i],dp[i-d]+1);
                x/=10;
            }
        }
 
        cout<<dp[n];
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