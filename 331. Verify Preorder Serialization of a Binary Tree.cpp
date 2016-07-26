class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        int diff = 1;
        vector<string> pre;
        split(preorder,",",pre);
        for(auto s : pre){
        	--diff;
        	if(diff < 0) return false;
        	if(s != "#") diff+=2;
        }
        return diff==0;
    }
    void split(const string s,const string delim,vector<string>& ret){
    	int last = 0;
    	int index = s.find_first_of(delim,last);
    	while(index != -1){
    		ret.push_back(s.substr(last,index-last));
    		last = index + 1 ;
    		index = s.find_first_of(delim,last);
    	}
    	if(last < s.size())
    		ret.push_back(s.substr(last));
    }
};


//方法二：stack
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        preorder.push_back(',');
        bool is_num = false;
        for(auto c : preorder){
            if(c == '#'){
                while(stk.size() && stk.top() == '#'){
                    stk.pop();
                    if(stk.empty() || stk.top() == '#') return false;
                    stk.pop();
                }
                stk.push('#');
            } else if( c == ','){
                if(is_num) stk.push('n');
                is_num = false;
            } else{
                is_num = true;
            }
        }
        return stk.size()==1 && stk.top() == '#';
    }
};