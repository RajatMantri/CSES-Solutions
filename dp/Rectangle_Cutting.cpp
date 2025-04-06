#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod = 1e9 + 7;
 
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
 
vector<vector<int>> dp(501,vector<int>(501,0));
 
//rbegin()
int main(){
    int a,b;
    cin>>a>>b;
    
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i!=j){
                int ways=INT_MAX;
                for(int p=1;p<i;p++){
                    ways=min(ways,1+dp[i-p][j]+dp[p][j]);
                }
                for(int p=1;p<j;p++){
                    ways=min(ways,1+dp[i][j-p]+dp[i][p]);
                }
                dp[i][j]=ways;
            }
        }
    }
 
    cout<<dp[a][b];
}