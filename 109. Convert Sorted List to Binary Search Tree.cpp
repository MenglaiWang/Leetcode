/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* helper(ListNode*head,ListNode* tail){
		ListNode* slow = head,*fast = head;
		if(head == tail) return NULL;
		if(head->next == tail){
			return new TreeNode(head->val);
		}
		while(fast != tail && fast->next != tail){
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* result = new TreeNode(slow->val);
		result->left = helper(head,slow);
		result->right = helper(slow->next,tail);
		return result;
	}
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return helper(head,NULL);
    }
};