class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>>& ans,
             vector<vector<int>>& image,
             int newColor,
             int delRow[],
             int delCol[],
             int iniColor) {

        // Change the current pixel to the new color
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        // Check all 4 directions
        for (int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check if:
            // 1. The new row is inside the image
            // 2. The new column is inside the image
            // 3. The original image has the same color
            // 4. This cell has not already been changed
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != newColor) {

                dfs(nrow, ncol,
                    ans, image,
                    newColor,
                    delRow, delCol,
                    iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr,
                                   int sc,
                                   int color) {

        // Store the color of the starting pixel
        int iniColor = image[sr][sc];

        // Copy the original image
        vector<vector<int>> ans = image;

        // Four directions:
        // up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // If the new color is already the same as the
        // initial color, nothing needs to be changed.
        if (iniColor == color)
            return ans;

        // Start DFS from the starting pixel
        dfs(sr, sc,
            ans, image,
            color,
            delRow, delCol,
            iniColor);

        return ans;
    }
};