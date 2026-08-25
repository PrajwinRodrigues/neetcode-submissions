class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[0];
        if(i==1) return nums[1];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0;
        for(int idx=i-2;idx>=0;idx--){
            maxi=max(maxi,nums[i]+f(idx,nums,dp));
        }
        return dp[i]=maxi;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans=max(ans,f(i,nums,dp));
        }
        return ans;
    }
};
