 #include<iostream>
 using namespace std;

//Recursive 

 int ladders_recursive(int n,int k ){
     if(n==0) return 1;
     int ways =0;
     for(int i =1;i<=k;i++){
         if(n-i>=0){
             ways+= ladders_recursive(n-i,k);
         }
     }
     return ways;
 }

// Top down : TC : O(NK) : SC : O(N)

 int ladders_topdown(int n,int k ,int dp[]){
     if(n==0) return 1;

     // look up
     if(dp[n]!=0) return dp[n];
     int ways =0;
     for(int i =1;i<=k;i++){
         if(n-i>=0){
             ways+= ladders_topdown(n-i,k,dp);
         }
     }
     return dp[n]= ways;
 }

 // Bottom up : same
 int ladders_BU(int n, int k){
     int dp[100] = {0};
     dp[0]=1;
     for(int i =1;i<=n;i++){
         dp[i]=0;
         for(int j =1;j<=k;j++){
             if(i-j>=0)
                dp[i]+=dp[i-j];
         }
     }
     return dp[n];
 }

 //Optimised : TC : O(N)
 int ladders_opt(int n,int k){
     int dp[100]={0};
     dp[0]=dp[1]=1;
     for(int i =2;i<=k;i++){
         dp[i]= 2* dp[i-1];
     }
     for(int i = k+1;i<=n;i++){
         dp[i] = 2*dp[i-1]-dp[i-k-1];
     }
    return dp[n];
 }


 int main(){
     int n,k;
     cin>>n>>k;
     int dp[100] = {0};
    //  memset(dp,0,sizeof(dp));
    //  cout<<ladders_topdown(n,k,dp)<<endl;
    //  cout<<ladders_BU(n,k)<<endl;
    cout<<ladders_opt(n,k)<<endl;
     return 0;
 }