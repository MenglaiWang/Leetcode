// 题目描述

// 对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
// 给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
// 测试样例：
// 1->2->2->1
// 返回：true

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	ListNode* ReverseList(ListNode* head){
		ListNode* pre =NULL;
		ListNode* cur = head;
		while(cur){
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
    bool chkPalindrome(ListNode* head) {
    	if(!head || !head->next) return true;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while(fast->next && fast->next->next){
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	slow->next = ReverseList(slow->next);
    	slow = slow->next;
    	while(slow){
    		if(slow->val != head->val) return false;
    		slow = slow->next;
    		head = head->next;
    	}
    	return true;
    }
};