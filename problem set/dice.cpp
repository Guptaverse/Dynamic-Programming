#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long 
using namespace std;
// const int N = 1000001;
// int dp[N];
void solver(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=6&&i-j>=0;j++){
           (dp[i] += dp[i-j]) %= mod;
        }
    }
    cout<<dp[n]<<endl;
 
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
