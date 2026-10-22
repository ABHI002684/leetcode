class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Array can be sorted only if it is one of the two below types, else
        // not
        //      Increasing + Increasing (2, 3, 4, 0, 1)
        //      Decreasing + Decreasing (2, 1, 0, 4, 3)
        int n = nums.size();
        if (n == 1)
            return 0;
        if (is_sorted(begin(nums), end(nums)))
            return 0;
        if (is_sorted(next(begin(nums)), end(nums)) && nums[0] > nums.back())
            return 1;
        if (is_sorted(next(begin(nums)), end(nums), greater<int>()) &&
            nums[0] < nums.back())
            return 2;
        // Increasing + Increasing case
        if (nums[1] > nums[0]) {
            int i = 1, chunk_len1 = 1;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                chunk_len1++;
                i++;
            }
            if (i == n)
                return 0;
            int chunk_len2 = 1;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                chunk_len2++;
                i++;
            }
            if (i != n)
                return -1;
            // Take min of below 2
            //      Shift left for all chunk_len1
            //      Reverse (it will become Decreasing + Decreasing case), shift
            //      left for all chunk_len2, then reverse again
            return min(chunk_len1, 1 + chunk_len2 + 1);
        }
        // Decreasing + Decreasing case
        int i = 1, chunk_len1 = 1;
        while (i < n && nums[i - 1] == nums[i] + 1) {
            chunk_len1++;
            i++;
        }
        // All decreasing, so just reverse once
        if (i == n)
            return 1;
        int chunk_len2 = 1;
        i++;
        while (i < n && nums[i - 1] == nums[i] + 1) {
            chunk_len2++;
            i++;
        }
        if (i != n)
            return -1;
        // Take min of below 2
        //      Shift left for all chunk_len1, then reverse whole
        //      Reverse (it will become Increasing + Increasing case), shift
        //      left for all chunk_len2
        return min(chunk_len1 + 1, chunk_len2 + 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna