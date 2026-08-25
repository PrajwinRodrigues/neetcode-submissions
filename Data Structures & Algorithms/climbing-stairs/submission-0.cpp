class Solution {
public:
    int f(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        int first=f(n-1);
        int second=f(n-2);
        return first+second;
    }
    int climbStairs(int n) {
        return f(n);
    }
};
