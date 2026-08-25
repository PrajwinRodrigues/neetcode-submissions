class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l=0,r=0,c=0;
        priority_queue<int>pq;
        unordered_map<int,int>m;
        while(r<nums.size()){
            pq.push(nums[r]);
            m[nums[r]]+=1;
            c+=1;
            if(c==k){
                ans.push_back(pq.top());
                m[nums[l]]-=1;
                while( !pq.empty() && m[pq.top()]==0) pq.pop();
                l+=1;
                c=k-1;
            }
               r+=1;
        }
        return ans;
    }
};
