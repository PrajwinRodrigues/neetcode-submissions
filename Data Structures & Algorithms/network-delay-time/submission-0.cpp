class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>> adj(n+1);
       for(auto it: times){
        adj[it[0]].push_back({it[1],it[2]});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
       pq.push({0,k});
       vector<int> time(n+1,1e9);
       time[k]=0;
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int u=it.second;
        int d=it.first;
        for(auto node:adj[u]){
            if(d+node.second<time[node.first]){
                time[node.first]=d+node.second;
                pq.push({d+node.second,node.first});
            }
        }
       }
       int maxi=-1;
       for(int i=1;i<n+1;i++){
        if(time[i]==1e9) return -1;
        maxi=max(maxi,time[i]);
       } 
       return maxi;
    }
};
