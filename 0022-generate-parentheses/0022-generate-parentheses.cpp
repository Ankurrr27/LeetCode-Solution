class Solution {
public:
    void solve(string current, int open, int close, int n, vector<string>& result) {
        // Base case
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            solve(current + "(", open + 1, close, n, result);
        }

        // Add ')'
        if (close < open) {
            solve(current + ")", open, close + 1, n, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve("", 0, 0, n, result);
        return result;
    }
};