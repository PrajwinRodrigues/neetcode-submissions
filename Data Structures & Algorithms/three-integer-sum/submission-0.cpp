class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int j,k,sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j+=1;
                }
                else if(sum>0){
                   k-=1;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j+=1;
                    k-=1;
                    while(j<k && nums[j]==nums[j-1]) j+=1;
                    while(k>j && nums[k]==nums[k+1]) k-=1;
                }
            }
        }
        return ans;
    }
};
