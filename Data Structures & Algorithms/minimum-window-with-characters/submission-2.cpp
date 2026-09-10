class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> m1(256,0);
      int n=s.length();
      int m=t.length();
      for(int i=0;i<m;i++){
        m1[t[i]]+=1;
      }
      int l=0,r=0;
      int mini=1e9;
      int midx=-1;
      int k=m;
      string ans="";
      while(r<n){
        if(m1[s[r]]>0) k-=1;
        m1[s[r]]-=1;
        while(k==0){
           if(r-l+1<mini){
            mini=r-l+1;
            midx=l;
           }
            m1[s[l]]+=1;
            if(m1[s[l]]>0) k+=1;
            l+=1;
        }
        r+=1;
      }

      if(midx==-1) return "";
      ans=s.substr(midx,mini);
      return ans;
    }
};
