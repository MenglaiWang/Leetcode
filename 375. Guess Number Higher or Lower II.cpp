class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return helper(dp,1,n);
    }
    int helper(vector<vector<int>>& dp,int s,int e){
    	if(s>=e) return 0;
    	if(dp[s][e] != 0) return dp[s][e];
    	int result = INT_MAX;
    	for(int i = s; i <= e;i++){
    		int tmp = i + max(helper(dp,s,i-1),helper(dp,i+1,e));
    		result = min(result,tmp);
    	}
    	dp[s][e] = result;
    	return result;
    }
};


//自顶向下
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int j = 2; j < n+1;j++){
        	for(int i =j -1; i >=0;i--){
        		int globalMin = INT_MAX;
        		for(int k = i+1; k < j; k++){
        			int localMax = k + max(dp[i][k-1],dp[k+1][j]);
        			globalMin = min(globalMin,localMax);
        		}
        		dp[i][j] = i+1 == j?i:globalMin;
        	}
        }
        return dp[1][n];
    }
};