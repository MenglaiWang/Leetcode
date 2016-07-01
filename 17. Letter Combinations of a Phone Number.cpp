class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        vector<string> maps = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
        for(int i = 0 ; i < digits.size();i++){
        	vector<string> temp;
        	string str = maps[digits[i] - '0'];
        	for(int j = 0 ; j < str.size();j++){
        		for(int k = 0; k < result.size();k++){
        			temp.push_back(result[k] + str[j]);
        		}
        	}
        	result = temp;
        }
        return result;
    }
};