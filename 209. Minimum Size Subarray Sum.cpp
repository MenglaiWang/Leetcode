//O(n)算法 O(1)空间
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

//O(NlogN)算法 O(N)空间复杂度
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, min_ = INT_MAX;
        vector<int> sums(nums.size());
        for (int i = 0; i < nums.size(); i++)
            sums[i] = nums[i] + (i == 0 ? 0 : sums[i - 1]);

        for (int i = 0; i < nums.size(); i++) {
            int j = findWindowEnd(i, sums, s);
            if (j == nums.size()) break;
            min_ = min(j - i + 1, min_);
        }

        return min_ == INT_MAX ? 0 : min_;
    }

    int findWindowEnd(int start, vector<int>& sums, int s) {
        int i = start, j = sums.size() - 1, offset = start == 0 ? 0 : sums[start - 1];
        while (i <= j) {
            int m = (i + j) / 2;
            int sum = sums[m] - offset;
        if (sum >= s) j = m - 1;
        else i = m + 1;
    }
    return i;
}
};
