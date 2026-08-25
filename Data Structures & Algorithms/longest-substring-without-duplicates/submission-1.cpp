class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxl=0,cur=0;
        unordered_map<char,int>m;
        while(r<s.length()){
           m[s[r]]+=1;
           while(m[s[r]]>1){
            m[s[l]]-=1;
            l+=1;
           }
           cur=r-l+1;
           maxl=max(maxl,cur);
           r+=1;
        }
        return maxl;
    }
};
