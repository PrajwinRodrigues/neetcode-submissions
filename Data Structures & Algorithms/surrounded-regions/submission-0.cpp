class Solution {
public:
    void bfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        visited[r][c]=1;
        q.push({r,c});
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int cr=it.first;
            int cc=it.second;
            for(int i=0;i<4;i++){
                int nrow=cr+drow[i];
                int ncol=cc+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                bfs(i,0,board,visited);
            }
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                bfs(i,m-1,board,visited);
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !visited[0][i]) bfs(0,i,board,visited);
            if(board[n-1][i]=='O' && !visited[n-1][i]) bfs(n-1,i,board,visited);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    visited[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
    }
};
