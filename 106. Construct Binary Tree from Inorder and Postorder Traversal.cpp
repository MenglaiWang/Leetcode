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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int i, int j,int ii,int jj){
    	if(i > j || ii > jj) return NULL;
    	int root_loc = jj;
    	TreeNode* root = new TreeNode(postorder[jj]);
    	int k= i;
    	for(; k <= j; k++){
    		if(inorder[k] == postorder[jj])
    			break;
    	}
    	root->left = helper(inorder,postorder,i,k-1,ii,ii + k-1-i);
    	root->right = helper(inorder,postorder,k+1,j,ii+k-i,jj-1);
    	return root;
    }
};