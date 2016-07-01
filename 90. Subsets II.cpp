class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result(1,vector<int>());  //初始化包含空集
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();){
        	int count = 0;
        	while(i+count < nums.size() && nums[i] == nums[i+count]) count++;
        	int previousN = result.size();
        	for (int j = 0; j < previousN; ++j){
        		vector<int> instance = result[j];
        		for(int k = 0; k < count;k++){
        			instance.push_back(nums[i]);
        			result.push_back(instance);
        		}
        	}
        	i += count;
        }
        return result;
    }
};

class Solution {
public:
	void helper(vector<vector<int>>& result,vector<int>& nums,vector<int>cur,int begin){
		result.push_back(cur);
		for(int i = begin;i < nums.size();i++){
			if(i == begin || nums[i] != nums[i-1]){
				cur.push_back(nums[i]);
				helper(result,nums,cur,i+1);
				cur.pop_back();
			}
		}
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> cur;
        helper(result,nums,cur,0);
        return result;
    }
};