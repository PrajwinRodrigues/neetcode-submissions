class Solution {
public:
    bool can(vector<int> &nums,int k,int h){
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(cur>h) return false;
            if(nums[i]<=k){
                cur+=1;
            }
            else{
                cur+=(ceil((double)nums[i]/(double)k));
            }
        }
        return cur>h?false:true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int l=1;
      int r=INT_MIN;
      for(int i=0;i<piles.size();i++){
        r=max(r,piles[i]);
        l=min(l,piles[i]);
      }
      int ans=0;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(can(piles,mid,h)){
           ans=mid;
           r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      return ans;  

    }
};
