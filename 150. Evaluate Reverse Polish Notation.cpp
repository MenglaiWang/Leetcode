class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	if(tokens.size() <= 0) return -1;
        stack<int> s;
        int result = 0;
        for(int i =0 ; i < tokens.size(); i++){
        	if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        		s.push(string2int(tokens[i]));
        	else{
        		int num2 = s.top();
        		s.pop();
        		int num1 = s.top();
        		s.pop();
        		if(tokens[i] =="+")
        			s.push(num1 + num2);
        		if(tokens[i] == "-")
        			s.push(num1 - num2);
        		if(tokens[i] == "*")
        			s.push(num1 * num2);
        		if(tokens[i] == "/")
        			s.push(num1/num2);
        	}
        }
        result = s.top();
        return result;
    }
    int string2int(string str){
    	int result = 0;
    	int flag = 1;
    	int pos =0;
    	if(str[pos] == '-') {
    		flag = -1;
    		pos++;
    	}
    	if(str[pos] == '+') {
    		flag = 1;
    		pos++;
    	}
    	for(int i = pos; i < str.size();i++){
    		result = result*10 + str[i] - '0';
    	}
    	return result*flag;
    }	
};