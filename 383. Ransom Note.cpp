class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> table(26,0);
        for(auto c : magazine)
        	table[c-'a']++;
        for(auto c : ransomNote){
        	if(table[c-'a'] <= 0) return false;
        	table[c-'a']--;
        }
        return true;
    }
};