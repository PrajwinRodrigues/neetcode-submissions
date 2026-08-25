class Solution {
public:
    int f(int i,string &s,vector<int> &dp){
        if(s[i]=='0') return 0;
        if(i>=s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int p=0,np=0;
        p=f(i+1,s,dp);
        if(i<s.length()-1 && s[i]<='2'){
            if(s[i]=='2' && s[i+1]>'6') return p;
            np=f(i+2,s,dp);
        }
        return dp[i]=p+np;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        if(s[0]=='0') return 0;
        return f(0,s,dp);
    }
};
