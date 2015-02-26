#include<stdlib.h>
#include<iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
    	if (head == NULL) return NULL;
    	else if (head->next == NULL) return head;
    
    	ListNode *sortedHead = head;
    	ListNode *sortedTail = head;
    	ListNode *insertNode = head->next;
    	ListNode *tmpHead = NULL;
    	if (insertNode != NULL) tmpHead = insertNode->next;
    	while (insertNode != NULL) {
    		if (insertNode->val >= sortedHead->val) {
    			sortedHead->next = insertNode;
    			sortedHead = insertNode;
    		} else if (insertNode->val <= sortedTail->val){
    			insertNode->next = sortedTail;
    			sortedTail = insertNode;
    		} else if (insertNode->val <= sortedTail->next->val) {
    			insertNode->next = sortedTail->next;
    			sortedTail->next = insertNode;
    		} else {
    			ListNode *tmpNode = sortedTail;
    			while (tmpNode->next->val < insertNode->val) {
    				tmpNode = tmpNode->next;
    			}
    			insertNode->next = tmpNode->next;
    			tmpNode->next = insertNode;
    		}
    		insertNode = tmpHead;
    		if (tmpHead != NULL) tmpHead = tmpHead->next;
    	}
    	sortedHead->next = NULL;
    	return sortedTail;
    }
};

int main(int argc, char **argv) {
	ListNode *node_1 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *node_2 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *node_3 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *node_4 = (ListNode *)malloc(sizeof(ListNode));
	node_1->val = 3; node_2->val = 2; node_3->val = 4; //node_4->val = 2;
	node_1->next = node_2;
	node_2->next = node_3;
	node_3->next = NULL;
	node_4->next = NULL;
	Solution solution;
	ListNode *sortedList = solution.insertionSortList(node_1);
	ListNode *tmpNode = sortedList;
	while (tmpNode != NULL) {
		cout << tmpNode->val << endl;
		tmpNode = tmpNode->next;
	}
}
