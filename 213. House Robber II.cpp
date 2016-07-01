class Solution {
public:
	int robber(vector<int> &nums,int l,int r){
		int cur=0,pre=0;
		for(int i=l;i<=r;i++){
			int temp = max(pre + nums[i],cur);
			pre = cur;
			cur = temp;
		}
		return cur;
	}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(robber(nums,0,n-2),robber(nums,1,n-1));
    }
};