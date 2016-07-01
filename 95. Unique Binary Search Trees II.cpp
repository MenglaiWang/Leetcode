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
    vector<TreeNode*> generateTrees(int n) {
        if(n <=0) return vector<TreeNode*>();
        return generateSubTrees(1,n);
    }
    vector<TreeNode*>generateSubTrees(int s,int e){
    	vector<TreeNode*> res;
    	if(s > e){
    		res.push_back(NULL);
    		return res;
    	}
    	for(int i = s; i <= e;i++ ){
    		vector<TreeNode*> left = generateSubTrees(s,i-1);
    		vector<TreeNode*> right = generateSubTrees(i+1,e);

    		for(auto l : left){
    			for(auto r : right){
    				TreeNode* root = new TreeNode(i);
    				root->left = l;
    				root->right = r;
    				res.push_back(root);
    			}
    		}
    	}
    	return res;
    }
};