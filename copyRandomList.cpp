#include<iostream>
#include<stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 **/
 struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL) return NULL;
    	if (head->next == NULL) {
    		RandomListNode *copy_node = (RandomListNode *)malloc(sizeof(RandomListNode));
    		copy_node->label = head->label;
    		copy_node->next = NULL;
    		if (head->random == NULL) copy_node->random = NULL;
    		else copy_node->random = copy_node;
    		return copy_node;
    	}
    	
        //1. copy list
        RandomListNode *node = head;
        while (node != NULL) {
        	RandomListNode *copy_node = (RandomListNode *)malloc(sizeof(RandomListNode));
        	copy_node->label = node->label;
        	copy_node->next = node->next;
        	node->next = copy_node;
        	node = copy_node->next;
        }
        cout << "copy list ok" << endl;
        //2. copy random
        node = head;
        RandomListNode *node_next = head->next;
        while (node != NULL) {
        	if (node->random != NULL)node_next->random = node->random->next;
        	else node_next->random = NULL;
        	node = node_next->next;
        	if (node != NULL) node_next = node->next;
        }
        cout << "copy random ok" << endl;
               
        //3. split the list
        node = head->next;
        RandomListNode *node_1 = head;
        RandomListNode *node_2;
        RandomListNode *head_r = head->next;
		while (node != NULL && node->next != NULL) {
			node_2 = node->next;
			node->next = node->next->next;
			node_1->next = node_2;
			node = node->next;
			node_1 = node_2;
			node_2 = node->next;
		}   
		node_1->next = NULL;
		return head_r;     
    }
};

RandomListNode *init() {
	RandomListNode *node1 = (RandomListNode *)malloc(sizeof(RandomListNode));
	RandomListNode *node2 = (RandomListNode *)malloc(sizeof(RandomListNode));
	RandomListNode *node3 = (RandomListNode *)malloc(sizeof(RandomListNode));
	RandomListNode *node4 = (RandomListNode *)malloc(sizeof(RandomListNode));
	RandomListNode *node5 = (RandomListNode *)malloc(sizeof(RandomListNode));
	node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5; node5->next = NULL;
	node1->label = 1; node2->label = 2; node3->label = 3; node4->label = 4; node5->label = 5;
	node1->random = node4; node2->random = node3; node3->random = node1; node4->random = node1; node5->random = node5;
	return node1;
}

RandomListNode *init2() {
	RandomListNode *node1 = (RandomListNode *)malloc(sizeof(RandomListNode));
//	RandomListNode *node2 = (RandomListNode *)malloc(sizeof(RandomListNode));
	node1->next = NULL; //node2->next = NULL; 
	node1->label = -3; //node2->label = -2; 
	node1->random = node1; //node2->random = NULL;
	return node1;
}

void printList(RandomListNode *head) {
	RandomListNode *node = head;
	while (node != NULL) {
		int random_label = -100;
		if (node->random != NULL) {
			random_label = node->random->label;
		}
		cout << node->label << " " << random_label << endl;
		node = node->next;
	}
}

int main(int argc, char **argv) {
	Solution solution;
	RandomListNode *head = init2();
	printList(head);
	cout << "===========" << endl;
	RandomListNode *copy_head  = solution.copyRandomList(head);
	printList(head);
	cout << "===========" << endl;
	printList(copy_head);
}
