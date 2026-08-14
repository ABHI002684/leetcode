class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<int, int> mp;
        int maxLength = 0;
        while (right < n) {
            mp[s[right]]++;
            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(mp[s[left]]);
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};