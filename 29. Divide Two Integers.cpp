class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = (dividend<0) ^ (divisor <0)? -1:1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int result = 0;
        while(dvd >= dvs){
        	long long temp = dvs,multi = 1;
        	while(dvd >=(temp << 1)){
        		temp <<= 1;
        		multi <<= 1;
        	}
        	dvd -= temp;
        	result += multi;
        }
        return sign == 1?result:-result;
    }
};