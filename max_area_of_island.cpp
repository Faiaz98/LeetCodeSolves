class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>&grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 0;

        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) {
            return 0;
        }

        //mark the current area as visited
        grid[row][col] = 0;
        area++; //incremeant the area

        area += dfs(grid, row + 1, col);
        area += dfs(grid, row - 1, col);
        area += dfs(grid, row, col + 1);
        area += dfs(grid, row, col - 1);

        return area;
    }
};
