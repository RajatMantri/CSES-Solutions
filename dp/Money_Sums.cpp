#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
const int N=1e5+1;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    vector<bool> poss(N);
    poss[0]=1;
 
    for(int i=0;i<n;i++){
        for(int x=N-1;x>=a[i];x--){
            poss[x]=poss[x]|poss[x-a[i]];
        }
    }
 
    int ans=0;
    for(int i=1;i<N;i++) if(poss[i]) ans++;
    cout<<ans<<endl;
 
    for(int i=1;i<N;i++){
        if(poss[i]) cout<<i<<" ";
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