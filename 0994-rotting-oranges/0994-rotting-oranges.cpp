class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // visited array
        // 0 = not visited
        // 2 = visited / rotten
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Queue stores:
        // {{row, column}, time}
        queue<pair<pair<int, int>, int>> q;

        // Find all initially rotten oranges
        // and put them into the queue.
        // This makes it a multi-source BFS.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    // Initially rotten orange takes 0 minutes
                    q.push({{i, j}, 0});

                    // Mark it as visited
                    vis[i][j] = 2;
                }
            }
        }

        // Stores the maximum time required
        // for any orange to become rotten.
        int tm = 0;

        // Four possible directions:
        //       (-1,0)
        //          ↑
        // (0,-1) ←   → (0,1)
        //          ↓
        //       (1,0)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS
        while (!q.empty()) {

            // Get the front element
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            // Keep track of the maximum time
            tm = max(tm, t);

            // Check all 4 neighbouring cells
            for (int i = 0; i < 4; i++) {

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check:
                // 1. New row is inside the grid
                // 2. New column is inside the grid
                // 3. Orange has not already been visited
                // 4. The cell contains a fresh orange
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] == 1) {

                    // This fresh orange becomes rotten
                    // after 1 more minute.
                    q.push({{nrow, ncol}, t + 1});

                    // Mark it visited so that we
                    // don't process it again.
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Check if any fresh orange is still left.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        // All oranges have successfully rotted.
        return tm;
    }
};