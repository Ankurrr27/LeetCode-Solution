class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        // Put all 0s into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        // Directions: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS
        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            dist[row][col] = steps;

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // Check boundary and whether already visited
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 0) {

                    visited[nrow][ncol] = 1;

                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return dist;
    }
};