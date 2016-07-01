class Solution {
public:
	void helper(int k, int n, vector<vector<int>>& result, vector<int>& cur){
		if(cur.size() == k && n ==0){
			result.push_back(cur);
			return ;
		}
		int i;
		if(cur.size() <=0) i =1;
		else i = cur.back()+1;
		for(; i <=9;i++){
			if(n -i < 0) break;
			cur.push_back(i);
			helper(k,n-i,result,cur);
			cur.pop_back();
		}
	}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if(k<=0 || n <=0 || k > n) return result;
        vector<int> cur;
        helper(k,n,result,cur);
        return result;
    }
};