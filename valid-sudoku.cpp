#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> row(9, false);
            vector<bool> col(9, false);
            for (int j = 0; j < 9; j++) {
               if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (row[idx]) return false;
                    row[idx] = true;
                }
                if (board[j][i] != '.') {
                    int idx = board[j][i] - '1';
                    if (col[idx]) return false;
                    col[idx] = true;
                }
            }
        }
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                vector<bool> box(9, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char curr = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (curr != '.') {
                            int idx = curr - '1';
                            if (box[idx]) return false;
                            box[idx] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

