class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};
//回溯法
class Solution {
public:
	void genSubsets(vector<int>& S,int start,vector<vector<int>>& result,vector<int>& cur){
		result.push_back(cur);
		for(int i = start;i < S.size();i++){
			cur.push_back(S[i]);
			genSubsets(S,i+1,result,cur);
			cur.pop_back();
		}
	}
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        vector<vector<int>>result;
        vector<int> cur;
        genSubsets(S,0,result,cur);
        return result;
    }
};
