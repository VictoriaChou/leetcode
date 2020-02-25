// 有效数独
// box_index = (row / 3) * 3 + col / 3;
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int row[9][10] = { 0 };
      int col[9][10] = { 0 };
      int box[9][10] = { 0 };
      for (int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
          char num = board[i][j];
          if(num == '.') continue;
          int n = num - '0'; // 不能用(int)num， 这样会返回num的ascii码
          if(row[i][n]) return false;
          if(col[j][n]) return false;
          if(box[(i/3)*3 + j/3][n]) return false;
          row[i][n] = 1;
          col[j][n] = 1;
          box[(i/3)*3 + j/3][n] = 1;
        }
      }
      return true;
    }
};