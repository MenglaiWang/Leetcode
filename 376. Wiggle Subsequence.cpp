class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <2) return nums.size();
        int i = 1;
        int result = 1;
        while(i < nums.size() && nums[i] == nums[i-1]) i++;
        bool increase = nums[i] > nums[i-1];
        while(i < nums.size()){
        	if(increase){
        		while(i+1 < nums.size() && nums[i+1] >= nums[i]) i++; 
        	}
        	else{
        		while(i+1 < nums.size() && nums[i+1] <= nums[i]) i++;
        	}
        	increase = !increase;
        	result++;
        	i++;
        }
        return result;
    }
};