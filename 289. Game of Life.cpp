class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int lives = helper(board, m, n, i, j);
				// In the beginning, every 2nd bit is 0;
				// So we only need to care about when the 2nd bit will become 1.
				if (board[i][j] == 1 && lives >= 2 && lives <= 3) {
					board[i][j] = 3; // Make the 2nd bit 1: 01 ---> 11
				}
				if (board[i][j] == 0 && lives == 3) {
					board[i][j] = 2; // Make the 2nd bit 1: 00 ---> 10
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] >>= 1;  // Get the 2nd state.
			}
		}
	}
	int helper(vector<vector<int>>& board, int m, int n, int i, int j) {
		int lives = 0;
		for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
			for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
				lives += board[x][y] & 1;
			}
		}
		lives -= board[i][j] & 1;
		return lives;
	}
};