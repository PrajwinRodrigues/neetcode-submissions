class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxf=0,maxlen=0,len=0;
        vector<int>hash(26,0);
        while(r<s.length()){
            hash[s[r]-'A']+=1;
            maxf=max(maxf,hash[s[r]-'A']);
            if(r-l+1-maxf>k){
                hash[s[l]-'A']-=1;
                l+=1;
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            r+=1;
        }
        return maxlen;
    }
};
