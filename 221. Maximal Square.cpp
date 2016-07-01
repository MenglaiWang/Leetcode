class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_size = 0;
        if(matrix.empty()) return max_size;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> size(m,vector<int>(n,0));
        for(int i = 0; i < m;i++){
        	size[i][0] = matrix[i][0] - '0';
        	max_size = max(max_size,size[i][0]);
        }
        for(int j =0; j < n; j++){
        	size[0][j] = matrix[0][j] - '0';
        	max_size = max(max_size,size[0][j]);
        }
        for(int i = 1 ; i < m; i++){
        	for(int j =1 ; j < n;j++){
        		if(matrix[i][j] == '1'){
        			size[i][j] = min(min(size[i-1][j-1],size[i][j-1]),size[i-1][j]) + 1;
        			max_size = max(size[i][j],max_size);
        		}
        	}
        }
        return max_size*max_size;
    }
};