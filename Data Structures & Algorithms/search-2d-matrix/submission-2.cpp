class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int f=0,l=0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        while(f>=0 && l>=0 && f<n && l<m){
            if(visited[f][l]){
                return false;
            }
            visited[f][l]=1;
            if(matrix[f][l]==target){
                return true;
            }
            else if(target>matrix[f][l]){
                if(target>matrix[f][m-1]){
                    f+=1;
                }
                else{
                    l+=1;
                }
            }
            else{
              if(target<matrix[0][l]){
                f-=1;
              }
              else{
                l-=1;
              }
            }
        }
        return false;
    }
};
