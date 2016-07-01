/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	void cloneNodes(RandomListNode* head) {
		RandomListNode* p = head;
		while(p){
			RandomListNode* temp = new RandomListNode(p->label);
			temp->next = p->next;
			p->next = temp;
			p = temp->next;
		}
	}
	void cloneRandomPointer(RandomListNode* head) {
		RandomListNode *p1 = head,*p2;
		while(p1) {
			p2 = p1->next;
			if(p1->random){
				p2->random = p1->random->next;
			}
			p1 = p2->next;
		}
	}
	RandomListNode* ReconnectRandomList(RandomListNode *head) {
		RandomListNode* p1 = head,*p2;
		RandomListNode* clone_head = p1->next;
		while(p1->next){
			p2 = p1->next;
			p1->next = p2->next;
			p1 = p2;
		}
		return clone_head;
	}
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        cloneNodes(head);
        cloneRandomPointer(head);
        return ReconnectRandomList(head);
    }
};