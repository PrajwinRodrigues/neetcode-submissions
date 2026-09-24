class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        //Node and parent
        q.push({0,-1});
        visited[0]=1;
        while(!q.empty()){
          auto node=q.front();
          q.pop();
          int no=node.first;
          int parent=node.second;
          for(auto it:adj[no]){
            if(it==parent) continue;
            if(visited[it]) return 0;
            visited[it]=1;
            q.push({it,no});
          }
        }

        for(int i=0;i<n;i++) if(!visited[i]) return 0;
        return 1;
    }
};
