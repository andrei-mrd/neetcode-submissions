class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> freqRow;
        unordered_map<char, int> freqColumn;
        unordered_map<char, int> subBox;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    freqRow[board[i][j]] += 1;
                    if(freqRow[board[i][j]] > 1) {
                        return false;
                    }
                }
                if(board[j][i] != '.') {
                    freqColumn[board[j][i]] += 1;
                    if(freqColumn[board[j][i]] > 1) {
                        return false;
                    }
                }
            }
            freqRow.clear();
            freqColumn.clear();
            if(i == 0 || i == 3 || i == 6) {
                for(int k = i; k < i + 3; k ++) {
                    for(int j = 0; j < 3; j++) {
                        if(board[k][j] != '.') {
                            subBox[board[k][j]] +=1;
                            if(subBox[board[k][j]] > 1) {
                                return false;
                            }
                        }
                    }
                }
                subBox.clear();
                for(int k = i; k < i + 3; k ++) {
                    for(int j = 3; j < 6; j++) {
                        if(board[k][j] != '.') {
                            subBox[board[k][j]] +=1;
                            if(subBox[board[k][j]] > 1) {
                                return false;
                            }
                        }
                    }
                }
                subBox.clear();
                for(int k = i; k < i + 3; k ++) {
                    for(int j = 6; j < 9; j++) {
                        if(board[k][j] != '.') {
                            subBox[board[k][j]] +=1;
                            if(subBox[board[k][j]] > 1) {
                                return false;
                            }
                        }
                    }
                }
                subBox.clear();
            }
        }
        return true;
    }
};