#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> maxArray(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> result(k);
        for (int i = 0, j = 0; i < n; i++){
            while (n - i + j>k && j > 0 && result[j-1] < nums[i]) j--;
            if (j < k) result[j++] = nums[i];
        }
        return result;
    }


    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j){
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]){
            i++;
            j++;
        }
        return j == nums2.size() || (i<nums1.size() && nums1[i] > nums2[j]);
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<int> ans(k);
        int i = 0, j = 0;
        for (int r = 0; r<k; r++){
            if( greater(nums1, i, nums2, j) ) ans[r] = nums1[i++] ;
            else ans[r] = nums2[j++];
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result(k);
        for (int i = std::max(0 , k - n); i <= k && i <= m; i++){
            auto v1 = maxArray(nums1, i);
            auto v2 = maxArray(nums2, k - i);
            vector<int> candidate = merge(v1, v2, k);
            if (greater(candidate, 0, result, 0)) result = candidate;
        }
        return result;
    }
};
