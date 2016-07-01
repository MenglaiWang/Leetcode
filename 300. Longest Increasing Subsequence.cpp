class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int size = nums.size();
    	if(size ==0) return 0;
        vector<int> dp(size,1);
        for(int i = 1; i < size;i++){
        	for(int j = i-1; j >= 0 ;j--){
        		if(nums[i]>nums[j]){
        			dp[i] = max(dp[i],dp[j]+1);
        		}
        	}
        }
        int max_l = dp[0];
        for(auto d : dp)
        	max_l = max(max_l,dp);
        return max_l;
    }
};

int binary_search(vector<int>& result, int start,int end,int target){
	while(start < end-1){
		int mid = (start+end)>>1;
		if(result[mid] >= target) end = mid ;
		else start = mid;
	}
	return end;
}

int lengthOfLIS(vector<int>& nums){
	if(nums.empty()) return 0;
	vector<int> result;
	result.push_back(nums[0]);
	for(int i = 1; i < nums.size();i++){
		if(nums[i] < result[0]) result[0] = nums[i];
		else if(nums[i] > result.back()) result.push_back(nums[i]);
		else{
			int index = binary_search(result,0,result.size()-1,nums[i]);
			result[index] = nums[i];
		}		
	}
	return result.size();
}