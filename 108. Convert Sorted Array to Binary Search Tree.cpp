/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* helper(vector<int>& nums,int start,int end){
		int mid = (start + end)/2;
		if(start > end) return NULL;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums,start,mid-1);
		root->right = helper(nums,mid+1,end);
		return root;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int size = nums.size();
        return helper(nums,0,size-1);
    }
};