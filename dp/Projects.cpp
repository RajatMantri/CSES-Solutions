#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
#define ff first
#define ss second
 
vector<ll> dp;
 
ll f(vector<pair<pair<int,int>,ll>> &p,int i){
    int n=p.size();
    if(i==n) return 0;
 
    if(dp[i]!=-1) return dp[i];
 
    int ans=n,l=i+1,r=n-1;
 
    while(l<=r){
        int mid=(l+r)/2;
        if(p[mid].ff.ff>p[i].ff.ss){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
 
    return dp[i]=max(f(p,i+1),p[i].ss+f(p,ans));
}
 
int main(){
    int n;
    cin>>n;
 
    vector<pair<pair<int,int>,ll>> p(n);
 
    dp.resize(n,-1);
 
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        p[i].ff.ff=a;
        p[i].ff.ss=b;
        p[i].ss=c;
    }
 
    sort(p.begin(),p.end());
 
    cout<<f(p,0);
}