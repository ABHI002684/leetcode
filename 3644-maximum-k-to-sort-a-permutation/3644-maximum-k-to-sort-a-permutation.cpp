class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int i = 0, curr = -1;
        for (auto num : nums) {
            if (num != i) {
                if (curr == -1) {
                    curr = num;
                } else {
                    curr = curr & num;
                }
            }
            i++;
        }

        if (curr == -1) {
            return 0;
        }

        return curr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna