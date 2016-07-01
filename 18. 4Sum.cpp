class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
        if(nums.size() <4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i++){
        	int target1 = target - nums[i];
        	for(int j = i+1;j < nums.size();j++){
        		int target2 = target1 - nums[j];
        		int l = j+1, r= nums.size()-1;
        		while(l < r){
        			int sum = nums[l] + nums[r];
        			if(sum < target2)
        				l++;
        			else if (sum > target2)
        				r--;
        			else {
        				vector<int> res(4);
        				res[0] = nums[i];
        				res[1] = nums[j];
        				res[2] = nums[l];
        				res[3] = nums[r];
        				result.push_back(res);
        				while(l < r && nums[l] == res[2]) l++;
        				while(l < r && nums[r] == res[3]) r--;
        			}
        		}
        		while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
        	}
        	while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};