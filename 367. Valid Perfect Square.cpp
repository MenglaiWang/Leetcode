class Solution {
public:
    bool isPerfectSquare(int num) {
    	if(num < 1) return false;
        int left = 1, right = num;
        while(left <= right){
        	long mid = (left + right)/2;
        	long t = mid*mid;
        	if(t > num)
        		right = mid-1;
        	else if(t < num)
        		left = mid+1;
        	else return true;
        }
        return false;
    }
};

//Newton 
class Solution {
public:
    bool isPerfectSquare(int num) {
    	if(num < 1) return false;
    	if(num == 1) return true;
        long t = num/2;
        while(t*t > num){
        	t = (t + num/t)/2;
        }
        return t*t == num;
    }
};