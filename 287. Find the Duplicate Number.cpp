class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() <= 1) return -1;
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};


///解法二
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		//二分查找
		int low = 1, high = nums.size() - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			int count = 0;
			for (auto num : nums) {
				if (num <= mid)
					count++;
			}
			if (count <= mid)
				low = mid + 1;
			else high = mid;
		}
		return low;
	}
};