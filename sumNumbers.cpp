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
	void helper(TreeNode* root,int &result,int cur){
		if(!root) return;
		cur = cur*10 + root->val;
		if(root->left==NULL&&root->right==NULL){
			result += cur;
		}
		if(root->left) helper(root->left,result,cur);
		if(root->right) helper(root->right,result,cur);
	}
    int sumNumbers(TreeNode* root) {
       if(!root) return 0;
       int result = 0;
       int cur = 0;
       helper(root,result,cur);
       return result;
   }
};