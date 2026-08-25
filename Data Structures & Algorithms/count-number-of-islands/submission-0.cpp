class Solution {
public:
    int bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis,vector<int> &drow,vector<int> &dcol){
        queue<pair<int,int>> q;
        if(grid[i][j]=='0' || vis[i][j]==1) return 0;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=cr+drow[i];
                int ncol=dcol[i]+cc;
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int tot=0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                tot+=bfs(i,j,grid,visited,drow,dcol);
            }
        }
        return tot;
    }
};
