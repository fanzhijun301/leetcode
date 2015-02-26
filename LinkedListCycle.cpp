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
    bool hasCycle(ListNode *head) {
    	if (head == NULL) return false;
    	if (head->next == head) return true;
    	
    	ListNode *slowNode = head;
    	ListNode *quickNode = head->next;
    	
    	while (true) {
    		if (slowNode == NULL || quickNode == NULL) return false;
    		if (slowNode == quickNode) return true;
    		slowNode = slowNode->next;
    		if (slowNode == NULL || quickNode->next == NULL) return false;
    		quickNode = quickNode->next->next;
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
	node_4->next = node_4;
	
	Solution solution;
	bool is_cycle = solution.hasCycle(node_1);
	cout << is_cycle << endl;
}
