class Solution {
public:
    int findMin(vector<int> &nums) {
        int f=0,l=nums.size()-1;
        int mid;
        int ans=1e9;
        while(f<=l){
            mid=f+(l-f)/2;
            ans=min(ans,nums[mid]);
            if(nums[f]<=nums[mid]){
                ans=min(ans,nums[f]);
                f=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                l=mid-1;
            }
        }
        return ans;
    }
};
