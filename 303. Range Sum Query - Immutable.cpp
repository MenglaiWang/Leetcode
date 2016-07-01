class NumArray {
public:
    NumArray(vector<int> &nums) {
    	numarray.resize(nums.size());
    	if(nums.empty()) return;
    	numarray[0]=nums[0];
    	for(int i =1 ; i<nums.size();i++){
    		numarray[i] = numarray[i-1]+nums[i];
    	}
    }

    int sumRange(int i, int j) {
        return numarray[j]-numarray[i-1]; 
    }
private:
	vector<int> numarray;
};



// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);