class Solution {
public:
    Solution(vector<int> nums) {
        num = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(num);
        for(int j = result.size(); j > 0; j--){
        	int i = rand()%j;
        	swap(result[i],result[j-1]);
        }
        return result;
    }
private:
	vector<int> num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */