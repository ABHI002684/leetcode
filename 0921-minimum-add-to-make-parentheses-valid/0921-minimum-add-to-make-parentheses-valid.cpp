class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else if (open > 0 && s[i] == ')') {
                open--;
            } else if (open <= 0) {
                close++;
            }
        }
        return open + close;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna