class Solution {
public:
    bool f(vector<vector<char>> &board,string word,int idx,int r,int c){
        if(idx==word.length()) return true;
        if(r>=board.size() || c>=board[0].size() || r<0 || c<0) return false;
        if(board[r][c]=='.') return false;
        if(board[r][c]==word[idx]){
            char t=board[r][c];
            board[r][c]='.';
            bool f1,f2,f3,f4;
            f1=f(board,word,idx+1,r+1,c);
            f2=f(board,word,idx+1,r-1,c);
            f3=f(board,word,idx+1,r,c+1);
            f4=f(board,word,idx+1,r,c-1);
            board[r][c]=t;
            return f1 || f2 || f3 || f4;
        }
        else{
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(f(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};
