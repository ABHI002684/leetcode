class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lo = ranges::min(nums), moves = 0;
        for (int x : nums)
            moves += x - lo;
        return moves;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna