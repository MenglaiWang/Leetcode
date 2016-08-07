class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target+1,0); 
        result[0] = 1; // specially result[0] = 1, the empty combination has sum 0
        for(int i =1 ; i <= target;i++){
        	for(auto num : nums){
        		if(i >= num){
        			result[i] += result[i-num];
        		}
        	}
        }
        return result[target];
    }
};