class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> t(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    t[i][j]=0;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==-1) t[i][j]=-1;
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.second.first;
            int c=it.second.second;
            int d=it.first;
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=-1){
                    if(d+1<t[nrow][ncol]){
                        t[nrow][ncol]=d+1;
                        q.push({d+1,{nrow,ncol}});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(t[i][j]==1e9){
                    grid[i][j]=INT_MAX;
                }
                else
                grid[i][j]=t[i][j];
            }
        }

    }
};
