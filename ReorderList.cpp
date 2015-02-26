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
    void reorderList(ListNode *head) {
    	if (head == NULL || head->next == NULL) return;
    	
    	stack<ListNode *> list_stack;
    	ListNode *it_list = head;
    	while (it_list != NULL) {
    		list_stack.push(it_list);
    		it_list = it_list->next;
    	}
    	
    	it_list = head;
    	ListNode *top_node = list_stack.top();
    	while (it_list != top_node && it_list->next != top_node) {
    		top_node->next = it_list->next;
    		it_list->next = top_node;
    		list_stack.pop();
    		top_node = list_stack.top();
    		top_node->next = NULL;
    		it_list = it_list->next->next;
    	}
    }
};

int main(int argc, char **argv) {
	ListNode *node_1 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_2 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_3 = (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *node_4 = (ListNode *)calloc(1, sizeof(ListNode));
	
	node_1->val = 1; node_2->val = 2; node_3->val = 3; node_4->val = 4;
	
	node_1->next = node_2; node_2->next = node_3; //node_3->next = node_4;
	node_3->next = NULL;
	node_4->next = NULL;
	
	Solution solution;
	solution.reorderList(node_1);
	ListNode *p = node_1;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
}
