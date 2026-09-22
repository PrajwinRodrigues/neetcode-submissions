class Solution {
public:
    int isSafe(int r,int c,int n,vector<string> &b){
        for(int i=0;i<n;i++){
            if(b[i][c]=='Q') return 0;
        }

        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(b[i][j]=='Q') return 0;
        }

        for(int i=r-1,j=c+1;i>=0 && j<n; i--,j++){
            if(b[i][j]=='Q') return 0;
        }
        return 1;
    }

    void f(int r,vector<string> &temp,vector<vector<string>> &ans,int n){
        if(r==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
           if(isSafe(r,i,n,temp)){
            temp[r][i]='Q';
            f(r+1,temp,ans,n);
            temp[r][i]='.';
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        vector<vector<string>> ans;
        f(0,temp,ans,n);
        return ans;
    }
};
