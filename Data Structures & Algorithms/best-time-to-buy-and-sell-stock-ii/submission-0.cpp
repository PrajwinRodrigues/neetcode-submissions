class Solution {
public:
    int f(int idx,int buy,vector<int> &nums,vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            int p1=-nums[idx]+f(idx+1,0,nums,dp);
            int p2=f(idx+1,buy,nums,dp);
            return dp[idx][buy]=max(p1,p2);
        }
        else{
            int p1=nums[idx]+f(idx+1,1,nums,dp);
            int p2=f(idx+1,0,nums,dp);
            return dp[idx][buy]=max(p1,p2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};