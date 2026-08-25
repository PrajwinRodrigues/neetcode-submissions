class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &visited,int n,int m,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m || i<0 || m<0) return 0;
        if(visited[i][j]==1) return dp[i][j];
        visited[i][j]=1;
        dp[i][j]=dfs(i+1,j,visited,n,m,dp) + dfs(i,j+1,visited,n,m,dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        return dfs(0,0,visited,m,n,dp);
    }
};
