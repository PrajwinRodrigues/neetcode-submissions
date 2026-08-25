class Solution {
public:
    int f(int i,int j,string &s1, string &s2,vector<vector<int>> &dp){
        if(i==s1.length()) return 0;
        if(j==s2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+f(i+1,j+1,s1,s2,dp);
        int p1=f(i+1,j,s1,s2,dp);
        int p2=f(i,j+1,s1,s2,dp);
        return dp[i][j]=max(p1,p2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        return f(0,0,text1,text2,dp);
    }
};
