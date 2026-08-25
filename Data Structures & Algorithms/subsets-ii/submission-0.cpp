class Solution {
public:
    set<vector<int>>s;
    void f(vector<int> &nums,int idx,vector<int> &ans,vector<vector<int>> &fin){
        if(idx==nums.size()){
            if(s.find(ans)==s.end()){
            fin.push_back(ans);
            s.insert(ans);
            }
            return;
        }
        ans.push_back(nums[idx]);
        f(nums,idx+1,ans,fin);
        ans.pop_back();
        f(nums,idx+1,ans,fin);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<vector<int>> fin;
        int idx=0;
        f(nums,idx,ans,fin);
        return fin;
    }
};
