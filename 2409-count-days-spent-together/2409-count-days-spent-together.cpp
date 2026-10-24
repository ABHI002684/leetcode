class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        auto to_day = [&](const string& s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            return accumulate(days.begin(), days.begin() + m - 1, 0) + d;
        };

        if (start > end) {
            return 0;
        }
        return to_day(end) - to_day(start) + 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna