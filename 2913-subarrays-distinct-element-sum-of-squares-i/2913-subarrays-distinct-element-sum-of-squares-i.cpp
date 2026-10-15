class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, id = 0;

        vector<int> fr(101);

        for (int l = 0; l < n; l++) {
            int cnt = 0;
            id++;
            for (int r = l; r < n; r++) {
                cnt += (fr[nums[r]] != id);
                fr[nums[r]] = id;
                sum += pow(cnt, 2);
            }
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna