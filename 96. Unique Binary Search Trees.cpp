class Solution {
public:
    int numTrees(int n) {
        if(n <= 0) return 0;
        vector<int> nums(n+1,0);
        nums[0] = 1;
        for(int i = 1; i<=n; i++){
        	for(int j = 1; j <=i ; j++){
        		nums[i] += nums[j-1]*nums[i-j];
        	}
        }
        return nums[n];
    }
};