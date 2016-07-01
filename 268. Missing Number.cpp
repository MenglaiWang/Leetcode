class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int nums_sum = 0;
        for(auto num : nums)
        	nums_sum+=num;
        return sum- nums_sum;
    }
};

//可以用bit位操作
    int missingNumber(vector<int>& nums) {
    	int result = nums.size();
    	int i = 0;
        for(auto num : nums){
        	result ^=num;
        	result ^= i;
        	i++;
        }
        return result;
    }