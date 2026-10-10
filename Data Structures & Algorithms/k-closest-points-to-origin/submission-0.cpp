class Solution {
public:
    long long distance(long long x,long long y){
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
        for(auto it:points){
            auto d=distance(it[0],it[1]);
            pq.push({d,{it[0],it[1]}});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k!=0){
            auto it=pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
            k-=1;
        }

        return ans;
    }
};
