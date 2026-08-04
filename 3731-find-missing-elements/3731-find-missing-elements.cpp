class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int maxi=INT_MIN,mini=INT_MAX;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }

        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};