#include<bits/stdc++.h>
using namespace std;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
vector<int> c;
vector<int> p;
vector<vector<int>> dp;
 
int main(){
    int n,x;
    cin>>n>>x;
 
    c.resize(n),p.resize(n);
 
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
 
    for(int i=0;i<n;i++) cin>>p[i];
 
    vector<int> prev(x+1);
 
    for(int i=n-1;i>=0;i--){
        for(int rem=x;rem>=c[i];rem--){
            int pick=p[i]+prev[rem-c[i]];
            int notp=prev[rem];
 
            prev[rem]=max(pick,notp);
        }
    }
 
    cout<<prev[x];
}