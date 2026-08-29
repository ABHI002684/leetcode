class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < nums.size(); i++)
            vp.push_back({nums[i], i});

        sort(vp.begin(), vp.end());

        vector<vector<int>> groups;
        groups.push_back({vp[0].second});

        for (int i = 1; i < nums.size(); i++) {
            if (vp[i].first - vp[i - 1].first <= limit) {
                groups.back().push_back(vp[i].second);
            } else {
                groups.push_back({vp[i].second});
            }
        }

        for (auto& group : groups) {
            vector<int> sortedVal;
            for (int i = 0; i < group.size(); i++) {
                sortedVal.push_back(nums[group[i]]);
            }

            sort(sortedVal.begin(), sortedVal.end());
            sort(group.begin(), group.end());

            for (int i = 0; i < group.size(); i++) {
                nums[group[i]] = sortedVal[i];
            }
        }

        return nums;
    }
};