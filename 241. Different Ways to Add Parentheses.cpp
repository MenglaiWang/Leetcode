//递归版
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if(input.empty()) return result;
        for(int i =0; i< input.size();i++){
        	char temp = input[i];
        	if(temp == '-' || temp == '+' || temp == '*'){
        		vector<int> result1 = diffWaysToCompute(input.substr(0,i));
        		vector<int> result2 = diffWaysToCompute(input.substr(i+1));
        		for(auto res1 : result1){
        			for(auto res2 : result2){
        				if(temp =='-')
        					result.push_back(res1 - res2);
        				if(temp == '+')
        					result.push_back(res1+res2);
        				if(temp == '*')
        					result.push_back(res1*res2);
        			}
        		}
        	}
        }
      	if(result.empty())
      		result.push_back(atoi(input.c_str()));
      	return result;
    }
};



//DP 版本
class Solution {
public:
	vector<int> helper(string& input, unordered_map<string,vector<int>>& dpMap){
		vector<int> result;
		for (int i = 0; i < input.size(); i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = helper(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = helper(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
	}
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string,vector<int>> dpMap;
        return helper(input,dpMap);
    }
};