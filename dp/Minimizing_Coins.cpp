#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
void solve() {
    int n,k;
    cin >> n>>k;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    int prev[k+1];
    
    for(int sum=0;sum<=k;sum++) prev[sum]=1e18;
 
    prev[0]=0;
 
    for(int sum=1;sum<=k;sum++){
        if(sum>=a[0]) prev[sum]=prev[sum-a[0]]+1;
    }
 
    for(int i=1;i<n;i++){
        for(int sum=a[i];sum<=k;sum++){
            prev[sum]=min(prev[sum-a[i]]+1,prev[sum]);
        }
    }
 
    if(prev[k]==1e18) prev[k]=-1;
 
    cout<<prev[k]<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}