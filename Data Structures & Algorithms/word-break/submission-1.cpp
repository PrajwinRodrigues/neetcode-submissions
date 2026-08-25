class Solution {
public:
    int f(int l,int r,string &s,unordered_set<string> &st,vector<vector<int>> &dp){
        if(l==s.length()) return 1;
        if(r==s.length()) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int p=0,np=0;
        if(st.find(s.substr(l,r-l+1))!=st.end()){
           p=f(r+1,r+1,s,st,dp);
        } 
        np=f(l,r+1,s,st,dp);
        return dp[l][r]= (p || np);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return f(0,0,s,st,dp);
    }
};
