class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = nums[i], g = nums[i], l = nums[i];

            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long) nums[j]);
                l = lcm(l, (long long) nums[j]);

                if (prod > g * l) break;
                if (prod == g * l) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna