class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;
        result.push_back(string(n, '.'));
        string rest = string(n - 1, '#') + '.';
        for (int i = 1; i < m; i++) {
            result.push_back(rest);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna