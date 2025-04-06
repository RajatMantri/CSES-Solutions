#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const int N=1e6+10;
vector<ll> ways(N,0);
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
//rbegin()
int main(){
    int n;cin>>n;
    ways[0]=0;
    for(int i=1;i<=n;i++){
        if(i<=6) ways[i]++;
        for(int j=i-1;j>=max(0,i-6);j--){
            ways[i]+=ways[j];
        }
        ways[i]%=mod;
    }
 
    cout<<ways[n];
}