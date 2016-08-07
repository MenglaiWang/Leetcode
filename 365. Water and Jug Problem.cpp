class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z<0 || z > x + y) return false;
        if(x==z || y== z || x + y ==z) return true;
        int gcd = GCD(x,y);
        return z % gcd == 0;
    }
    int GCD(int x, int y){
    	if(x < y) return GCD(y,x);
    	if(y ==0) return x;
    	if(x%2 ==0 && y%2 ==0) return 2*GCD(x/2,y/2);
    	else if(x%2 == 0) return GCD(x/2,y);
    	else if(y%2 == 0) return GCD(x,y/2);
    	else return GCD(x-y,y);
    }
};