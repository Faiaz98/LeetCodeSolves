class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        queue<pair<int, int>> rotten;

        //find the initial rotten oranges and add them to the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        //perfrom bfs
        while (!rotten.empty()) {
            int size = rotten.size();
            bool changed = false;

            for (int i = 0; i < size; i++) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                //check adjacent cells
                for (const auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX >= 0 && newX < rows && newY >= 0 && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; //mark as rotten
                        rotten.push({newX, newY});
                        changed = true;
                    }
                }
            }

            if (changed) {
                minutes++;
            }
        }

        //check if there are any fresh oranges left
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return -1; //some oranges couldn't be rotten
                }
            }
        }

        return minutes;
    }
};
