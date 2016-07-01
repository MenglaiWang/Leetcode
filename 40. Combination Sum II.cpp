class Solution {
public:
	void combinations(vector<vector<int>>& result, vector<int>& candidates, vector<int> cur, int target, int begin) {
		if (target == 0) {
			result.push_back(cur);
			return;
		}
		for (int i = begin; i < candidates.size(); i++) {
			if (candidates[i] <= target) {
				if (i == begin || candidates[i] != candidates[i - 1]) {
					cur.push_back(candidates[i]);
					combinations(result, candidates, cur, target - candidates[i], i + 1);
					cur.pop_back();
				}
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.empty() || target <= 0) return result;
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		combinations(result, candidates, cur, target, 0);
		return result;
	}
};