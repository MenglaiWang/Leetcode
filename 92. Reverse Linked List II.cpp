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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        ListNode* p1 = &dummy;
        dummy.next = head;
        for (int i = 1; i < m; i++) {
            p1 = p1->next;
        }
        ListNode* pre = p1;
        ListNode* cur = pre->next;
        for(int i = 0; i<= n-m;i++){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p1->next->next = cur;
        p1->next = pre;
        return dummy.next;
    }
};
