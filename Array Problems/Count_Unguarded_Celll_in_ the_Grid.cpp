class Solution {
public:
    void mark(int r, int c, vector<vector<int>>& grid) {
        // up
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 1 || grid[i][c] == 2) {
                break;
            }
            grid[i][c] = 3;
        }
        // down
        for (int i = r + 1; i < grid.size(); i++) {
            if (grid[i][c] == 1 || grid[i][c] == 2) {
                break;
            }
            grid[i][c] = 3;
        }

        // left
        for (int i = c - 1; i >= 0; i--) {
            if (grid[r][i] == 1 || grid[r][i] == 2) {
                break;
            }
            grid[r][i] = 3;
        }

        // for right

        for (int i = c + 1; i < grid[0].size(); i++) {
            if (grid[r][i] == 1 || grid[r][i] == 2) {
                break;
            }
            grid[r][i] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (vector<int>& vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 1;
        }
        for (vector<int>& vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2;
        }
        for (vector<int>& v : guards) {
            int i = v[0];
            int j = v[1];
            mark(i, j, grid);
        }

        int ct = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    ct++;
            }
        }
        return ct;
    }
};
