/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //解法一，层序遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> result;
    	deque<TreeNode*> q;
    	if(!root) return result;
    	q.push_back(root);
    	int count = 0;
    	int to_be_print = 1;
    	while(q.size()){
    		TreeNode* temp = q.front();
    		q.pop_front();
    		to_be_print--;
    		if(temp->left){
    			q.push_back(temp->left);
    			count++;
    		}
    		if(temp->right){
    			q.push_back(temp->right);
    			count++;
    		}
    		if(to_be_print == 0) {
    			result.push_back(temp->val);
    			to_be_print = count;
    			count = 0;
    		}
    	}
    	return result;
    }
};


//解法二，递归
class Solution {
public:
	void helper(TreeNode* root,int level,vector<int>& result) {
		if(!root) return;
		if(result.size() < level) result.push_back(root->val);
		if(root->right) helper(root->right,level+1,result);
		if(root->left) helper(root->left,level+1,result);
	}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root,1,result);
        return result;
    }
};