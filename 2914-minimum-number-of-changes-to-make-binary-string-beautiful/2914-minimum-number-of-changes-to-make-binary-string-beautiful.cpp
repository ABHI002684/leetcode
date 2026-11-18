class Solution {
public:
    int minChanges(string s) {
        int min = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) {
                min++;
            }
        }
        return min;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna