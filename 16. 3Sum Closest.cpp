class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return -1;
        int gap = INT_MAX,result = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++){
        	int target1 = target - nums[i];
        	int start = i+1,end = nums.size()-1;
        	while(start < end){
        		int temp = nums[start] + nums[end];
        		if(temp < target1){
        			if(gap > target1-temp){
        				gap = target1-temp;
        				result = temp+nums[i];
        			}
        			start++;
        		}else if(temp > target1){
        			if(gap > temp - target1){
        				gap = temp - target1;
        				result = temp + nums[i]; 
        			}
        			end--;
        		}
        		else return target;
        	}
        }
        return result;
    }
};