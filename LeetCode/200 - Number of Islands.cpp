class Solution {
private:
    void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return;
        }
        if (visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        if (grid[row][col] == '0') {
            return;
        }
        visit(grid, visited, row - 1, col);
        visit(grid, visited, row + 1, col);
        visit(grid, visited, row, col - 1);
        visit(grid, visited, row, col + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '1') {
                    count++;
                }
                visit(grid, visited, i, j);
            }
        }
        return count;
    }
};
