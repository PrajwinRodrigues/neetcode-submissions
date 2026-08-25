class Solution {
public:
    bool f(vector<vector<char>> &board,int r,int c){
        int nrow=(r/3)*3;
        int ncol=(c/3)*3;
        for(int i=0;i<board.size();i++){
            if(board[i][c]==board[r][c] && r!=i) return false;
        }
        for(int i=0;i<board.size();i++){
            if(board[r][i]==board[r][c] && c!=i) return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+nrow][j+ncol]==board[r][c] && i+nrow!=r && j+ncol!=c){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!f(board,i,j)) return false;
            }
        }
        return  true;
    }
};
