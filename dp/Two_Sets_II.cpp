#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
ll power(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(a*res)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}
 
void solve() {
    int n;
    cin >> n;
 
    int x=n*(n+1)/2;
 
    if(x&1){
        cout<<0<<endl;
        return;
    }
 
    x/=2;
    
    vector<int> poss(x+1);
    poss[0]=1;
 
    for(int i=1;i<=n;i++){
        for(int j=x;j>=i;j--){
            poss[j]=(poss[j]+poss[j-i])%mod;
        }
    }
 
    cout<<poss[x]*(power(2,mod-2))%mod<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
