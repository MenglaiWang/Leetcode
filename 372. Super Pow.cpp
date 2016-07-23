class Solution {
public:
	int base = 1337;
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return ( helper(superPow(a,b),10) * helper(a,last_digit) )% base;
    }
    int helper(int a ,int k){
    	a %= base;
    	int result = 1;
    	for (int i = 0; i < k; ++i)
    	{
    		result = (result*a)%base;
    	}
    	return result;
    }
};