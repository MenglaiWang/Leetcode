/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //算法一，逐个合并链表
class Solution {
public:
	ListNode* merge2Lists(ListNode* l1,ListNode* l2) {
		ListNode dummy(-1);
		ListNode* l3 = &dummy;
		while(l1 && l2) {
			if(l1->val < l2->val){
				l3->next = l1;
				l1 = l1->next;
			} else {
				l3->next = l2;
				l2 = l2->next; 
			}
			l3 = l3->next;
		}
		l3->next = l1?l1:l2;
		return dummy.next;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty()) return NULL;
    	ListNode* res = lists[0];
    	for(int i = 1; i < lists.size();i++)
    		res	= merge2Lists(res,lists[i]);
    	return res;
    }
};


//算法二，两两合并链表，归并算法，递归
class Solution {
public:
	ListNode* helper(vector<ListNode*>& lists,int l,int r){
		if(l >=r) return lists[l];
		int mid = (l+r)/2;
		return merge2Lists(helper(lists,l,mid),helper(lists,mid+1,r));
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty()) return NULL;
    	return helper(lists,0,lists.size()-1);
    }
};


//算法二，两两合并链表，归并算法，非递归
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty()) return NULL;
    	int n = lists.size();
    	while(n > 1) {
    		int k = (1+n)/2;
    		for(int i = 0; i < n/2;i++){
    			lists[i] = merge2Lists(lists[i],lists[i+k]);
    		}
    		n = k;
    	}
    	return lists[0];
    }
};


//算法三，利用堆或者优先队列实现
class Solution {
public:
	struct cmp
	{
		bool operator()(const ListNode* a,const ListNode* b){
			return a->val > b->val;
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty()) return NULL;
    	priority_queue<ListNode*,vector<ListNode*>,cmp>q;
    	ListNode dummy(-1);
    	ListNode* res = &dummy;
    	for(auto list : lists)
    		if(list) q.push(list);
    	while(q.size()) {
    		ListNode* temp = q.top();
    		q.pop();
    		res->next = temp;
    		res = temp;
    		if(temp->next) q.push(temp->next);
    	}
    	return dummy.next;
    }
};