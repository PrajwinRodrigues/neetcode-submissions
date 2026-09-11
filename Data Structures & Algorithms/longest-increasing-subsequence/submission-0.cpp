class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(nums[i]);
                continue;
            }
            if(ans.back()>=nums[i]){
                int lb=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[lb]=nums[i];
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans.size();
    }
};
