#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll dp[20][2][11];
 
ll f(int n,bool tight,int prev,string &r){
    if(n==0) return 1;
 
    if(dp[n][tight][prev]!=-1) return dp[n][tight][prev];
 
    int ub=9;
    if(tight) ub=r[r.length()-n]-'0';
 
    ll ans=0;
 
    for(int i=0;i<=ub;i++){
        if(i!=0&&i!=prev) ans+=f(n-1,tight&(ub==i),i,r);
        else if(i==0){
            if(prev==10) ans+=f(n-1,tight&(ub==i),10,r);
            else if(prev!=i) ans+=f(n-1,tight&(ub==i),0,r);
        }
    }
    
    return dp[n][tight][prev]=ans;
}
 
void solve() {
    ll p,q;cin>>p>>q;
    ll x=0;
 
    string r=to_string(q);
 
    if(p!=0){
        p--;
        string l=to_string(p);
        memset(dp,-1,sizeof(dp));
        x=f(l.length(),1,10,l);
    }
   
    memset(dp,-1,sizeof(dp));
    ll y=f(r.length(),1,10,r);
 
    cout<<(y-x)<<endl;
}
 
int main()
{       
    ll t = 1;
    
    while (t--) solve();
 
    return 0;
}