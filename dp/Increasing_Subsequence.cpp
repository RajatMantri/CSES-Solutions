#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    vector<int> temp;
    temp.push_back(a[0]);
 
    for(int i=1;i<n;i++){
        if(temp.back()<a[i]){
            temp.push_back(a[i]);
        }
        else{
            int lb=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
            temp[lb]=a[i];
        }
    }
 
    cout<<temp.size()<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
