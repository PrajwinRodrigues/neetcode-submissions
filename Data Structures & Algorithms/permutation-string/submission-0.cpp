class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i=0;i<s1.length();i++) hash1[s1[i]-'a']+=1;
        int l=0,r=0;
        while(r<s2.length()){
            hash2[s2[r]-'a']+=1;
           if( r-l+1==s1.length() && hash1==hash2) return true;
           if(r-l+1>s1.length()){
            hash2[s2[l]-'a']-=1;
            l+=1;
           }
           if( r-l+1==s1.length() && hash1==hash2) return true;
           r+=1;
        }
        return false;
    }
};
