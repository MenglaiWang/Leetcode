class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        int i = 0;
        int result = 0;
        while(i < nums.size()-1){
        	int k = nums[i];
        	if(k==0) return false;
        	if(i+k >=nums.size()-1) return true;
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
        return true;
    }
};


bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}