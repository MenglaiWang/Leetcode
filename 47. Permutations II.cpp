class Solution {
public:
	void permutation(vector<vector<int>>& result, vector<int> nums,int begin) {
		if(begin >=nums.size())
			result.push_back(nums);
		for(int i = begin;i < nums.size();i++){
			if(i!=begin && nums[i] == nums[begin]) continue;
			swap(nums[i],nums[begin]);
			permutation(result,nums,begin+1);
			//swap(nums[i],nums[begin]);   //这个swap不能要，如果有，会有重复
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        permutation(result,nums,0);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        vector<int> next_permute(nums);
        while(1){
        	result.push_back(next_permute);
        	next_permutation(next_permute.begin(), next_permute.end());
        	if(next_permute == nums)
        		break;
        }
        return result;
    }
};