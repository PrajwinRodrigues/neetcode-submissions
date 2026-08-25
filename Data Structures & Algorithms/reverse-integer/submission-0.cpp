class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x != 0) {
            ans = ans * 10 + x % 10;   // works for negative too
            if (ans > INT_MAX || ans < INT_MIN) return 0; // check overflow
            x /= 10;
        }
        return (int)ans;
    }
};
