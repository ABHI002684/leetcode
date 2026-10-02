class Solution {
public:
    void generateParenthesisHelper(string curr, int open, int close, int n,
                                   vector<string>& ans) {
        // base case or case-1
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // case-2
        if (open < n) {
            curr.push_back('(');
            generateParenthesisHelper(curr, open + 1, close, n, ans);
            curr.pop_back();
        }

        // case-3
        if (close < open) {
            curr.push_back(')');
            generateParenthesisHelper(curr, open, close + 1, n, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        generateParenthesisHelper(curr, 0, 0, n, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna