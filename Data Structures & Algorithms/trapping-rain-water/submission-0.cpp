class Solution {
public:
    int trap(vector<int>& height) {
       int lmax=0;
       int rmax=0;
       int l=0;
       int n=height.size();
       int r=n-1;
       int total=0;
       while(l<r){
        lmax=max(lmax,height[l]);
        rmax=max(rmax,height[r]);
        total+=(lmax-height[l]);
        total+=(rmax-height[r]);
        if(lmax>rmax){
            r-=1;
        }
        else{
            l+=1;
        }
       }
       return total; 
    }
};
