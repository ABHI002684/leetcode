class Solution {
public:
    int getDigitSum(int n){
        int sum=0;

        while(n>0){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2){
            int digitSum1= getDigitSum(num1);
            int digitSum2= getDigitSum(num2);

            if(digitSum1 != digitSum2){
                return digitSum1<digitSum2;
            }

            return num1<num2;
        };

        sort(afterSorted.begin(),afterSorted.end(),lambda);

        unordered_map<int,int> ValToIdx;

        for(int i=0;i<n;i++){
            ValToIdx[nums[i]]=i;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = ValToIdx[expectedVal];

            nums[i]=expectedVal;
            nums[idx]=currVal;

            ValToIdx[expectedVal]=i;
            ValToIdx[currVal]=idx;
            cnt++;
        }

        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna