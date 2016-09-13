class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        int i =0;
        string res;
        while(i < s.size()){
        	if(isdigit(s[i])){
        		int count = 0;
        		while(isdigit(s[i])){
        			count = count*10 + s[i]- '0';
        			i++;
        		}
        		counts.push(count);
        	}
        	else if(s[i] == '['){
        		strs.push(res);
        		res = "";
        		i++;
        	}
        	else if(s[i] == ']'){
        		string temp(strs.top());
        		strs.pop();
        		int repeatTimes = counts.top();
        		counts.pop();
        		for(int j = 0; j < repeatTimes;++j){
        			temp += res;
        		}
        		res = temp;
        		i++;
        	}
        	else {
        		res += s[i];
        		i++;
        	}
        }
        return res;
    }
};