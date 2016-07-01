/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //两个队列实现
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        deque<TreeNode*> cur,next;
        cur.push_back(root);
        bool flag = true;
        while(cur.size()){
        	vector<int> res;
        	while(cur.size()){
        		TreeNode* temp = cur.front();
        		cur.pop_front();
        		res.push_back(temp->val);
        		if(temp->left) next.push_back(temp->left);
        		if(temp->right) next.push_back(temp->right);
        	}
        	if(!flag) reverse(res.begin(), res.end());
        	result.push_back(res);
        	flag = !flag;
        	swap(cur,next);
        }
        return result;
    }
};


//一个队列实现
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> result;
    	if(!root) return result;
    	deque<TreeNode*> q;
    	q.push_back(root);
    	bool flag = true;
    	while(q.size()) {
    		vector<int> res;
    		int size = q.size();
    		for(int i = 0; i < size;i++){
    			TreeNode* temp = q.front();
    			q.pop_front();
    			res.push_back(temp->val);
    			if(temp->left) q.push_back(temp->left);
    			if(temp->right) q.push_back(temp->right);
    		}
    		if(!flag) reverse(res.begin(), res.end());
        	result.push_back(res);
        	flag = !flag;
    	}
    	return result; 
    }
};