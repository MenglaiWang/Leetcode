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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> result;
        if(!root) return result;
        std::vector<string> left,right;
        if(!root->left&&!root->right) result.push_back(to_string(root->val));
        if(root->left) left = binaryTreePaths(root->left);
        if(root->right) right = binaryTreePaths(root->right);
        for(int i = 0;i<left.size();++i){
        	result.push_back(to_string(root->val)+"->"+left[i]);
        }
        for(int i = 0;i<right.size();++i){
        	result.push_back(to_string(root->val)+"->"+right[i]);
        }
        return result;
    }
};