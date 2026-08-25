class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> present(26,0);
        vector<int> indegree(26,0);
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.length(),s2.length());
            bool mismatch=false;
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    mismatch=true;
                    break;
                }
            }
            if(!mismatch && s1.length()>s2.length()) return "";

        }

        for(auto it:words){
            for(int i=0;i<it.length();i++){
                present[it[i]-'a']=1;
            }
        }

        for(auto it:adj){
            for(auto node:it){
                indegree[node]+=1;
            }
        }

        queue<int> q;
        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0) q.push(i);
        }

        string answer="";
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            answer.push_back((char)(it+'a'));
            for(auto node:adj[it]){
                indegree[node]-=1;
                if(indegree[node]==0) q.push(node);
            }
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(present[i]) c+=1;
        }

        if(c!=answer.length()) return "";
        return answer;
    }
};
