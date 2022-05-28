// Leetcode : 53 Maximum Subarray

// Kadane algorithm
class Solution {
public:

	int maxSubArray(vector<int> &nums) {
        int currSum = 0;
        int maxSofar =0;
        int flag =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>=0) flag=1;
            currSum+=nums[i];
            if(currSum<0) currSum =0;
            maxSofar = max(currSum,maxSofar);
        }
        if(flag==0){
            int maxSofar = INT_MIN;
            for(auto x:nums){
                maxSofar = max(maxSofar,x);
            }
            return maxSofar;
        }
        return maxSofar;
    }
};

//  DP bottom up approach
 
class Solution {
public:

	int maxSubArray(vector<int> &nums) {
        int dp[100001];
        int maxSofar =nums[0];
        dp[0]= nums[0]>0?nums[0]:0;
        int flag =0;
        for(int i =1;i<nums.size();i++){
            if(nums[i]>=0) flag=1;
            dp[i] = dp[i-1]+nums[i];
            if(dp[i]<0) dp[i] =0;
            maxSofar = max(dp[i],maxSofar);
        }
        if(flag==0){
            int maxSofar = INT_MIN;
            for(auto x:nums){
                maxSofar = max(maxSofar,x);
            }
            return maxSofar;
        }

        return maxSofar;
    }
};
