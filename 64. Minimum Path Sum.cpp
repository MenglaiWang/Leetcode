class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[0][1] = 0; dp[1][0] = 0;
        for(int i =1; i<= m;i++){
        	for(int j =1 ; j<= n;j++){
        		dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];  //这里是i-1 ！！！！！
        	}
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};

 class Solution {
 public:
 	int minPathSum(vector<vector<int>>& grid) {
 		int m = grid.size();
 		int n = grid[0].size();
 		vector<int> cur(m,0);
 		cur[0] = grid[0][0];
 		for(int i = 1; i<m;i++)
 			cur[i] = cur[i-1] + grid[i][0]; 
 		for(int j = 1; j < n;j++){
 			cur[0] += grid[0][j];
 			for(int i = 1; i < m; i++){
 				cur[i] = min(cur[i],cur[i-1]) + grid[i][j];
 			}
 		}
 		return cur[m-1];
 	}
 };