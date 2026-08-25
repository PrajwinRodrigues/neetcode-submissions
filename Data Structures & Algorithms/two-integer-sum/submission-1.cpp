class Solution {
public:   
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans(2,-1);
        int first;
        for(int i=0;i<nums.size();i++){
            first=nums[i];
            if(m.find(target-first)!=m.end()){
                ans[0]=i;
                ans[1]=m[target-first];
                 sort(ans.begin(),ans.end());
                 return ans;
            }
            else{
                m[first]=i;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
