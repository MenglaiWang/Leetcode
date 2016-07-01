/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head){
		ListNode* pre =NULL;
		while(head){
			ListNode* next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* slow = head,*fast = head;
        while(fast&&fast->next){
        	slow = slow->next;
        	fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        ListNode* p1 =head;
        while(slow->next){
        	ListNode* p2 =slow->next;
        	slow->next = p2->next;
        	p2->next = p1->next;
        	p1->next = p2;
        	p1 = p2->next;
        }
    }
};