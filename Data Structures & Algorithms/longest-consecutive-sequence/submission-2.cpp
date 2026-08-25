class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int maxl=1;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int j=1;
                int l=1;
                while(s.find(nums[i]+j)!=s.end()){
                  l+=1;
                  j+=1;
                  maxl=max(maxl,l);
                }
            }
        }
        return maxl;
    }
};
