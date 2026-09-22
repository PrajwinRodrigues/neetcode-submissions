class Solution {
public:
    void f(int idx, string &s,map<int,vector<char>> &m,string &temp,vector<string> &ans){
        if(idx==s.length()){
            ans.push_back(temp);
            return;
        }
        int number=s[idx]-'0';
        for(auto it:m[number]){
            temp.push_back(it);
            f(idx+1,s,m,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        map<int,vector<char>> m;
        int c=0;
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        vector<string> ans;
        string temp="";
        f(0,digits,m,temp,ans);
        return ans;

    }
};
