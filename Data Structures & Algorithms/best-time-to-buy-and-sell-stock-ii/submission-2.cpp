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
        vector<int> next(2,0);
        vector<int> cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    int p1=-prices[i]+next[0];
                    int p2=next[1];
                    cur[1]=max(p1,p2);
                }
                else{
                    int p1=prices[i]+next[1];
                    int p2=next[0];
                    cur[0]=max(p1,p2);
                }
                next=cur;
            }
        }
        return cur[1];
    }
};