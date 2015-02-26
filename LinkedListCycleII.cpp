#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;

//Definition for singly-linked list.
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if (head == NULL) return NULL;
    	if (head->next == head) return head;
    	
    	ListNode *slowNode = head;
    	ListNode *quickNode = head->next;
    	
    	int slow_steps = 0;
    	while (true) {
    		if (slowNode == NULL || quickNode == NULL) return NULL;
    		if (slowNode == quickNode) break;
    		slowNode = slowNode->next;
    		slow_steps += 1;
    		if (slowNode == NULL || quickNode->next == NULL) return NULL;
    		quickNode = quickNode->next->next;
    	}
    	
    	ListNode *ln_begin = head;
    	int index_begin = 0; index_end = slow_steps;
    	//slowNode is in circle
    	while (true) {
    		# how to select ln_begin?
    		int index_middle = (index_begin + index_end) / 2;
    		ln_begin = head;
    		for (int i = 0; i < index_middle; i++) {
    			ln_begin = ln_bein->next;
    		}
    		
    		int encount_slow = 0;
    		ListNode *it_ln = ln_begin->next;
    		while (encount_slow < 2) {
    			if (it_ln == ln_begin) return ln_begin;
    			if (it_ln == slowNode) encount_slow += 1;
    			it_ln = it_ln->next;
    		}
    	}
    }
};

int main(int argc, char **argv) {
	ListNode *node_1 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_2 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_3 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_4 = (ListNode *)calloc(1, sizeof(ListNode));
	
	node_1->val = 1; node_2->val = 2; node_3->val = 3; node_4->val = 4;
	
	node_1->next = node_2; node_2->next = node_3; node_3->next = node_4;
//	node_3->next = NULL;
	node_4->next = NULL; 
	
	Solution solution;
	ListNode *node = solution.detectCycle(node_1);
	if (node != NULL) cout << node->val << endl;
	else cout << "NULL" << endl;
}
