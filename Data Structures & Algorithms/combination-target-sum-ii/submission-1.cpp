class Solution {
public:
    void f(int idx,vector<int> &temp,vector<vector<int>> &ans,vector<int> &nums,int tar){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=nums.size()) return;
        if(tar<0) return;
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>tar) break;
            temp.push_back(nums[i]);
            f(i+1,temp,ans,nums,tar-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(0,temp,ans,candidates,target);
        return ans;
    }
};
