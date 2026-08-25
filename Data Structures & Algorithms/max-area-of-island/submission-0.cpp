class Solution {
public:
    int bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited,vector<int> &drow,vector<int> &dcol){
        if(grid[i][j]==0 || visited[i][j]==1) return 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        int area=1;
        while(!q.empty()){
            auto it=q.front();
            int cr=it.first;
            int cc=it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=cr+drow[i];
                int ncol=dcol[i]+cc;
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1 && !visited[nrow][ncol]!=0){
                    area+=1;
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int total=0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> drow={1,0,-1,0};
        vector<int> dcol={0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                total=max(total,bfs(i,j,grid,visited,drow,dcol));
            }
        }
        return total;
    }
};
