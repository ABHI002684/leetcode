class Solution {
public:
    int m, n;
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n) { // out of bound
            return false;
        }

        if (grid[r][c] == 1) { // water
            return true;
        }

        grid[r][c] = 1;

        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(i, j, grid) == true) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna