class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> maps;
        for(auto c : s)
        	maps[c]++;
        for(int i = 0; i < s.size();i++){
        	if(maps[s[i]]==1)
        		return i;
        }
        return -1;
    }
};