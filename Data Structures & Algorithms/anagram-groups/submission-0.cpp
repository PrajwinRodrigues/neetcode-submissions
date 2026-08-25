class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<string,vector<string>>m;
        string temp;
        for(string s:strs){
            temp=s;
            sort(temp.begin(),temp.end());
            if(m.find(temp)==m.end()){
                m[temp]={s};
            }
            else{
                m[temp].push_back(s);
            }
        }
        for(auto it=m.begin();it!=m.end();it++){
            answer.push_back(it->second);
        }
        return answer;
    }
};
