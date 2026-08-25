class Solution {
public:
    int f(int i,int p,vector<int>&nums, vector<vector<int>>& memo){
        if(i < 0) return 0;
        if(i == 0) return p == 1 ? 0 : nums[0];
        if(memo[i][p] != -1) return memo[i][p];
        
        int take = nums[i] + f(i - 2, p, nums, memo);
        int skip = f(i - 1, p, nums, memo);
        
        return memo[i][p] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> memo1(n, vector<int>(2, -1));
        vector<vector<int>> memo2(n, vector<int>(2, -1));
        // Case 1: Rob houses from index 0 to n-2 (ignore last house)
        int res1 = f(n - 2, 0, nums, memo1);
        // Case 2: Rob houses from index 1 to n-1 (ignore first house)
        int res2 = f(n - 1, 1, nums, memo2);
        return max(res1, res2);
    }
};