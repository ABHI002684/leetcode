class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }

        nth_element(nums.begin(),nums.begin()+n/2,nums.end());

        long long ans=0, i;

        for( i=0;i<n/2;i++){
            ans -= (1LL * nums[i] * nums[i]);
        }

        for(;i<n;i++){
            ans+=(1LL * nums[i] * nums[i]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna