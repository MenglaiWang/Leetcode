class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int mid = nums[n/2];
        int i =0 , low =0, high = n-1;
        #define A(i) nums[(1+2*(i)) % (n | 1)]
        while(i <= high){
        	if(A(i) > mid){
        		swap(A(i++),A(low++));
        	}
        	else if(A(i) < mid){
        		swap(A(i),A(high--));
        	}
        	else i++;
        }
    }
};