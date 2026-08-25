class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>prev(nums.size(),1),next(nums.size(),1);
       int p=1;
       for(int i=0;i<nums.size()-1;i++){
        p*=nums[i];
        prev[i+1]=p;
       }
       p=1;
       for(int i=nums.size()-1;i>0;i--){
         p*=nums[i];
         next[i-1]=p;
       }
       vector<int>ans(nums.size());
       for(int i=0;i<nums.size();i++){
        ans[i]=prev[i]*next[i];
       }
       return ans;
    }
};
