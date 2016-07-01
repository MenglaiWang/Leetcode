class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return -1;
        vector<int> result(n);
        result[0]=1;
        int t2=0,t3=0,t5=0;
        for(int i = 1; i< n;i++){
        	result[i] = min(min(result[t2]*2,result[t3]*3),result[t5]*5);
        	if(result[i]==result[t2]*2) t2++;
        	if(result[i]==result[t3]*3) t3++;
        	if(result[i]==result[t5]*5) t5++;
        }
        return result[n-1];
    }
};