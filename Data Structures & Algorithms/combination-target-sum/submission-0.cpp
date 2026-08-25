class Solution {
public:
    set<vector<int>>s;
    void f(int i,int tar,vector<int> &nums,vector<int> &temp,vector<vector<int>> &fin){
        if(i==nums.size() || tar<0){
            if(tar==0){
                if(s.find(temp)==s.end()){
                fin.push_back(temp);
                s.insert(temp);
                }
            }
            return;
        }
        if(tar==0){
            if(s.find(temp)==s.end()){
            fin.push_back(temp);
            s.insert(temp);
            return;
        }
        }
        temp.push_back(nums[i]);
        f(i+1,tar-nums[i],nums,temp,fin);
        f(i,tar-nums[i],nums,temp,fin);
        temp.pop_back();
        f(i+1,tar,nums,temp,fin);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,target,nums,temp,ans);
        return ans;
    }
};
