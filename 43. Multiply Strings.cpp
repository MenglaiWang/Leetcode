//下面方法太复杂
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "-1";
        if(num1 == "0" || num2 == "0") return "0";
        string result;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.size();i++){
        	string str(i,0);
        	int cur = num1[i] - '0';
        	int carry =0;
        	for(int j = 0; j < num2.size();j++){
        		int cur2 = (cur*(num2[j]-'0') + carry)%10;
        		carry = (cur*(num2[j]-'0') + carry) / 10;
        		str.push_back(cur2 + '0');
        	}
        	if(carry > 0) str.push_back(carry + '0');
        	result = add(result,str);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string add(string str1,string str2){
    	int carry = 0;
    	int i =0;
    	string result;
    	while(i < str1.size() && i < str2.size()){
    		int cur = (str1[i] + str2[i] - '0' + carry) %10;
    		carry = (str1[i] + str2[i] - '0' + carry) /10;
    		result.push_back(cur + '0');
    	}
    	while(i < str1.size()){
    		int cur = (str1[i] - '0' + carry) %10;
    		carry = (str1[i] - '0' + carry) /10;
    	}
    	while(i < str2.size()){
    		int cur = (str2[i] - '0' + carry) %10;
    		carry = (str2[i] - '0' + carry) /10;
    	}
    	if(carry > 0) result.push_back(carry + '0');
    	return result;
    }
};


//简化版直接计算
class Solution {
public:
    string multiply(string num1, string num2) {
		string result(num1.size() + num2.size() ,'0');
		for(int i= num1.size()-1; i >=0;i--){
			int carry = 0;
			for(int j = num2.size()-1;j >=0;j--){
				int temp = (result[i+j+1] - '0') + (num1[i]-'0')*(num2[j] - '0') + carry;
				result[i+j+1] = temp%10 + '0';
				carry = temp /10;
			}
			result[i] += carry;
		}
		int start_pos = result.find_first_not_of('0');
		if (string::npos != start_pos) {
        	return result.substr(start_pos);
    	}
    	return "0";
    }
};

//最简单的方法
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> pos(m+n);
        for(int i = m-1; i >=0; i--){
            for(int j = n-1; j >=0;j--){
                int mul = (num1[i] -'0')*(num2[j]- '0');
                int sum = pos[i+j+1] + mul;
                pos[i+j] += sum/10;
                pos[i+j+1] = sum%10; 
            }
        }
        string result;
        for(auto p : pos){
            if(!(result.empty() && p==0)) result.push_back(p + '0');
        }
        return result.empty()?"0":result;
    }
};