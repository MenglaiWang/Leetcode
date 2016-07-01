class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int nMinusone = 2;
        int nMinustwo = 1;
        int result;
        for(int i =3; i <=n;i++){
        	result = nMinusone + nMinustwo;
        	nMinustwo  = nMinusone; 
        	nMinusone = result;
        }
        return result;
    }
};