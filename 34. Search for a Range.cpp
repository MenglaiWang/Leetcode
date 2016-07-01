class Solution {
public:
	int findFirstK(vector<int>& nums,int target){
		int start = 0, end = nums.size()-1;
		while(start <= end){
			int mid = (start + end)/2;
			if(nums[mid] < target)
				start = mid+1;
			else if(nums[mid] > target)
				end = mid-1;
			else{
				if(mid > 0 && nums[mid-1] == nums[mid])
					end = mid-1;
				else return mid;
			}
		}
		return -1;
	}
	int findLastK(vector<int>& nums,int target){
		int start = 0, end = nums.size()-1;
		while(start <= end){
			int mid = (start + end)/2;
			if(nums[mid] < target)
				start = mid+1;
			else if(nums[mid] > target)
				end = mid-1;
			else{
				if(mid < nums.size()-1 && nums[mid] == nums[mid+1])
					start = mid+1;
				else return mid;
			}
		}
		return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result(2,-1);
        if(nums.empty()) return result;
        result[0] = findFirstK(nums,target);
        result[1] = findLastK(nums,target);
        return result;
    }
};