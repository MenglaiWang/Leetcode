class Solution {
public:
    string simplifyPath(string path) {
        string result,temp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,temp,'/')){
        	if(temp == "" || temp == ".") continue;
        	if(temp == ".." && stk.size()) stk.pop_back();
        	else{
        		if(temp != "..")
        			stk.push_back(temp);
        	}
        }
        for(auto s : stk)
        	result += "/" + s;
        return result.empty() ? "/":result;
    }
};