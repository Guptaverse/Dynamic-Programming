/*
Ques on LC : https://leetcode.com/problems/house-robber/
*/

class Solution {
public:
    int recursive(vector<int>& nums,int idx){
        if(idx>=nums.size()) return 0;
        int res1 = recursive(nums,idx+2)+nums[idx];
        int res2 = recursive(nums,idx+1);
        return  max(res1,res2);
    }
    int rob(vector<int>& nums) {
        //<--------------Recursive: TLE-------->

        // if (nums.size()==1) return nums[0];
        // return recursive(nums,0);
        
        //<-----------------DP------------------>
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};