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
	int robber(TreeNode* root,unordered_map<TreeNode*,int> &maps){
		if(!root) return 0;
		auto it = maps.find(root);
		if(it != maps.end()) return maps[root];
		int val = 0;
		if(root->left) val += robber(root->left->left,maps) + robber(root->left->right,maps);
		if(root->right) val += robber(root->right->left,maps) + robber(root->right->right,maps);
		val = max(val+root->val,robber(root->left,maps)+robber(root->right,maps));
		maps[root]= val;
		return val;
	}
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> maps;
        return robber(root,maps);
    }
};



class Solution {
public:
	vector<int> robber(TreeNode* root){
		if(!root) return vector<int>(2);
		vector<int> left = robber(root->left);
		vector<int> right = robber(root->right);
		std::vector<int> res(2);
		res[0] = max(left[0],left[1]) + max(right[0],right[1]);
		res[1] = root->val + left[0] + right[0];
		return res;
	}
    int rob(TreeNode* root) {
  		vector<int> res = robber(root);
  		return max(res[0],res[1]);      
    }
};