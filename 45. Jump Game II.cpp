class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0;
        int result = 0;
        while(i < nums.size()-1){
        	int k = nums[i];
        	if(k==0) return -1;
        	if(i+k >=nums.size()-1) return ++result;
        	int index = i + k;
        	int max_jump = k + nums[i+k];
        	for(int j  = 1 ; j < k;j++){
        		if(j+nums[i+j] > max_jump){
        			max_jump = j + nums[i+j];
        			index = i+j;
        		}
        	}
        	i = index;
        	result++;
        }
        return result;
    }
};
