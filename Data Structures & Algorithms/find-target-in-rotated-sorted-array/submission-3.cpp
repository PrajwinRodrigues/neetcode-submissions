class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f=0,l=nums.size()-1;
        while(f<=l){
            int mid=f+(l-f)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[f]<=nums[mid]){
                if(target>=nums[f] && target<=nums[mid]){
                    l=mid-1;
                }
                else{
                    f=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[l]){
                    f=mid+1;
                }
                else{
                    l=mid-1;
                }
            }  
        }
        return -1;
    }
};
