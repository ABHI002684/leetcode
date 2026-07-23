class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        else if(n==2) return 2;
        int x=0;
        while(pow(2,x+1)<=n){
            x++;
        }

        return pow(2,x+1);
    }
};