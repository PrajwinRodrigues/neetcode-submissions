class Solution {
public:

    int maxArea(vector<int>& heights) {
      int f=0,l=heights.size()-1;
      int maxi=(l-f)*min(heights[f],heights[l]);
      while(f<l){
        maxi=max(maxi,(l-f)*min(heights[f],heights[l]));
        if(heights[f]<heights[l]){
            f+=1;
        }
        else{
            l-=1;
        }
       
      }
      return maxi;
    }
};
