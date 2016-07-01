class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        vector<int> st;
        int num =0;
        char sign = '+';
        for(int i = 0 ;i < s.size();i++){
        	if(s[i]>='0' && s[i] <='9')
        		num = num*10 + s[i]- '0';
        	if(((s[i] > '9' || s[i] < '0') &&s[i] != ' ') || i == s.size()-1){
        		if(sign == '-')
        			st.push_back(-num);
        		if(sign == '+')
        			st.push_back(num);
        		if(sign == '*'){
        			int temp = st.back();
        			st.pop_back();
        			st.push_back(num*temp);
        		}
        		if(sign == '/'){
        			int temp = st.back();
        			st.pop_back();
        			st.push_back(temp/num);
        		}
        		sign = s[i];
        		num = 0;
        	}
        }
       	int result = 0;
       	for(auto ss : st)
       		result += ss;
       	return result;
    }
};