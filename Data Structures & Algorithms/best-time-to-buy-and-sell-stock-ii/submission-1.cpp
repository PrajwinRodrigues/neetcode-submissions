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
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    int p1=-prices[i]+dp[i+1][0];
                    int p2=dp[i+1][1];
                    dp[i][j]=max(p1,p2);
                }
                else{
                    int p1=prices[i]+dp[i+1][1];
                    int p2=dp[i+1][0];
                    dp[i][j]=max(p1,p2);
                }
            }
        }
        return dp[0][1];
    }
};