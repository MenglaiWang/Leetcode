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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head) return head;
        int size = 0;
    	ListNode* p1 = head,*p2 =head;
    	while(p2){
    		p2 = p2->next;
    		size++;
    	}
    	p2 =head;
    	if(k%size==0) return head;
    	k = k%size;
        for(int i = 0; i <k;i++){
        	p1 = p1->next;
        }
        while(p1->next){
        	p1= p1->next;
        	p2 =p2->next;
        }
        ListNode* new_head = p2->next;
        p1->next = head;
        p2->next = NULL;
        return new_head;
    }
};