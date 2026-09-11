class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // Boundary check
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // If this cell is water, stop
        if (grid[row][col] == '0')
            return;

        // Mark the current land cell as visited
        grid[row][col] = '0';

        // Visit all 4 directions
        dfs(row - 1, col, grid); // up
        dfs(row + 1, col, grid); // down
        dfs(row, col - 1, grid); // left
        dfs(row, col + 1, grid); // right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();        // rows
        int m = grid[0].size();     // columns

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found a new island
                if (grid[i][j] == '1') {
                    count++;

                    // Explore the entire island
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};