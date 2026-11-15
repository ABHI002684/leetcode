class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, prefix = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            if (prefix % 2 == 0) {
                // ans=(ans%mod+odd%mod)%mod;
                ans += odd;
                even++;
            } else {
                // ans=(ans%mod+even%mod)%mod;
                ans += even;
                odd++;
            }

            ans %= mod;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna