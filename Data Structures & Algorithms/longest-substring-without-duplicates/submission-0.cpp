class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxl=0,len=0;
        vector<int>hash(256,-1);
        while(r<s.length()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            hash[s[r]]=r;
            len=r-l+1;
            maxl=max(maxl,len);
            r+=1;
        }
        return maxl;
        
    }
};
