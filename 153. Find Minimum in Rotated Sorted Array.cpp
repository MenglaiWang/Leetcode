class Solution {
public:
	int minInorder(vector<int>&nums,int i,int j){
		int result = nums[i];
		for(int k = i+1;k<=j;k++)
			result = min(result,nums[k]);
		return result;
	}
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int i = 0, j = nums.size()-1;
        int mid = i;
        while(nums[i] >=nums[j]){
        	mid = (i+j)/2;
        	if(i == j-1) return nums[j];
        	if(nums[mid] == nums[i] && nums[mid] == nums[j]) return minInorder(nums,i,j);
        	if(nums[mid]>=nums[i]) i = mid;
        	else if(nums[mid] <= nums[j]) j = mid;        	 
        }
        return nums[mid];
    }
};