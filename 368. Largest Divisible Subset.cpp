class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(),0);
        vector<int> parent(nums.size(),0);
        int cnt = 0;
        int index = 0;
        for(int i = nums.size() -1; i >=0; i--){
        	for(int j = i; j < nums.size();j++){
        		if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1){
        			// if nums[j] mod nums[i] == 0, it means dp[j] can form a larger subset by putting nums[i] into dp[j]
        			dp[i] = dp[j] +1;
        			parent[i] = j; //记录前一个数的索引位置
        			if(dp[i] > cnt){
        				cnt = dp[i];
        				index = i;
        			}
        		}
        	}
        }

        for(int k = 0; k < cnt; k++){
        	result.push_back(nums[index]);
        	index = parent[index];
        }
        return result;
    }
};