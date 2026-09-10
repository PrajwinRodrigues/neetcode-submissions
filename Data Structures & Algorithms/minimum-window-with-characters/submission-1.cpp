class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> m1(256,0);
      vector<int> m2(256,0);
      int n=s.length();
      int m=t.length();
      int c=0;
      for(int i=0;i<m;i++){
        if(m1[t[i]]==0) c+=1;
        m1[t[i]]+=1;
      }

      int l=0,r=0;
      int mini=1e9;
      int midx=-1;
      string ans="";
      int k=0;
      while(r<n){
        m2[s[r]]+=1;
        if(m1[s[r]]==m2[s[r]]) k+=1;
        while(k>=c){
           if(r-l+1<mini){
            mini=r-l+1;
            midx=l;
           }
            m2[s[l]]-=1;
            if(m1[s[l]]>m2[s[l]]) k-=1;
            l+=1;
        }
        r+=1;
      }

      if(midx==-1) return "";
      ans=s.substr(midx,mini);
      return ans;
    }
};
