#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

        int list_len = 0;
		ListNode *pre_tail = NULL, *tmp_node, *headA, *headB, *node_p;
		for (node_p = head; node_p != NULL; node_p = node_p->next){list_len++;}
		for (int sort_len = 2; sort_len <= list_len * 2; sort_len *=2) {
			int step_count = 1;
			pre_tail = NULL;
			node_p = head;
			while (node_p != NULL) {
				if (step_count == 1) {
					headA = node_p;
					node_p = node_p->next; 
					step_count++;
					if (sort_len == 2) {
						headA->next = NULL;
						headB = node_p;
					}
				} else if (step_count == sort_len / 2) {
					tmp_node = node_p;
					node_p = node_p->next;
					tmp_node->next = NULL;
					step_count++;
					headB = node_p;
					if (node_p == NULL) step_count = 1;
				} else if (step_count == sort_len) {
					tmp_node = node_p;
					node_p = node_p->next;
					tmp_node->next = NULL;
					step_count++;
					ListNode *merge_tail;
					ListNode *merge_head = mergeList(headA, headB, merge_tail);
					if (pre_tail == NULL) head = merge_head;
					else pre_tail->next = merge_head;
					merge_tail->next = node_p;
					pre_tail = merge_tail;
					step_count = 1;
				} else {
					node_p = node_p->next;
					step_count++;
				}
			}
			if (step_count > sort_len / 2 && headA != NULL && headB != NULL) {
				ListNode *merge_tail;
				ListNode *merge_head = mergeList(headA, headB, merge_tail);
				if (pre_tail == NULL) head = merge_head;
				else pre_tail->next = merge_head;
				merge_tail->next = NULL;
			}
		}
		return head;
    }

	ListNode *mergeList(ListNode *headA, ListNode *headB, ListNode *&merge_tail) {
		ListNode *head, *node_p;
		if (headA->val <= headB->val) {head = headA; headA = headA->next;}
		else {head = headB; headB = headB->next;}
		node_p = head;
		while (headA != NULL && headB != NULL) {
			if (headA->val <= headB->val) {
				node_p->next = headA;
				headA = headA->next;
			} else {
				node_p->next = headB;
				headB = headB->next;
			}
			node_p = node_p->next;
		}
		if (headA != NULL) node_p->next = headA;
		else if (headB != NULL) node_p->next = headB;
		else node_p->next = NULL;
		while (node_p->next != NULL) node_p = node_p->next;
		merge_tail = node_p;
		return head;
	}
};

void sortList_test_case1() {
	ListNode n1(8),n2(2),n3(5),n4(4),n5(7),n6(6),n7(9),n8(3),n9(1),n10(5);
	n1.next = &n2; n2.next = &n3; n3.next=&n4; n4.next=&n5; n5.next=&n6; 
	n6.next=&n7; n7.next=&n8; n8.next=&n9; n9.next = &n10; n6.next=NULL;
	
	ListNode *head = &n1;

	Solution solution;
	ListNode *node_p = solution.sortList(head);
	while (node_p != NULL) {
		cout << node_p->val << endl;
		node_p = node_p->next;
	}
}

int main_sortList(int argc, char **argv) {
	sortList_test_case1();	
	return 0;
}