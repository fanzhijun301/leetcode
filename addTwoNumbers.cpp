#include<iostream>
#include<stdlib.h>

using namespace std;
/**
 *  * Definition for singly-linked list.
 **/
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry = 0;
		ListNode *head = NULL, *last_node = NULL;
		bool first = true;
        while (l1 != NULL && l2 != NULL) {
			int val_1 = l1->val;
			int val_2 = l2->val;

			int v = val_1 + val_2 + carry;

			ListNode *node = (ListNode *)calloc(1, sizeof(ListNode));
			if (v < 10) { node->val = v; carry = 0;} 
			else {	node->val = v % 10;	carry = 1;}
			if (first) {
				first = false;
				head = node;
				last_node = node;
			} else {
				last_node->next = node;
				last_node = node;
			}

			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == NULL) {
			while (l2 != NULL) {
				int val_2 = l2->val;
				int v = val_2 + carry;
				ListNode *node = (ListNode *)calloc(1, sizeof(ListNode));
				if (v < 10) {node->val = v; carry = 0;}
				else {node->val = v % 10; carry = 1;}
				last_node->next = node;
				last_node = node;
				l2 = l2->next;
			}
		}
		if (l2 == NULL) {
			while (l1 != NULL) {
				int val_1 = l1->val;
				int v = val_1 + carry;
				ListNode *node = (ListNode *)calloc(1, sizeof(ListNode));
				if (v < 10) {node->val = v; carry = 0;}
				else {node->val = v % 10; carry = 1;}
				last_node->next = node;
				last_node = node;
				l1 = l1->next;
			}
		}
		if (carry == 1) {
			ListNode *node = (ListNode *)calloc(1, sizeof(ListNode));
			node->val = 1;
			last_node->next = node;
			last_node = node;
		}
		last_node->next = NULL;

		return head;
    }
};

int main(int argc, char **argv) {
	Solution solution;
	ListNode *node2 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node4_1 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node3 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node1 = (ListNode *)calloc(1, sizeof(ListNode));

	ListNode *node5 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node6 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node4_2 = (ListNode *)calloc(1, sizeof(ListNode));

	node2->val=2; node4_1->val=4; node3->val=3; node1->val=1;
	node5->val=5; node6->val=6; node4_2->val=4;
	
	node2->next=node4_1; node4_1->next=node3; node3->next=node1; node1->next=NULL;
	node5->next=node6; node6->next=node4_2; node4_2->next=NULL;

	ListNode *result = solution.addTwoNumbers(node2, node5);
	while (result != NULL) {
		int v = result->val;
		cout << v << endl;
		result = result->next;
	}
}

