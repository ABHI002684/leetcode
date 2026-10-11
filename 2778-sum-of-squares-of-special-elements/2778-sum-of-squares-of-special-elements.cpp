class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int a = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                a += nums[i] * nums[i];
            }
        }
        return a;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna