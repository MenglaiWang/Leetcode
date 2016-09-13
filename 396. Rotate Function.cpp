class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        long max_global,sum=0,max_sofar=0;
        for(int i = 0; i < n; i++){
        	max_sofar += A[i]*i;
        	sum += A[i];
        }
        max_global = max_sofar;
        for(int i = n-1; i > 0; i--){
        	max_sofar = max_sofar + sum - A[i]*n;
        	max_global = max(max_sofar,max_global);
        }
        return max_global;
    }
};