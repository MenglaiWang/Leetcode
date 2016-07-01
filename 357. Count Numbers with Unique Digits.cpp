class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n==1) return 10;
        n = min(n,10); 	//if n > 10, there can't be any number has unique digits
        int sum = 10,temp = 9;
        for(int i = 1; i < n;i++){
        	temp *= (10-i);
        	sum += temp;
        }
        return sum;
    }
};