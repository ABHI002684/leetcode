class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxi = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                if (maxi < count)
                    maxi = count;
            } else if (c == ')') {
                count--;
            }
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna