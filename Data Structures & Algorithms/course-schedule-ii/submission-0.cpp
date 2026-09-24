class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]+=1;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        if(q.empty()) return {};

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]-=1;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(n==ans.size()) return ans;
        return {};

    }
};
