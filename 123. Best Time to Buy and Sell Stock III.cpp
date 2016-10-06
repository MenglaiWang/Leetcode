class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        int KK = 2;
        int res = 0;
        if(prices.size() < 1) return res;
        vector<vector<int> > f(KK+1,vector<int>(prices.size(),0));
        for(int k = 1; k <= KK; k++){
        	int tmpMax = f[k-1][0] - prices[0];
        	for(int ii = 1; ii < prices.size(); ii++){
        		f[k][ii] = max(f[k][ii-1], tmpMax + prices[ii]);
        		tmpMax = max(tmpMax,f[k-1][ii] - prices[ii]);
        		res = max(res,f[k][ii]);
        	}
        }
        return res;
    }
};