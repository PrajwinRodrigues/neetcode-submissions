class Solution {
public:
    void f(int open, int close, int n,
           string& temp, vector<string>& ans) {

        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // Choose '('
        if (open < n) {
            temp.push_back('(');
            f(open + 1, close, n, temp, ans);
            temp.pop_back();
        }

        // Choose ')'
        if (close < open) {
            temp.push_back(')');
            f(open, close + 1, n, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        f(0, 0, n, temp, ans);

        return ans;
    }
};