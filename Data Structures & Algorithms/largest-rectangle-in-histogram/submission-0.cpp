class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prevsmall(n,-1),nextsmall(n,-1);
        stack<int>s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                prevsmall[i]=-1;
            }
            else{
                prevsmall[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while( !s.empty() && heights[i]<=heights[s.top()]) s.pop();
            if(s.empty()) nextsmall[i]=n;
            else nextsmall[i]=s.top();
            s.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int area=(nextsmall[i]-prevsmall[i]-1)*heights[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;

    }
};
