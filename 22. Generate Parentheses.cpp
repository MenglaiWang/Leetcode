class Solution {
public:
	void helper(vector<string>& result,string str,int open,int close,int max){
		if(open==max && close ==max){
			result.push_back(str);
		}
		if(open < max) helper(result,str+"(",open+1,close,max);
		if(close < open) helper(result,str+")",open,close+1,max);
	}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n<=0) return result;
        helper(result,"",0,0,n);
        return result;
    }
};