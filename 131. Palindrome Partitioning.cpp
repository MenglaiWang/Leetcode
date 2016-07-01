class Solution {
public:
	bool isPalindrome(string s,int start,int end){
		while(start <= end){
			if(s[start++]!= s[end--])
				return false;
		}
		return true;
	}
	void helper(string s,vector<string>& cur,vector<vector<string>>& result,int index){
		if(index == s.size()){
			result.push_back(cur);
			return;
		}
		for(int i = index; i < s.size();i++){
			if(isPalindrome(s,index,i)){
				cur.push_back(s.substr(index,i-index+1));
				helper(s,cur,result,i+1);
				cur.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.empty()) return result;
        vector<string> cur;
        helper(s,cur,result,0);
        return result;
    }
};