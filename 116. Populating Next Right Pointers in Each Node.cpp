/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

//用两个队列实现，使用了log(N)空间，与题目不符，可以使用O(1)空间
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        deque<TreeLinkNode*> cur;
        deque<TreeLinkNode*> next;
        cur.push_back(root);
        while(cur.size()){
        	TreeLinkNode* next_node =NULL;
        	while(cur.size()){
        		TreeLinkNode* temp = cur.front();
        		cur.pop_front();
        		temp->next = next_node;
        		next_node = temp;
        		if(temp->right) next.push_back(temp->right);
        		if(temp->left) next.push_back(temp->left);
        	}
        	swap(cur,next);
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL) return;
	    TreeLinkNode *pre = root;
	    TreeLinkNode *cur = NULL;
	    while(pre->left) {
	        cur = pre;
	        while(cur) {
	            cur->left->next = cur->right;
	            if(cur->next) cur->right->next = cur->next->left;
	            cur = cur->next;
	        }
	        pre = pre->left;
	    }
    }
};