class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int result = 0;
        for(int i = 0; i< prices.size();){
        	int j = i+1;
        	while(j < prices.size() && prices[j]>=prices[i] ){
        		result = max(result,prices[j] - prices[i]);
        		j++;
        	}
        	i = j;
        }
        return result;
    }
};

//解法二：连续最大数组子段和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int result = 0;
        int curMax = 0;
        for(int i = 1; i< prices.size();i++){
        	curMax += prices[i] - prices[i-1];
        	curMax = max(0,curMax);
        	result = max(result,curMax);
        }
        return result;
    }
};