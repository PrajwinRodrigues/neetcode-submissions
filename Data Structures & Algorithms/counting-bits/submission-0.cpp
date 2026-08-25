class Solution {
public:
    int f(int n){
        int count=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                count+=1;
            }
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<n+1;i++){
            ans[i]=f(i);
        }
        return ans;
    }
};
