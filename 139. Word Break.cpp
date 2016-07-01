class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size() <= 0) return true;
        for(int i = 1;i <= s.size();i++){
        	if(wordDict.find(s.substr(0,i)) == wordDict.end()) continue;
        	if(wordBreak(s.substr(i),wordDict)) return true;
        }
        return false;
    }
};



//DP
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	if(s.empty()) return false;
        vector<bool> dp(s.size()+1,false);
        dp[0] =true;
        for(int i = 1; i <= s.size();i++){
        	for(int j = i-1; j >=0;j--){
        		if(dp[j]){
        			string str = s.substr(j,i-j);
        			if(wordDict.find(str) != wordDict.end()){
        				dp[i] = true;
        				break;
        			}
        		}
        	}
        }
        return dp[s.size()];
    }
};