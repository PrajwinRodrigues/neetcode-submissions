class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2,-1);
        int f=0,l=numbers.size()-1;
        while(f<l){
            if(target==numbers[f]+numbers[l]){
                ans[0]=f+1;
                ans[1]=l+1;
                return ans;
            }
            else if(target>numbers[f]+numbers[l]){
                f+=1;
            }
            else{
                l-=1;
            }
        }
        return ans;
    }
};
