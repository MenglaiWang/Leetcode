class Solution {
public:
	bool search(int i, int j ,vector<vector<char>>& board, string& word,int k){
		if(k == word.size()) return true;
		if(i< 0 || j< 0 || i >= board.size() || j >= board[0].size()) return false;
		if(word[k] != board[i][j]) return false;
		board[i][j] = '\0';
		bool flag = search(i-1,j,board,word,k+1) || search(i+1,j,board,word,k+1) ||
					search(i,j-1,board,word,k+1) || search(i,j+1,board,word,k+1);
		board[i][j] = word[k];
		return flag;
	}
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n;j++){
        		if(search(i,j,board,word,0)) return true;
        	}
        }
        return false;
    }
};