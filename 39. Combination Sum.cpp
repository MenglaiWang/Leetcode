class Solution {
public:
	void combination(vector<vector<int>>& result,vector<int>& candidates,vector<int> cur,int target,int begin){
		if(target == 0){
			result.push_back(cur);
			return;
		}
		for(int i = begin;i < candidates.size();i++){
			if(candidates[i] <= target){
				cur.push_back(candidates[i]);
				combination(result,candidates,cur,target-candidates[i],i);
				cur.pop_back();
			}
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty() || target <= 0) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        combination(result,candidates,cur,target,0);
        return result;
    }
};