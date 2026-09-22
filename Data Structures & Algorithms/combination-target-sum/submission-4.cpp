class Solution {
public:
    void f(int idx,vector<int> &temp,vector<vector<int>> &ans,int tar,vector<int> &nums){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(tar<0) return;
        if(idx==nums.size()) return;
        temp.push_back(nums[idx]);
        f(idx,temp,ans,tar-nums[idx],nums);
        temp.pop_back();
        f(idx+1,temp,ans,tar,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,temp,ans,target,nums);
        return ans;
    }
};
