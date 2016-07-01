class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return ;
        int k = nums.size()-2;
        while(k>=0){
        	if(nums[k] < nums[k+1])
        		break;
        	k--;
        }
        if(k == -1){
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int l = nums.size()-1;
        while(l > k){
        	if(nums[k] < nums[l])
        		break;
        	l--;
        }
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
};