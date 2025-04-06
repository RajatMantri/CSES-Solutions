#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
const int N=1e6+1;
vector<vector<int>> res(N,vector<int>(2));
 
void solve() {
    int n;
    cin >> n;
    
    cout<<(res[n][0]+res[n][1])%mod<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    res[1][0]=1,res[1][1]=1;
    for(int i=2;i<N;i++){
        res[i][0]=(2*res[i-1][0]+res[i-1][1])%mod;
        res[i][1]=(res[i-1][0]+4*res[i-1][1])%mod;
    }
    while (t--) solve();
    return 0;
}