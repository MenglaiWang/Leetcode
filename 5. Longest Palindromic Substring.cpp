class Solution {
public:
	string preprocess(string s){
	    string str;
		str.push_back('$');
		str.push_back('#');
		for(auto ss : s){
			str.push_back(ss);
			str.push_back('#');
		}
		str.push_back('^');
		return str;
	}
    string longestPalindrome(string s) {
        if(s.size() <= 1)return s;
        //Manncher算法 ，o（n）
        string str = preprocess(s);
        int n = str.size();
        int mx = 0,id = 0;
        vector<int> p(n,0);
        for(int i = 1; i< n-1;i++){
        	p[i] = mx > i? min(p[2*id-i],mx-i) : 1;
        	while(str[i+p[i]] == str[i-p[i]]) p[i]++;
        	if(i + p[i] > mx){
        		mx = i+p[i];
        		id = i;
        	}
        }
        int maxLen = 0;
        for(int i = 1;i < n-1;i++){
        	if(p[i] > maxLen){
        		maxLen = p[i];
        		id = i;
        	}
        }
        return s.substr((id-maxLen)/2,maxLen-1);
    }
};