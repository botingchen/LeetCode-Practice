class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> box_mp;
        unordered_map<int, int> row_mp;
        unordered_map<int, int> col_mp;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && row_mp[board[i][j]] != 0) return false;
                else if(board[i][j] != '.') row_mp[board[i][j]]++;
                if(board[j][i] != '.' && col_mp[board[j][i]] != 0) return false;
                else if(board[j][i] != '.') col_mp[board[j][i]]++;
            }
            row_mp.clear();
            col_mp.clear();
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 3; j++){
                if(board[(i / 3) * 3][(i % 3) * 3 + j] != '.' && box_mp[board[(i / 3) * 3][(i % 3) * 3 + j]] != 0) return false;
                if(board[(i / 3) * 3 + 1][(i % 3) * 3 + j] != '.' && box_mp[board[(i / 3) * 3 + 1][(i % 3) * 3 + j]] != 0) return false;
                if(board[(i / 3) * 3 + 2][(i % 3) * 3 + j] != '.' && box_mp[board[(i / 3) * 3 + 2][(i % 3) * 3 + j]] != 0) return false;
                else {
                    box_mp[board[(i / 3) * 3][(i % 3) * 3 + j]]++;
                    box_mp[board[(i / 3) * 3 + 1][(i % 3) * 3 + j]]++;
                    box_mp[board[(i / 3) * 3 + 2][(i % 3) * 3 + j]]++;
                }
            }
            box_mp.clear();
        }
        return true;
    }
};