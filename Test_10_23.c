class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<int>> rows(9, vector<int>(10, 0));//共9行，每行10个数字对应0~9
		vector<vector<int>> cols(9, vector<int>(10, 0));//9列
		vector<vector<int>> cell(9, vector<int>(10, 0));//9个单元格
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
                if(board[i][j]=='.') continue;
				int e = board[i][j] - '0';
				if (rows[i][e] == 0) rows[i][e]++;
				else return false; //如果有重复的直接返回false
				if (cols[j][e] == 0) cols[j][e]++;
				else return false;
				int ci = map(i, j);
				if (cell[ci][e] == 0) cell[ci][e]++;
				else return false;
			}
		}
		return true;
	}
	int map(int i, int j) {
		int a = i / 3;
		int b = j / 3;
		return a + b * 3;
	}
};