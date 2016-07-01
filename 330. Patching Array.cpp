class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        if(n <=0 ) return 0;
        long miss = 1,i = 0;   //if miss is int , it can overflow
        int result = 0;
        while(miss <= n){
        	if(i < nums.size() && nums[i] <= miss){
        		miss += nums[i++];
        	} else {
        		miss += miss;
        		result++;
        	}
        }
        return result;
    }
};