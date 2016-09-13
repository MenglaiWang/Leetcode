class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i =0 ,j =0;
        while(i <m && j < n){
        	if(t[j] == s[i]){
        		i++;
        		j++;
        	}else j++;
        }
        if( i == m) return true;
        return false;
    }
};