class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> result;
        int factorial = 1;
        for(int i = 1; i <= n;i ++){
        	result.push_back(i);
        	factorial *= i;
        }
        k = k%factorial == 0 ?factorial:k%factorial;
        for(int i = 2; i<= k;i++){
        	next_permulation(result);
        }
        string res;
        for(auto r : result)
        	res += to_string(r);
        return res;
    }
    void next_permulation(vector<int>& nums){
    	int k = nums.size()-2;
    	while(k>=0){
    		if(nums[k] < nums[k+1])
    			break;
    		k--;
    	}
    	if(k ==-1){
    		reverse(nums.begin(), nums.end());
    		return;
    	}
    	int l = nums.size()-1;
    	while(l > k) {
    	    if(nums[k] < nums[l])
    	    	break;
    	    l--;
    	}
    	swap(nums[k],nums[l]);
    	reverse(nums.begin()+k+1,nums.end());
    	return;
    }
};


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int>	factorial(n+1,1);
        string result;
        for(int i =1; i<=n;i++){
        	factorial[i] = factorial[i-1]*i;
        	nums.push_back(i);
        }
        k--;
        for(int i = 1;i <=n;i++){
        	int index = k/factorial[n-i];
        	result.push_back(nums[index] + '0');
        	nums.erase(nums.begin()+index);
        	k-=index*factorial[n-i];
        }
        return result;
    }
};