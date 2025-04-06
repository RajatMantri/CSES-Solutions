#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
vector<vector<int>> dp;
 
int f(string&a,string&b,int i,int j){
    if(j<0&&i<0) return 0;
    if(j<0) return i+1;
    if(i<0) return j+1;
 
    if(dp[i][j]!=-1) return dp[i][j];
 
    if(a[i]==b[j]){
        return dp[i][j]=f(a,b,i-1,j-1);
    }
    else{
        //replace add erase
        return dp[i][j]=(min({f(a,b,i-1,j-1),f(a,b,i,j-1),f(a,b,i-1,j)})+1);
    }
}
 
//rbegin()
int main(){
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    dp.resize(n,vector<int>(m,-1));
 
    cout<<f(a,b,n-1,m-1);
}