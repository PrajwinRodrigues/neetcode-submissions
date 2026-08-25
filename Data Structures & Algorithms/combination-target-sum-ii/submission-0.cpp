class Solution {
public:
    set<vector<int>>s;
    void f(vector<int> &nums,int idx,int tar,vector<int> &temp,vector<vector<int>> &ans){
        if(tar==0){ 
        if(s.find(temp)==s.end()){
        ans.push_back(temp);
        s.insert(temp);
        }
        return;
        }
        if(idx==nums.size() || tar<0) return;
        temp.push_back(nums[idx]);
        f(nums,idx+1,tar-nums[idx],temp,ans);
        temp.pop_back();
        f(nums,idx+1,tar,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates,0,target,temp,ans);
        return ans;
    }
};
