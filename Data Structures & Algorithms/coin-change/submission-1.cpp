class Solution {
public:
    int f(int i,int amt,vector<int> &nums,vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(amt<0) return INT_MAX;
        if(i<0) return INT_MAX;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int p=0,np=0;
        p=f(i,amt-nums[i],nums,dp);
        np=f(i-1,amt,nums,dp);
        if(p==INT_MAX) return dp[i][amt]=np;
        else return dp[i][amt]=min(p+1,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
        for(int i=0;i<coins.size();i++) dp[i][0]=0;
        for(int i=0;i<coins.size();i++){
           for(int amt=1;amt<=amount;amt++){
            int p=1e9,np=1e9;
            if(coins[i]<=amt){
                p=1+dp[i][amt-coins[i]];
            }
            if(i>0)
            np=dp[i-1][amt];
            dp[i][amt]=min(p,np);
           }
        }
        return dp[coins.size()-1][amount]==1e9?-1:dp[coins.size()-1][amount];
    }
};
