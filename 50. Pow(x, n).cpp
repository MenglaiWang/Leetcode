class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)  return 1;
		if (n < 0)   return 1.0 / (myPow(x, -(n + 1)) * x);
		double ret = myPow(x, n / 2);
		return ret * ret * ((n & 1) == 1 ? x : 1);
	}
};