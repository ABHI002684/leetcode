class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc_length = 1;
        int dec_length = 1;
        int max_length = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc_length += 1;
                dec_length = 1;
            } else if (nums[i] < nums[i - 1]) {
                inc_length = 1;
                dec_length += 1;
            } else {
                inc_length = 1;
                dec_length = 1;
            }

            max_length = max(max_length, max(inc_length, dec_length));
        }
        return max_length;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna