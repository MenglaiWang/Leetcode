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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=0,rh=0;
        for(TreeNode* l = root;l != NULL; l = l->left)
        	lh++;
        for(TreeNode* r = root;r != NULL; r = r->right)
        	rh++;
        if(lh == rh) return (1<<lh) -1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};