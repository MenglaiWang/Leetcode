class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> >nums(m,vector<int>(n));
        nums[0][0] = obstacleGrid[0][0] ==1?0:1;
        for(int j = 1; j< n;j++) nums[0][j] = obstacleGrid[0][j]==1?0:nums[0][j-1];
        for(int i = 1;i <m;i++){
        	nums[i][0] = obstacleGrid[i][0]==1?0:nums[i-1][0];
        	for(int j = 1; j<n;j++){
        		nums[i][j] = nums[i-1][j] + nums[i][j-1];
        		if(obstacleGrid[i][j]) nums[i][j] = 0;
        	}
        } 
        return nums[m-1][n-1];
    }
};