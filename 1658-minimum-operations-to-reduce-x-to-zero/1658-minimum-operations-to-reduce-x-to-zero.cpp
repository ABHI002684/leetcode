class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];

         x=sum-x;
        int len=-1,l=0,r=0,curr=0;

        while(r<n){
            curr+=nums[r];
            while(l<=r && curr>x){
                curr-=nums[l];
                l++;
            }

            if(curr==x){
                len=max(len,r-l+1);
            }
            r++;
        }

        return len==-1?-1:n-len;
    }
};