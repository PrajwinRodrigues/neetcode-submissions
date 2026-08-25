class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]+=1;
        }
        for(auto it=m.begin();it!=m.end();it++){
            pq.push({it->second,it->first});
        }
        vector<int> ans(k);
        int c=0;
        while(c!=k){
            int n=pq.top().second;
            ans[c]=n;
            c+=1;
            pq.pop();
        }
        return ans;
    }
};
