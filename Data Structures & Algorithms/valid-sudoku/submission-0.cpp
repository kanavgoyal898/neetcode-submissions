class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> nums;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (nums.find(board[i][j]) != nums.end()) {
                        return false;
                    }
                    nums.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<int> nums;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (nums.find(board[j][i]) != nums.end()) {
                        return false;
                    }
                    nums.insert(board[j][i]);
                }
            }
        }

        for (int k = 0; k < 9; k++) {
            unordered_set<int> nums;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int i_ = k / 3 * 3 + i;
                    int j_ = k % 3 * 3 + j;
                    if (board[i_][j_] != '.') {
                        if (nums.find(board[i_][j_]) != nums.end()) {
                            return false;
                        }
                        nums.insert(board[i_][j_]);
                    }
                }
            }
        }

        return true;
    }
};
