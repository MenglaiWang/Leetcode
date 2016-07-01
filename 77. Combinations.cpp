class Solution {
public:
	void combine(vector<vector<int>>& result,vector<int>& cur,int start,int num,int n,int k){
		if(num == k){
			result.push_back(cur);
			return;
		}
		for(int i = start;i < n;i++){
			cur.push_back(i+1);
			combine(result,cur,i+1,num+1,n,k);
			cur.pop_back();
		}
	}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n<k) return result;
        vector<int> cur;
        combine(result,cur,0,0,n,k);
    }
};