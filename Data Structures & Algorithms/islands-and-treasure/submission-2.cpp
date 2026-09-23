class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    visited[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] &&
                grid[nrow][ncol]==INT_MAX){
                    grid[nrow][ncol]=d+1;
                    q.push({d+1,{nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            }
        }

    }
};
