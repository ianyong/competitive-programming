class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int row, int col) {
        if (i == word.size()) {
            return true;
        }
        if (row < 0 || row > board.size() - 1 || col < 0 || col > board[0].size() - 1) {
            return false;
        }
        if (board[row][col] == '\0') {
            return false;
        }
        if (word[i] != board[row][col]) {
            return false;
        }
        char c = board[row][col];
        board[row][col] = '\0';
        bool isFound = dfs(board, word, i + 1, row, col - 1)
            || dfs(board, word, i + 1, row, col + 1)
            || dfs(board, word, i + 1, row - 1, col)
            || dfs(board, word, i + 1, row + 1, col);
        board[row][col] = c;
        return isFound;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
