class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i++){
        	int target = -nums[i];
        	int l = i+1,r = nums.size()-1;
        	while(l < r) {
        		int sum = nums[l] + nums[r];
        		if( sum < target)
        			l++;
        		else if(sum > target)
        			r--;
        		else{
        			vector<int> res(3);
        			res[0] = nums[i];
        			res[1] = nums[l];
        			res[2] = nums[r];
        			result.push_back(res);
        			while(l < r && nums[l] == res[1]) l++;  //用过的数字跳过
        			while(l < r && nums[r] == res[2]) r--; 
        		} 
        	}
        	while(i+1< nums.size() && nums[i] == nums[i+1]) i++; //用过的数字跳过
        }
        return result;
    }
};