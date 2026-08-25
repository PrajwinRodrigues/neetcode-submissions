class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int u=0,r=matrix[0].size()-1,l=0,d=matrix.size()-1;
        while(d>=u && r>=l){
           for(int i=l;i<=r;i++){
            ans.push_back(matrix[u][i]);
           }
           u+=1;
           for(int i=u;i<=d;i++){
            ans.push_back(matrix[i][r]);
           }
           r-=1;
           if(u>d) break;
           for(int i=r;i>=l;i--){
            ans.push_back(matrix[d][i]);
           }
           d-=1;
           if(l>r) break;
           for(int i=d;i>=u;i--){
            ans.push_back(matrix[i][l]);
           }
           l+=1;
        }
        return ans;
    }
};
