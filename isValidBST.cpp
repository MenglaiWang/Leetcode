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
	bool inorder(TreeNode* root, long &pre){
		if (!root) return true;
		bool left = true, right = true;
		if (root->left) left = inorder(root->left, pre);
		if (pre >= root->val) return false;
		pre = root->val;
		if (root->right) right = inorder(root->right, pre);
		return left&&right;
	}
    bool isValidBST(TreeNode* root) {
    	long pre = LONG_MIN;
	    return inorder(root, pre);
    }
};