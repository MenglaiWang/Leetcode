class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size() <10) return result;
        unordered_map<string,int> maps;
        for(int i =0 ; i <= s.size() -10; i++){
        	string str = s.substr(i,10);
        	maps[str]++;
        }
        for(auto it = maps.begin(); it != maps.end();it++){
        	if(it->second >1) result.push_back(it->first);
        }
        return result;
    }
};