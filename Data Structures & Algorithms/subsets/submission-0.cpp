class Solution {
public:
    void f(vector<int> &nums,int i,vector<int> &ans,vector<vector<int>> &fin){
        if(i==nums.size()){
            fin.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        f(nums,i+1,ans,fin);
        ans.pop_back();
        f(nums,i+1,ans,fin);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        f(nums,0,temp,ans);
        return ans;
    }
};
