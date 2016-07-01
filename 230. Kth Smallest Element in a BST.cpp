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
	void inOrder(TreeNode* root,vector<int>& inorder){
		if(root){
			inOrder(root->left,inorder);
			inorder.push_back(root->val);
			inOrder(root->right,inorder);
		}
	}
    int kthSmallest(TreeNode* root, int k) {
    	vector<int> inorder;
        inOrder(root,inorder);
        return inorder[k-1];
    }
};