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
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,1,dp);
    }
};
