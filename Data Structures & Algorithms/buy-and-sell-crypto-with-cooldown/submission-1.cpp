class Solution {
public:
    int f(int idx,vector<int> &nums,int buy,vector<vector<int>> &dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int p1=0,p2=0;
        if(buy){
         p1=-nums[idx]+f(idx+1,nums,0,dp);
         p2=f(idx+1,nums,1,dp);
        }
        else{
            p1=nums[idx]+f(idx+2,nums,1,dp);
            p2=f(idx+1,nums,0,dp);
        }
        return dp[idx][buy]=max(p1,p2);
    }
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(2,0));
        int n=nums.size();
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int p1=0,p2=0;
                if(buy){
                    p1=-nums[idx]+dp[idx+1][0];
                    p2=dp[idx+1][1];
                }
                else{
                    p1=nums[idx]+dp[idx+2][1];
                    p2=dp[idx+1][0];
                }
                dp[idx][buy]=max(p1,p2);
            }
        }
        return dp[0][1];
    }
};
