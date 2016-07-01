class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string>> mp;
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> result;
        for(auto m : mp){
            vector<string> cur(m.second.begin(),m.second.end());
            result.push_back(cur);
        }
        return result;
    }
};