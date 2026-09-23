class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     int c=0;
     queue<pair<int,int>>q;
     int n=grid.size();
     int m=grid[0].size();
     bool flag=1;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2) q.push({i,j});
            if(grid[i][j]==1) flag=0;
        }
     }
     if(q.empty() && flag) return 0;
     if(q.empty() && !flag) return -1;
     int drow[]={-1,0,1,0};
     int dcol[]={0,1,0,-1};
     while(!q.empty()){
        int size=q.size();
        c+=1;
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});
                }
            }
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
     }
     return c-1;
    }
};
