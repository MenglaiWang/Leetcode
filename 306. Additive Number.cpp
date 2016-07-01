class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size()/2; ++i){
        	for(int j = 1; j <= (num.size()-i)/2;j++){
        		if(check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;
        	}
        }
        return false;
    }
    bool check(string str1,string str2,string str){
    	if(str1.size() > 1 && str1[0] =='0') return false;
    	if(str2.size() > 1 && str2[0] =='0') return false;
    	string sum = add(str1,str2);
    	if(sum.size() > str.size()) return false;
    	if(sum == str) return true;
    	if(sum.size() <= str.size() && sum != str.substr(0,sum.size())) return false;
    	else return check(str2,sum,str.substr(sum.size()));
    }
    string add(string str1,string str2){
    	string result;
    	int i = str1.size()-1,j = str2.size()-1;
    	int carry = 0;
    	while(i>=0 || j >=0){
    		int sum = carry + (i>=0?str1[i--]-'0':0) + (j>=0?str2[j--]-'0':0);
    		result.push_back(sum%10 + '0');
    		carry = sum/10;
    	}
    	if(carry) result.push_back(carry+'0');
    	reverse(result.begin(), result.end());
    	return result;
    }
};