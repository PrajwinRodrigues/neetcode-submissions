class Solution {
public:
    int f(int i,string &s){
        if(s[i]=='0') return 0;
        if(i>=s.length()) return 1;
        int p=0,np=0;
        p=f(i+1,s);
        if(i<s.length()-1 && s[i]<='2'){
            if(s[i]=='2' && s[i+1]>'6') return p;
            np=f(i+2,s);
        }
        return p+np;
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        return f(0,s);
    }
};
