class Solution {
public:
	int partition(vector<int>& nums,int start,int end){
		int privot = nums[end];
		int index = start;
		int big = start;
		for(;index < end;index++){
			if(nums[index] > privot){
				if(index !=big){
					swap(nums[big],nums[index]);
				}
				big++;
			}
		}
		swap(nums[big],nums[end]);
		return big;
	}
    int findKthLargest(vector<int>& nums, int k) {
    	int start = 0,end = nums.size()-1;
        int loc = partition(nums,start,end);
        while(loc != k-1){
        	if(loc < k -1){
        		start = loc + 1;
        		loc = partition(nums,start,end);
        	}
        	else {
        		end = loc -1;
        		loc = partition(nums,start,end);
        	}
        }
        return nums[k-1];
    }
};