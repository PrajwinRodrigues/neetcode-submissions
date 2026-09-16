class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxInd=max(i+nums[i],maxInd);
            if(maxInd>=n-1) return 1;
            if(maxInd<=i) return 0;
        }
        return maxInd>=n-1;
    }
};
