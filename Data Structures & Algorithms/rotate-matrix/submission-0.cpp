class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                if(i==j) continue;
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        int f=0,l=matrix.size()-1;
        while(f<l){
            for(int i=0;i<matrix.size();i++){
               int t=matrix[i][f];
               matrix[i][f]=matrix[i][l];
               matrix[i][l]=t;
            }
            f+=1;
            l-=1;
        }
    }
};
