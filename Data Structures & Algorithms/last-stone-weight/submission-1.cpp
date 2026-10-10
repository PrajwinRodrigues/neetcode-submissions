class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            auto it1=pq.top();
            pq.pop();
            if(pq.empty()) return it1;
            auto it2=pq.top();
            pq.pop();
            if(it1==it2) continue;
            else if(it1<it2){
                pq.push(it2-it1);
            }
            else if(it2<it1){
                pq.push(it1-it2);
            }
        }

        return 0;
    }
};
