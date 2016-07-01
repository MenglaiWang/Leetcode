class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       	if(nums.empty()) return -1;
       	int i = 0;
       	while( i < nums.size()-1){
       		if(nums[i] > nums[i+1])
       			break;
       		i++;
       	}
       	return i;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        int low = 0, high = nums.size()-1;
        while(low < high) {
        	int mid = (low + high)/2;
        	if(nums[mid] < nums[mid+1])
        		low = mid+1;
        	else high = mid;
        }
        return low;
    }
};