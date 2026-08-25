class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=1;
            }
            else{
                m[s[i]]+=1;
            }
        }
        for(int i=0;i<t.length();i++){
            m[t[i]]-=1;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>0) return false;
        }
        return true;
    }
};
