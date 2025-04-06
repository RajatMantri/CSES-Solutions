#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
int dp[5001][5001][2];
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    int sum=0;
 
    for(int i=0;i<n;i++){
        dp[i][i][0]=a[i];
        dp[i][i][1]=0;
 
        sum+=a[i];
    }
 
    for(int diff=1;diff<n;diff++){
        for(int i=0;i+diff<n;i++){
            int j=i+diff;
 
            dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
            dp[i][j][1]=min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }
 
    cout<<dp[0][n-1][0]<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}