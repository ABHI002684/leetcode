class Solution {
public:
    int minInsertions(string s) {
        vector<char> st;
        int n = s.size(), i = 0, ans = 0;

        while (i < n) {
            if (s[i] == '(') {
                st.push_back('(');
                i++;
            } else {
                // Ensure every closing pair contains two ')'.
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    ans++;
                    i++;
                }

                // Match the closing pair with an opening parenthesis.
                if (!st.empty()) {
                    st.pop_back();
                } else {
                    ans++; // Insert a missing '('.
                }
            }
        }

        // Each unmatched '(' needs two closing parentheses.
        ans += 2 * st.size();

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna