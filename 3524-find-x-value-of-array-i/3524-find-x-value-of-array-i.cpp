class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);

        vector<long long> prev(k, 0);

        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;
            vector<long long> curr(k, 0);
            curr[rem] += 1;

            for (int j = 0; j < k; j++) {
                long long val = prev[j];
                if (val == 0)
                    continue;
                int idx = (j * rem) % k;
                curr[idx] += val;
            }

            for (int x = 0; x < k; x++) {
                ans[x] += curr[x];
            }

            prev = curr;
        }

        return ans;
    }
};