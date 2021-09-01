class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        if (r > 0 && heights[r - 1][c] >= heights[r][c]) {
            dfs(heights, visited, r - 1, c);
        }
        if (r < visited.size() - 1 && heights[r + 1][c] >= heights[r][c]) {
            dfs(heights, visited, r + 1, c);
        }
        if (c > 0 && heights[r][c - 1] >= heights[r][c]) {
            dfs(heights, visited, r, c - 1);
        }
        if (c < visited[0].size() - 1 && heights[r][c + 1] >= heights[r][c]) {
            dfs(heights, visited, r, c + 1);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> p(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> a(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, p, i, 0);
            dfs(heights, a, i, heights[0].size() - 1);
        }
        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, p, 0, i);
            dfs(heights, a, heights.size() - 1, i);
        }
        vector<vector<int>> v;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (p[i][j] && a[i][j]) {
                    v.push_back(vector<int>{i, j});
                }
            }
        }
        return v;
    }
};
