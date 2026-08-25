class Solution {
public:
    int f(int i,vector<int> &cost,vector<int>&dp){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int p1=cost[i]+f(i+1,cost,dp);
        int p2=cost[i]+f(i+2,cost,dp);
        return dp[i]=min(p1,p2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(f(0,cost,dp),f(1,cost,dp));
    }
};
