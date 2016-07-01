class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>maps;
        for(auto c:s) maps[c]++;
        for(int i = 0; i< t.size();i++){
        	if(maps.find(t[i]) == maps.end()) return false;
        	else maps[t[i]]--;
        	if(maps[t[i]] < 0) return false;
        }
        for(auto it : maps){
        	if(it->second != 0) return false;
        }
        return true;
    }
};