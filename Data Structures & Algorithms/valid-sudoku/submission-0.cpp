class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> nums;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (nums.find(board[i][j]) == nums.end()) {
                        nums.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<char> nums;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (nums.find(board[j][i]) == nums.end()) {
                        nums.insert(board[j][i]);
                    } else {
                        return false;
                    }
                }
            }
        }

        for (int k = 0; k < 9; k++) {
            unordered_set<char> nums;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int i_ = (k / 3) * 3 + i;
                    int j_ = (k % 3) * 3 + j;
                    if (board[i_][j_] != '.') {
                        if (nums.find(board[i_][j_]) == nums.end()) {
                            nums.insert(board[i_][j_]);
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
