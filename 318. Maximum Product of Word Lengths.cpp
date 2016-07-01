class Solution {
public:	
    int maxProduct(vector<string>& words) {
        int result = 0;
        if(words.empty()) return result;
        unordered_map<int ,int> maps;
        for(auto word : words){
        	int mask = 0;
        	for(auto c : word)
        		mask |= 1<<(c-'a');   //这句是精华，用比特位指示出现某个字符
        	maps[mask] = max(maps[mask],(int) word.size());        	
        }
        for(auto a : maps)
        	for(auto b : maps){
        		if(!(a.first & b.first))
        			result = max(result, a.second*b.second);
        	}
        return result;
    }
};