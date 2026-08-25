class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int r=0,l=0;
        int len=0;
        int u=0;
        vector<int> hash(26,0);
        while(r<s.length()){
            if(hash[s[r]-'a']==0){
                u+=1;
            }
            hash[s[r]-'a']+=1;
            if(u<=k){
                len=max(len,r-l+1);
            }
            while(u>k){
                if(hash[s[l]-'a']==1){
                    u-=1;
                }
                hash[s[l]-'a']-=1;
                l+=1;
            }
            r+=1;
        }
        return len;
    }
};
