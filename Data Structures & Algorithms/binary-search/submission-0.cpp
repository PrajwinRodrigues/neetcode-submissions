class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f=0,l=nums.size()-1;
        while(f<=l){
            int m=f+(l-f)/2;
            if(nums[m]==target){
                return m;
            }
            else if(target>nums[m]){
                f=m+1;
            }
            else{
                l=m-1;
            }
        }
        return -1;
    }
};
