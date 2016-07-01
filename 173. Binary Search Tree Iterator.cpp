/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
    	find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* result = st.top();
        st.pop();
        if(result->right)
        	find_left(result->right);
        return result->val;
    }
private:
	void find_left(TreeNode* node) {
		while(node){
			st.push(node);
			node = node->left;
		}
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */