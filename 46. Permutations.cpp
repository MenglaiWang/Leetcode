class Solution {
public:
	void permute_recursive(vector<int> nums, vector<vector<int>>& result, int begin){
		if(begin >= nums.size())
			result.push_back(nums);
		for(int i = begin; i < nums.size(); i++){
			swap(nums[i],nums[begin]);
			permute_recursive(nums,result,begin+1);
		//	swap(nums[i],nums[begin]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        permute_recursive(nums,result,0);
        return result;
    }
};