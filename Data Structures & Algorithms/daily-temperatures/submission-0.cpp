class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(),0);
        int n=temperatures.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            s.push(i);
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()) result[i]=s.top()-i;
            else result[i]=0;
            s.push(i);
        }
        return result;
    }
};
